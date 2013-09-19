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
 * @file nyx_log.h
 *
 */

#ifndef _NYX_LOG_H_
#define _NYX_LOG_H_

#include <stdarg.h>
#include <nyx/common/nyx_macros.h>

/*
Logging domains within nyx:
 - Nyx: All library, stubs, modules

Logging can be set at runtime:
   export NYX_LOG_LEVEL=info (or =INFO, =5)
   -or-
   export NYX_LOG_LEVEL=debug:syslog

To disable all nyx logging, set NYX_LOG_LEVEL=0.
If NYX_LOG_LEVEL is not set, then log level is set to NYX_LOG_DEFAULT, meaning:
 - Use glib for logging and display glib levels: error, critical, warning and message.
   Note info, debug and trace are suppressed.
 */

#define NYX_LOG_DOMAIN "Nyx"

typedef enum
{
    NYX_LOG_DEFAULT = -1,
    NYX_LOG_NONE = 0,
    NYX_LOG_ERROR,
    NYX_LOG_CRITICAL,
    NYX_LOG_WARNING,
    NYX_LOG_MESSAGE,
    NYX_LOG_INFO,
    NYX_LOG_DEBUG,
    NYX_LOG_LEVEL_MAXIMUM = NYX_LOG_DEBUG,
} nyx_log_level_t;

typedef enum
{
    NYX_LOG_PRINTER_CONSOLE = 1,
    NYX_LOG_PRINTER_SYSLOG,
} nyx_log_destination_t;

typedef int32_t (*nyx_log_printer_function_t)(nyx_log_level_t level,
        const char *msg, va_list args);


void nyx_log_init();
void nyx_log_set_level(nyx_log_level_t level);
void nyx_log_set_printer(nyx_log_printer_function_t new_logger);


#define nyx_critical(m, args...) nyx_msg(NYX_LOG_CRITICAL, (m), ##args)
#define nyx_error(m, args...) nyx_msg(NYX_LOG_ERROR, (m), ##args)
#define nyx_warn(m, args...) nyx_msg(NYX_LOG_WARNING, (m), ##args)
#define nyx_info(m, args...) nyx_msg(NYX_LOG_INFO, (m), ##args)
#define nyx_debug(m, args...) nyx_msg(NYX_LOG_DEBUG, (m), ##args)
#define nyx_print(l, m, args...) nyx_msg(l, (m), ##args)

#define nyx_msg(msg_level, msg, args...)                                 \
    do {                                                             \
      _nyx_log__(__FILE__, __LINE__, (msg_level), (msg), ##args);    \
    } while(0)

void _nyx_log__(const char *file, int32_t line, nyx_log_level_t level,
                const char *msg, ...) NYX_PRINTF_FORMAT_FUNC(4, 5);

#endif /* _NYX_LOG_H_ */
