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
 * @file nyx_sensor_rotation_common.h
 *
 */

#ifndef _NYX_SENSOR_ROTATION_COMMON_H_
#define _NYX_SENSOR_ROTATION_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_rotation_public Rotation Sensor
* @ingroup nyx_public
* @{
*/


typedef struct
{
	float w;
	float x;
	float y;
	float z;
} nyx_sensor_rotation_quaternion_vector_t;

typedef struct
{
	float roll;   /**< amount of roll in degrees */
	float pitch;      /**< amount of pitch in degrees */
	float yaw;    /**< amount of yaw in degrees */
} nyx_sensor_rotation_euler_angle_t;

/**
 * Definition of rotation event type.
 */
typedef struct
{
	float  matrix[9];                       /** Rotation matrix */
	nyx_sensor_rotation_quaternion_vector_t
	quaternion_vector;  /** Quaternion vector of rotation */
	nyx_sensor_rotation_euler_angle_t
	euler_angle;          /** Euler angle of rotation (in degrees) */
} nyx_sensor_rotation_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_ROTATION_COMMON_H_ */
