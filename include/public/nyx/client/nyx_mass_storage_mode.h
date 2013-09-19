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
 * @file nyx_mass_storage_mode.h
 *
 */

/**
 * @brief Nyx's public Mass Storage Mode API.
 *
 */

#ifndef _NYX_MASS_STORAGE_MODE_H_
#define _NYX_MASS_STORAGE_MODE_H_

#include <nyx/common/nyx_mass_storage_mode_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_mass_storage_mode_public Mass Storage Mode
* @ingroup nyx_public
* @{
*/

/**
 * @brief Enable/disable Mass Storage Mode mode.
 *
 * @param[in] handle - the handle returned from nyx_device_open
 * @param[in] action - enable/disable Mass Storage Mode mode
 * @param[out] ret - return the error code (if any)
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_mass_storage_mode_set_mode(
    nyx_device_handle_t handle, nyx_mass_storage_mode_action_t action,
    nyx_mass_storage_mode_return_code_t *ret);

/**
 * @brief Query current Mass Storage Mode state.
 *
 * @param[in]  handle - the handle returned from nyx_device_open
 * @param[out] state  - current Mass Storage Mode state
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_mass_storage_mode_get_state(
    nyx_device_handle_t handle, nyx_mass_storage_mode_state_t *state);

/**
 * @brief Register callback function for Mass Storage Mode mode changes.
 *
 * @param[in]  handle - the handle returned from nyx_device_open
 * @param[in]  callback_func - callback function to handle the event
 * @param[in]  context - for callback function
 *
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */

NYX_API_EXPORT nyx_error_t nyx_mass_storage_mode_register_change_callback(
    nyx_device_handle_t handle, nyx_device_callback_function_t callback_func,
    void *context);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_MASS_STORAGE_MODE_H_ */
