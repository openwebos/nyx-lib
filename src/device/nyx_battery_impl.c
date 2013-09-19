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

/********************************************************************************
 * @file nyx_battery_impl.c
 *
 * @brief This is the nyx battery lib implementation
 ********************************************************************************/

#include "nyx_device_impl.h"
#include <nyx/module/nyx_device_internal.h>

nyx_error_t nyx_battery_query_battery_status(nyx_device_handle_t handle,
        nyx_battery_status_t *status)
{
	nyx_execute_return_function(battery_query_battery_status, BATTERY,
	                            QUERY_BATTERY_STATUS, handle, status);
}

nyx_error_t nyx_battery_register_battery_status_callback(
    nyx_device_handle_t handle, nyx_device_callback_function_t callback_func,
    void *context)
{
	nyx_execute_return_function(battery_register_battery_status_callback, BATTERY,
	                            REGISTER_BATTERY_STATUS_CALLBACK, handle, callback_func, context);
}

nyx_error_t nyx_battery_authenticate_battery(nyx_device_handle_t handle,
        bool *result)
{
	nyx_execute_return_function(battery_authenticate_battery, BATTERY,
	                            AUTHENTICATE_BATTERY, handle, result);
}

nyx_error_t nyx_battery_get_ctia_parameters(nyx_device_handle_t handle,
        nyx_battery_ctia_t *params)
{
	nyx_execute_return_function(battery_get_ctia_parameters, BATTERY,
	                            GET_CTIA_PARAMETERS, handle, params);
}

nyx_error_t nyx_battery_set_wakeup_percentage(nyx_device_handle_t handle,
        int32_t percentage)
{
	nyx_execute_return_function(battery_set_wakeup_percentage, BATTERY,
	                            SET_WAKEUP_PARAMETERS, handle, percentage);
}
