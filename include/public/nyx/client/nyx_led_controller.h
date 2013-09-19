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
 * @file nyx_led_controller.h
 *
 */

/**
 * @brief Nyx's public LED Controller API.
 */

#ifndef _NYX_LED_CONTROLLER_H_
#define _NYX_LED_CONTROLLER_H_

#include <nyx/client/nyx_led_controller_core_configuration.h>
#include <nyx/common/nyx_led_controller_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_led_controller_public LED Controller
* @ingroup nyx_public
* @{
*/

/**
 * Execute an effect on the LED controller.
 *
 * @param[in]   handle - the device handle
 * @param[in]   effect - effect description and parameters
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_execute_effect(
    nyx_device_handle_t handle, nyx_led_controller_effect_t effect);

/**
 * Stop effect(s) on given LEDs.
 *
 * @param[in]   handle - the device handle
 * @param[in]   led - LED mask for LEDs to stop
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_stop(nyx_device_handle_t handle,
        nyx_led_controller_led_t led);

/**
 * Get the state of LEDs.
 *
 * @param[in]   handle - the device handle
 * @param[in]   led - LED whose state you want to get
 * @param[out]  state_out_ptr - pointer to hold state of LED
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_get_state(
    nyx_device_handle_t handle,
    nyx_led_controller_led_t led, nyx_led_controller_state_t *state_out_ptr);


/**
 * Set the state of abl -- enabled or disabled for LED.
 *
 * @param[in]   handle - the device handle
 * @param[in]   led - LED whose abl state you want to set
 * @param[in]   abl_state - state to set to
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_set_abl_state(
    nyx_device_handle_t handle,
    nyx_led_controller_led_t led, nyx_led_controller_abl_state_t abl_state);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_LED_CONTROLLER_H_ */
