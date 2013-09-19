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
 * @file nyx_sensor_orientation_common.h
 *
 */

#ifndef _NYX_SENSOR_ORIENTATION_COMMON_H_
#define _NYX_SENSOR_ORIENTATION_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_orientation_public Orientation Sensor
* @ingroup nyx_public
* @{
*/

/**
 * This type is an enum describing the value of the orientation event.
 */
typedef enum {
	NYX_SENSOR_ORIENTATION_UNDEFINED,   /**< Device orientation is unknown */
	NYX_SENSOR_ORIENTATION_FACE_UP,     /**< Device is facing up */
	NYX_SENSOR_ORIENTATION_FACE_DOWN,   /**< Device is facing down */
	NYX_SENSOR_ORIENTATION_FACE_FORWARD,    /**< Device is in normal orientation */
	NYX_SENSOR_ORIENTATION_FACE_BACK,   /**< Device is in upside-down orientation */
	NYX_SENSOR_ORIENTATION_LEFT,        /**< Device has left side facing down */
	NYX_SENSOR_ORIENTATION_RIGHT,       /**< Device has right side facing down */
}
nyx_sensor_orientation_value_t;

/**
 * Definition of threshold values in x,y,z axis for orientation event.
 * The orientation (in degrees) must be greater than threshold for an event to be emitted.
 */
typedef struct
{
	int32_t x;  /**< Threshold (minimum rotation) for x-axis in degrees */
	int32_t y;  /**< Threshold (minimum rotation) for y-axis in degrees */
	int32_t z;  /**< Threshold (minimum rotation) for z-axis in degrees */
} nyx_sensor_orientation_threshold_t;


/**
 * Definition of orientation event type.
 */
typedef struct
{

	nyx_sensor_orientation_value_t
	value;   /**< orientation value of type @ref nyx_sensor_orientation_value_t. */

} nyx_sensor_orientation_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SENSOR_ORIENTATION_COMMON_H_ */
