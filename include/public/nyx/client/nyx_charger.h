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
 * @file nyx_charger.h
 *
 */

/**
 * @brief Nyx's public charging API.
 *
 */

#ifndef _NYX_CHARGER_H_
#define _NYX_CHARGER_H_

#include <nyx/common/nyx_charger_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_charger_public Charging
* @ingroup nyx_public
* @{
*/

/**
 * @brief Query charger status.
 *
 * @param[in]   handle - the event handle
 * @param[out]  status_out_ptr - (max) charger status (needs to be allocated by caller)
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_charger_query_charger_status(
    nyx_device_handle_t handle, nyx_charger_status_t *status_out_ptr);


/**
 * @brief Register callback function for any change in charger status.
 *
 * @param[in]  handle - the event handle
 * @param[in]  callback_func - the callback function to handle the event
 * @param[in]  context - for callback function
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_charger_register_charger_status_callback(
    nyx_device_handle_t handle, nyx_device_callback_function_t callback_func,
    void *context);


/**
 * @brief Enable device charging.
 *
 * @param[in]   handle - the event handle
 * @param[out]  status - charger information used for enabling charging
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_charger_enable_charging(nyx_device_handle_t
        handle, nyx_charger_status_t *status);

/**
 * @brief Disable device charging.
 *
 * @param[in]   handle - the event handle
 * @param[out]  status - charger information used for disabling charging
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_charger_disable_charging(
    nyx_device_handle_t handle, nyx_charger_status_t *status);

/**
 * @brief Register callback function for any change in charging state.
 *
 * @param[in]  handle - the event handle
 * @param[in]  callback_func - the callback function to handle the event
 * @param[in]  context - for callback function
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_charger_register_state_change_callback(
    nyx_device_handle_t handle, nyx_device_callback_function_t callback_func,
    void *context);

/**
 * @brief Query charging event.
 *
 * This API needs to be called every time the callback function registered with
 * the "nyx_charger_register_state_change_callback" function is called.  The
 * "event" parameter returned is the ORed value of all the pending events, so
 * even if this API is called once after multiple callbacks, it returns back
 * all the pending events, and only then clears these events in charger module.
 *
 * @param[in]   handle - the event handle
 * @param[out]  event  - ORing of all the pending charging events
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_charger_query_charger_event(
    nyx_device_handle_t handle, nyx_charger_event_t *event);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_CHARGER_H_ */
