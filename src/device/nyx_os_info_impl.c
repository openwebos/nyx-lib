/* @@@LICENSE
*
*      Copyright (c) 2013 LG Electronics
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
 * @file nyx_os_info_impl.c
 *
 * @brief Implementation of NYX's public API for accessing OS information
 *
 *******************************************************************************
 */

#include <stdio.h>
#include <inttypes.h>
#include "nyx_os_info_impl.h"

nyx_error_t nyx_os_info_query(nyx_device_handle_t handle,
                              nyx_os_info_query_t type, const char  **val)
{
	nyx_execute_return_function(os_info_query, OS_INFO, QUERY, handle, type, val);
}

