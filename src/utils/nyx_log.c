/* @@@LICENSE
*
*      Copyright (c) 2010-2013 LG Electronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

/**
 *******************************************************************************
 * @file nyx_log.c
 *
 * @brief definition of NYX's internal logging
 *
 *******************************************************************************
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <syslog.h>

#include <glib.h>

#include <nyx/nyx_client.h>
#include <nyx/nyx_module.h>

/* By default, nyx log messages with levels Warning,Critical or Error
 * are logged to destination syslog.
 */
static nyx_log_level_t nyx_log_level = NYX_LOG_WARNING;
static bool use_colors = true;
static const char *_logged_file;
static int32_t _logged_line;

struct log_level_mapping
{
	int32_t syslog_level;
	GLogLevelFlags glib_level;
	const char *name_level;
};

static struct log_level_mapping level_map[] =
{
	[NYX_LOG_NONE]     = { 0, 0, "" },
	[NYX_LOG_ERROR]    = { LOG_ERR, G_LOG_LEVEL_CRITICAL, "Error" },
	[NYX_LOG_CRITICAL] = { LOG_CRIT, G_LOG_LEVEL_CRITICAL, "Critical" },
	[NYX_LOG_WARNING]  = { LOG_WARNING, G_LOG_LEVEL_WARNING, "Warning" },
	[NYX_LOG_MESSAGE]  = { LOG_NOTICE, G_LOG_LEVEL_MESSAGE, "Message" },
	[NYX_LOG_INFO]     = { LOG_INFO, G_LOG_LEVEL_INFO, "Info" },
	[NYX_LOG_DEBUG]    = { LOG_DEBUG, G_LOG_LEVEL_DEBUG, "Debug" },
};


#define COLOR_NORMAL "\033[0m"
static const char *color_escape[] =
{
	"\033[m",        /* NYX_LOG_NONE */
	"\033[1;31m",    /* NYX_LOG_ERROR (red) */
	"\033[1;33m",    /* NYX_LOG_CRITICAL (yellow) */
	"\033[1;35m",    /* NYX_LOG_WARNING (magenta)*/
	"\033[1;32m",    /* NYX_LOG_MESSAGE (green)*/
	"\033[1;34m",    /* NYX_LOG_INFO (blue)*/
	"\033[1m",       /* NYX_LOG_DEBUG (bold) */
};

/* Forward reference */
static int32_t print_error_wrapper(const char *msg, ...);


int32_t _nyx_log_console_printer(nyx_log_level_t level, const char *msg,
                                 va_list args)
{
	const char *level_name = level_map[level].name_level;
	int32_t printed;

	if (use_colors)
		printed = fprintf(stderr, "%s" NYX_LOG_DOMAIN ":%s:%s:%d: ",
		                  color_escape[level], level_name, _logged_file, _logged_line);
	else
		printed = fprintf(stderr, NYX_LOG_DOMAIN ":%s:%s:%d: ",
		                  level_name, _logged_file, _logged_line);

	printed += vfprintf(stderr, msg, args);

	if (use_colors)
	{
		fputs(COLOR_NORMAL "\n", stderr);
	}
	else
	{
		fputs("\n", stderr);
	}

	return printed;
}

int32_t _nyx_log_syslog_printer(nyx_log_level_t level, const char *msg,
                                va_list args)
{
	int32_t syslog_level = level_map[level].syslog_level;

	vsyslog(LOG_USER | syslog_level, msg, args);
	return 0;
}

static nyx_log_printer_function_t nyx_printer = _nyx_log_syslog_printer;


static int32_t print_error_wrapper(const char *msg, ...)
{
	int32_t printed;

	va_list va;
	va_start(va, msg);
	printed = (*nyx_printer)(NYX_LOG_ERROR, msg, va);
	va_end(va);

	return printed;
}

void nyx_log_set_printer(nyx_log_printer_function_t new_log_printer)
{
	if (new_log_printer == NULL)
	{
		print_error_wrapper("Attempt to set a NULL logger");
		return;
	}

	nyx_printer = new_log_printer;

	if (nyx_printer == _nyx_log_console_printer)
	{
		use_colors = true;
	}
	else
	{
		use_colors = false;
	}
}

void nyx_log_set_level(nyx_log_level_t level)
{
	nyx_log_level = CLAMP(level, NYX_LOG_DEFAULT, NYX_LOG_DEBUG);
}



void nyx_log_init()
{
	char *level_str = getenv("NYX_LOG_LEVEL");
	nyx_log_level_t new_level = NYX_LOG_WARNING;
	nyx_log_destination_t printer = NYX_LOG_PRINTER_SYSLOG;

	if (NULL != level_str)
	{
		/* level_letters contains first character of the various log levels:
		 * none,error,critical,warning,message,info,debug
		 */
		char firstch = *level_str;
		static const char *level_letters = "necwmid";
		char *straddr = strchr(level_letters, tolower(firstch));

		if (NULL != straddr)
		{
			new_level = straddr - level_letters;
		}
		else if (isdigit(firstch))
		{
			new_level = firstch - '0';
		}
		else
		{
			new_level = NYX_LOG_WARNING;
		}

		/* Check if env.variable contains ":" and a printer name (console, syslog, ...) */
		straddr = strchr(level_str, ':');

		if (NULL != straddr && *(straddr + 1) != '\0')
		{
			char chprint = tolower(*(straddr + 1));

			if (chprint == 'c' || chprint == 't')
			{
				printer = NYX_LOG_PRINTER_CONSOLE;
			}
			else if (chprint == 's')
			{
				printer = NYX_LOG_PRINTER_SYSLOG;
			}
			else
			{
				print_error_wrapper("Unknown log printer '%s' -- use 'c' or 's'\n",
				                    straddr + 1);
			}
		}
	}

	if (new_level != nyx_log_level)
	{
		nyx_log_set_level(new_level);
	}

	switch (printer)
	{
		case NYX_LOG_PRINTER_CONSOLE:
			nyx_log_set_printer(_nyx_log_console_printer);
			break;

		case NYX_LOG_PRINTER_SYSLOG:
			nyx_log_set_printer(_nyx_log_syslog_printer);
			break;

		default:
			print_error_wrapper("Invalid log printer given");
	}
}


void _nyx_log__(const char *file, int32_t line, nyx_log_level_t level,
                const char *msg, ...)
{
	if (NYX_LOG_NONE == nyx_log_level)
	{
		return;
	}

	if (NYX_LOG_DEFAULT == nyx_log_level)   /* use glib logging */
	{
		va_list va;
		GLogLevelFlags glib_log_level;

		level = CLAMP(level, NYX_LOG_ERROR, NYX_LOG_LEVEL_MAXIMUM);
		glib_log_level = level_map[level].glib_level;

		va_start(va, msg);
		g_logv(NYX_LOG_DOMAIN, glib_log_level, msg, va);
		va_end(va);

	}
	else if (nyx_log_level >= level && NYX_LOG_LEVEL_MAXIMUM >= level)
	{
		va_list va;
		va_start(va, msg);

		_logged_file = file;    /* Used in the nyx_printer methods */
		_logged_line = line;

		(*nyx_printer)(level, msg, va);

		va_end(va);
	}
}
