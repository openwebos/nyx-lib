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
 * @file nyx_utils.h
 *
 */


#ifndef _NYX_UTILS_H_
#define _NYX_UTILS_H_

#include <stdint.h>
#include <nyx/module/nyx_device_internal.h>

/* Utility functions to write and read an integer value to/from a file */
void nyx_utils_write_value(char *path, int32_t val);
int32_t nyx_utils_read_value(char *path);

nyx_error_t nyx_utils_async_callback(nyx_device_t *device_in_ptr,
                                     nyx_device_callback_function_t callback,
                                     nyx_callback_status_t status, void *context);

#endif /* _NYX_UTILS_H_ */
