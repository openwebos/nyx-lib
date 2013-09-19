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
 * @file nyx_sensor_gravity_common.h
 *
 */

#ifndef _NYX_SENSOR_GRAVITY_COMMON_H_
#define _NYX_SENSOR_GRAVITY_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_gravity_public Gravity Sensor
* @ingroup nyx_public
* @{
*/


/**
 * @brief Definition of gravity event type.
 * The x,y,z portions of this structure form a unit vector |x,y,z| = 1.0.
 */
typedef struct
{

	float x;    /**< gravitational acceleration x component of unit vector */
	float y;    /**< gravitational acceleration y component of unit vector */
	float z;    /**< gravitational acceleration z component of unit vector */

} nyx_sensor_gravity_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_GRAVITY_COMMON_H_ */
