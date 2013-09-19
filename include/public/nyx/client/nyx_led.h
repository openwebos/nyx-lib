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
 * @file nyx_led.h
 *
 */

/**
 * @brief Nyx's public API for accessing an LED device.
 *
 */

#ifndef _NYX_LED_H_
#define _NYX_LED_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_led_public LED
* @ingroup nyx_public
* @{
*/

/**
 * Set the brightness of the LED device. The range is 0-100%.
 *
 * @param[in]   handle - the device handle
 * @param[in]   brightness - brightness to set
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_set_brightness(nyx_device_handle_t handle,
        int32_t brightness);

/**
 * Get the brightness of the LED device. The range is 0-100%.
 *
 * @param[in]   handle - the device handle
 * @param[out]  brightness_out_ptr - pointer to store current brightness of the LED device
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_get_brightness(nyx_device_handle_t handle,
        int32_t *brightness_out_ptr);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_LED_H_ */
