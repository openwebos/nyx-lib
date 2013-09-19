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
 * @file nyx_bluetooth_input_detect.h
 *
 */

/**
 * @brief Nyx's public API for accessing a bluetooth input detection device
 * and the events it generates.
 *
 */

#ifndef _NYX_BLUETOOTH_INPUT_DETECT_H_
#define _NYX_BLUETOOTH_INPUT_DETECT_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_bluetooth_input_detect_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_bluetooth_input_detect_public Bluetooth Input Detection
* @ingroup nyx_public
* @{
*/

/**
 * Get the data associated with the nyx_bluetooth_input_detect event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  item_out_ptr - pointer to bluetooth_input_detect_event_item of ALS event
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_bluetooth_input_detect_event_get_data(
    nyx_event_handle_t handle,
    nyx_bluetooth_input_detect_event_item_t *item_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_BLUETOOTH_INPUT_DETECT_H_ */
