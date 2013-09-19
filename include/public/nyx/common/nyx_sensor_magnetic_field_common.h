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
 * @file nyx_sensor_magnetic_field_common.h
 *
 */

#ifndef _NYX_SENSOR_MAGNETIC_FIELD_COMMON_H_
#define _NYX_SENSOR_MAGNETIC_FIELD_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_magnetic_field_public Magnetic Field Sensor
* @ingroup nyx_public
* @{
*/

/**
 * Definition of magnetic field event type.
 */
typedef struct
{

	int32_t x;  /**< strength of magnetic field for x-axis in micro Teslas */
	int32_t y;  /**< strength of magnetic field for y-axis in micro Teslas */
	int32_t z;  /**< strength of magnetic field for z-axis in micro Teslas */

	int32_t raw_x;  /**< raw strength of magnetic field for x-axis in micro Teslas */
	int32_t raw_y;  /**< raw strength of magnetic field for y-axis in micro Teslas */
	int32_t raw_z;  /**< raw strength of magnetic field for z-axis in micro Teslas */

} nyx_sensor_magnetic_field_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SENSOR_MAGNETIC_FIELD_COMMON_H_ */
