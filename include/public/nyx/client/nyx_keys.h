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
 * @file nyx_keys.h
 *
 * @brief Nyx's public API for accessing a keyboard device and the events
 *     it generates.
 *
 */

#ifndef _NYX_KEYS_H_
#define _NYX_KEYS_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_keys_common.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_keys_public Keys
* @ingroup nyx_public
* @{
*/

/**
 * Get the key for the current event.
 * If the key type is standard, then the keyCode is returned and left to caller
 * to look up in keymap.
 * No keys are consumed.
 *
 * @param[in]   handle - the event handle
 * @param[out]  key_out_ptr - pointer to store key value
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_keys_event_get_key(nyx_event_handle_t handle,
        int32_t *key_out_ptr);

/**
 * Get the key type for the current event.
 * Key type will be standard or custom (webOS-specific type)
 *
 * @param[in]   handle - the event handle
 * @param[out]  key_type_out_ptr - pointer to store key type
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_keys_event_get_key_type(nyx_event_handle_t
        handle, nyx_key_type_t *key_type_out_ptr);

/**
 * Get the is_key_press value for the current event.
 * Value is 1 if it is a down event; 0 if it is an up event
 *
 * @param[in]   handle - the event handle
 * @param[out]  key_is_press_out_ptr - pointer to store is_press value
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_keys_event_get_key_is_press(
    nyx_event_handle_t handle, bool *key_is_press_out_ptr);

/**
 * Get the is_auto_repeat value for the current event.
 * If is_auto_repeat is true for the current key, it means this key was
 * previously in a down state and the new event is the same key in a down state.
 *
 * @param[in]   handle - the event handle
 * @param[out]  key_is_auto_repeat_out_ptr - pointer to store is_auto_repeat value
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_keys_event_get_key_is_auto_repeat(
    nyx_event_handle_t handle, bool *key_is_auto_repeat_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_KEYS_H_ */
