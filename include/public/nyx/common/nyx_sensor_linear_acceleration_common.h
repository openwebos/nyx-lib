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
 * @file nyx_sensor_linear_acceleration_common.h
 *
 */

#ifndef _NYX_SENSOR_LINEAR_ACCELERATION_COMMON_H_
#define _NYX_SENSOR_LINEAR_ACCELERATION_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_linear_acceleration_public Linear Acceleration Sensor
* @ingroup nyx_public
* @{
*/

/**
 * Definition of linear acceleration event type.
 */
typedef struct
{

	float x;        /**< acceleration value for x-axis in meters per second<sup>2</sup> */
	float y;        /**< acceleration value for y-axis in meters per second<sup>2</sup> */
	float z;        /**< acceleration value for z-axis in meters per second<sup>2</sup> */
	float world_x;      /**< world coordinate acceleration value for x-axis in meters per second<sup>2</sup> */
	float world_y;      /**< world coordinate acceleration value for y-axis in meters per second<sup>2</sup> */
	float world_z;      /**< world coordinate acceleration value for z-axis in meters per second<sup>2</sup> */

} nyx_sensor_linear_acceleration_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_LINEAR_ACCELERATION_COMMON_H_ */
