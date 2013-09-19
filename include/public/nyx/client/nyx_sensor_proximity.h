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
 * @file nyx_sensor_proximity.h
 *
 */

/**
 * @brief Nyx's public API for accessing a proximity sensor
 * device and the events it generates.
 *
 */

#ifndef _NYX_SENSOR_PROXIMITY_H_
#define _NYX_SENSOR_PROXIMITY_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_proximity_public Proximity Sensor
* @ingroup nyx_public
* @{
*/


/**
 * Get the event items for the current event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  present_out_ptr - pointer to the proximity presence value of the proximity event
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_sensor_proximity_event_get_presence(
    nyx_event_handle_t handle, int32_t *present_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_PROXIMITY_H_ */
