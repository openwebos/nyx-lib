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
 * @file nyx_sensor_acceleration.h
 *
 * @brief Nyx's public API for accessing an acceleration sensor
 * device and the events it generates.
 *
 */

#ifndef _NYX_SENSOR_ACCELERATION_H_
#define _NYX_SENSOR_ACCELERATION_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_sensor_acceleration_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_acceleration_public Acceleration Sensor
* @ingroup nyx_public
* @brief Nyx's public API for accessing an acceleration sensor
* device and the events it generates.
* @{
*/

/**
 * Get the event items for the current event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  event_out_ptr - pointer to the acceleration event item
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_sensor_acceleration_event_get_item(
    nyx_event_handle_t handle, nyx_sensor_acceleration_event_item_t *event_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_ACCELERATION_H_ */
