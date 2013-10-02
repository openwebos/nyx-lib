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
 * @file nyx_system.c
 *
 * @brief nyx system file
 *
 *******************************************************************************
 */

#include "nyx_device_impl.h"
#include "nyx_core_impl.h"
#include <nyx/nyx_module.h>


nyx_error_t nyx_system_set_alarm(nyx_device_handle_t handle, time_t time,
                                 nyx_device_callback_function_t callback_func, void *context)
{
	nyx_execute_return_function(system_set_alarm, SYSTEM, SET_ALARM, handle, time,
	                            callback_func, context);
}

nyx_error_t nyx_system_query_next_alarm(nyx_device_handle_t handle,
                                        time_t *time)
{
	nyx_execute_return_function(system_query_rtc_time, SYSTEM, QUERY_NEXT_ALARM,
	                            handle, time);
}

nyx_error_t nyx_system_query_rtc_time(nyx_device_handle_t handle, time_t *time)
{
	nyx_execute_return_function(system_query_rtc_time, SYSTEM, QUERY_RTC_TIME,
	                            handle, time);
}

nyx_error_t nyx_system_suspend(nyx_device_handle_t handle, bool *success)
{
	nyx_execute_return_function(system_suspend, SYSTEM, SUSPEND, handle, success);
}

nyx_error_t nyx_system_shutdown(nyx_device_handle_t handle,
                                nyx_system_shutdown_type_t type, const char *reason)
{
	nyx_execute_return_function(system_shutdown, SYSTEM, SHUTDOWN, handle, type,
	                            reason);
}

nyx_error_t nyx_system_reboot(nyx_device_handle_t handle,
                              nyx_system_shutdown_type_t type, const char *reason)
{
	nyx_execute_return_function(system_reboot, SYSTEM, REBOOT, handle, type,
	                            reason);
}

nyx_error_t nyx_system_erase_partition(nyx_device_handle_t handle,
                                       nyx_system_erase_type_t type)
{
	nyx_execute_return_function(system_erase_partition, SYSTEM, ERASE_PARTITION,
	                            handle, type);
}
