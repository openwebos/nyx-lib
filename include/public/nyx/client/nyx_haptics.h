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
 * @file nyx_haptics.h
 *
 */

/**
 * @brief Nyx's public API for accessing a haptics device.
 *
 */

#ifndef _NYX_HAPTICS_H_
#define _NYX_HAPTICS_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_haptics_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_haptics_public Haptics
* @ingroup nyx_public
* @{
*/

/**
 * Vibrate according to a specified configuration.
 * The configuration should either identify the type of effect (launching
 * an effect that the device already has preconfigured), or contain values
 * for the period, duration, and direction fields.
 *
 * @param[in]   handle - the device handle
 * @param[in]   configuration - structure containing effect data
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_vibrate(nyx_device_handle_t handle,
        nyx_haptics_configuration_t configuration);

/**
 * Cancel a specified haptics effect.
 *
 * @param[in]   handle - the device handle
 * @param[in]   haptics_id - id of the haptics effect to cancel
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_cancel(nyx_device_handle_t handle,
        int32_t haptics_id);

/**
 * Cancel all haptics effects.
 *
 * @param[in]   handle - the device handle
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_cancel_all(nyx_device_handle_t handle);

/**
 * Get the haptics effect id associated with this device.
 *
 * @param[in]   handle - the device handle.
 * @param[out]  haptics_effect_id_out_ptr - pointer to store the haptics effect id
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_get_effect_id(nyx_device_handle_t handle,
        int32_t *haptics_effect_id_out_ptr);

/**
 * Set the dampening factor associated with this device handle.
 * The dampening factor is a single value to tone down the magnitude of haptics
 * effects.  When the device is initially opened, the dampening factor is 100,
 * signifying 100% of the magnitude specified.  If the dampening factor is set
 * to 50, the magnitude of the effect will be 50% of the originally specified
 * magnitude.  This can be used for tuning the effect.
 *
 * @param[in]   handle - the device handle
 * @param[in]   dampening_factor - value of new dampening factor
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_set_dampening_factor(
    nyx_device_handle_t handle, int32_t dampening_factor);

/**
 * Get the dampening factor associated with this device handle.
 * The dampening factor is a single value to tone down the magnitude of haptics
 * effects.  When the device is initially opened, the dampening factor is 100,
 * signifying 100% of the magnitude specified.  If the dampening factor is set
 * to 50, the magnitude of the effect will be 50% of the originally specified
 * magnitude.  This can be used for tuning the effect.
 *
 * @param[in]   handle - the device handle
 * @param[out]  dampening_factor_out_ptr - pointer to store value
 *          of dampening factor
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_haptics_get_dampening_factor(
    nyx_device_handle_t handle, int32_t *dampening_factor_out_ptr);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_HAPTICS_H_ */
