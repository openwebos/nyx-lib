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
 * @file nyx_system.h
 *
 */

/**
 * @brief Nyx's public system API.
 *
 */

#ifndef _NYX_SYSTEM_H_
#define _NYX_SYSTEM_H_

#include <time.h>
#include <nyx/common/nyx_system_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_system_public System
* @ingroup nyx_public
* @{
*/

/**
 * @brief Set an RTC alarm.
 *
 * @param[in]  handle - the event handle
 * @param[in]  time - time to set the alarm for (if 0, any existing RTC alarm present will be cleared)
 * @param[in]  callback - callback function to be called when any RTC alarm fires
 * @param[in]  context - context passed to the callback function
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_set_alarm(nyx_device_handle_t handle, time_t time, nyx_device_callback callback_func, void *context);

/**
 * @brief Query RTC time for next alarm.
 *
 * @param[in]  handle - the event handle
 * @param[out] time - RTC time for next alarm
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_query_next_alarm(nyx_device_handle_t handle, time_t *time);


/**
 * @brief Query current RTC time.
 *
 * @param[in]  handle - the event handle
 * @param[out] time - RTC time returned by the RTC driver
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_query_rtc_time(nyx_device_handle_t handle, time_t *time);



/**
 * @brief Suspend the device.
 *
 * @param[in]  handle - the event handle
 * @param[out] success - true if device was able to suspend
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 * Note: This call will return only when the device has resumed again or
 * failed to suspend.
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_suspend(nyx_device_handle_t handle, bool *success);


/**
 * @brief Shut down the device.
 *
 * @param[in] handle - the event handle
 * @param[in] type  - normal or emergency shutdown
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_shutdown(nyx_device_handle_t handle, nyx_system_shutdown_type_t type);


/**
 * @brief Reboot the device.
 *
 * @param[in] handle - the event handle
 * @param[in] type  -  normal or emergency reboot
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_reboot(nyx_device_handle_t handle, nyx_system_shutdown_type_t type);


/*   MSM APIs   */

/**
 * @brief Enable/disable MSM mode.
 *
 * @param[in] handle - the event handle
 * @param[in] action - enable/disable MSM mode
 * @param[out] ret - return the error code (if any)
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_set_msm_mode(nyx_device_handle_t handle, nyx_system_msm_action_t action, nyx_system_msm_return_code_t *ret);

/**
 * @brief Query current MSM state.
 *
 * @param[in]  handle - the event handle
 * @param[out] state  - current MSM state
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_get_msm_state(nyx_device_handle_t handle, nyx_system_msm_state_t *state);

/**
 * @brief Register callback function for MSM mode changes.
 *
 * @param[in]  handle - the event handle
 * @param[in]  callback_func - callback function to handle the event
 * @param[in]  context - for callback function
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_register_msm_change_callback(nyx_device_handle_t handle, nyx_device_callback callback_func, void *context);

/**
 * @brief Erase partition.
 *
 * @param[in]  handle - the event handle
 * @param[in]  type   - erase type (var/media/all/wipe)
 * @param[out] error_msg - error message in case underlying erase script fails
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_erase_partition(nyx_device_handle_t handle, nyx_system_erase_type_t type, const char *error_msg);

/**
 * @brief Load a new QOS profile.
 *
 * @param[in] handle - the device handle
 * @param[in] profile - pointer to nyx_qos_profile_t structure populated with the requested QOS values
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_qos_request_profile(nyx_device_handle_t handle, nyx_qos_profile_t *profile);


/**
 * @brief Release the constraints in the specified qos profile.
 *
 * @param[in] handle - the device handle
 * @param[in] profile - the same nyx_qos_profile_t pointer passed in the request function
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_qos_release_profile(nyx_device_handle_t handle, nyx_qos_profile_t *profile);

/**
 * @brief Enable the system tickle mode (set system cpu frequency to max value) for
 * a specified time interval.
 *
 * @param[in] handle - the device handle
 * @param[in] duration - time in msec for tickle mode
 * (if this is set to 0, tickle mode will be set for a default duration)
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_system_qos_tickle(nyx_device_handle_t handle, int32_t duration);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SYSTEM_H_ */
