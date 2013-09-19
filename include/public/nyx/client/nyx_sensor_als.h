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
 * @file nyx_sensor_als.h
 *
 */

/**
 * @brief Nyx's public API for accessing an ambient light sensor
 * device and the events it generates.
 *
 */

#ifndef _NYX_SENSOR_ALS_H_
#define _NYX_SENSOR_ALS_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_als_public Ambient Light Sensor
* @ingroup nyx_public
* @{
*/

/**
 * Get the light intensity value of the ambient light sensor (ALS) event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  intensity_in_lux_out_ptr - pointer to light intensity value (in lux) of the ALS event
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_sensor_als_event_get_intensity(
    nyx_event_handle_t handle, int32_t *intensity_in_lux_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SENSOR_ALS_H_ */
