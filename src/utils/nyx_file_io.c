/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
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
 * @file nyx_file_io.c
 *
 * @brief nyx file io implementation
 *
 *******************************************************************************
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define READ_BUFFER_SIZE 10

int32_t nyx_utils_read_value (char* path)
{
	int32_t val = -1;
	int32_t fd = open (path, O_RDONLY);
	if (fd <= -1) {
		goto end;
	}

	char buffer[READ_BUFFER_SIZE];
	ssize_t r = read (fd, buffer, READ_BUFFER_SIZE);
	if (r <= 0) {
		goto end;
	}

	char* endptr = NULL;
	val = (int32_t) strtol (buffer, &endptr, 10);
	if (endptr == buffer) {
		val = -1;
		goto end;
	}

end:

	if (fd >= 0) {
		close (fd);
	}
	return val;
}

void nyx_utils_write_value (char* path, int32_t val)
{
	int32_t fd = open (path, O_WRONLY);
	if (fd <= -1) {
		goto end;
	}

	char buffer[READ_BUFFER_SIZE];
	sprintf(buffer, "%i", val);

	int32_t l = strlen (buffer);
	write (fd, buffer, l);

end:

	if (fd >= 0) {
		close (fd);
	}
}

