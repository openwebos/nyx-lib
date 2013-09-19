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
 * @file nyx_event.h
 *
 */

/**
 * @brief Nyx's events and associated types.
 *
 */

#ifndef _NYX_EVENT_H_
#define _NYX_EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif


/**
* @defgroup nyx_event_public Events
* @ingroup nyx_public
* @{
*/

/**
 * Nyx event types
 */
typedef enum {
	NYX_EVENT_UNDEFINED,            /**< Undefined device type */
	NYX_EVENT_BLUETOOTH_INPUT_DETECT,    /**< Bluetooth Input Detect*/
	NYX_EVENT_KEYS,             /**< Keys */
	NYX_EVENT_TOUCHPANEL,           /**< Touchpanel */
	NYX_EVENT_SENSOR_ACCELERATION,      /**< Acceleration */
	NYX_EVENT_SENSOR_ALS,           /**< Ambient light sensor */
	NYX_EVENT_SENSOR_ANGULAR_VELOCITY,  /**< Angular velocity */
	NYX_EVENT_SENSOR_BEARING,       /**< Bearing (heading) */
	NYX_EVENT_SENSOR_GRAVITY,       /**< Gravity */
	NYX_EVENT_SENSOR_LINEAR_ACCELERATION,   /**< Linear Acceleration */
	NYX_EVENT_SENSOR_MAGNETIC_FIELD,    /**< Magnetic field */
	NYX_EVENT_SENSOR_ORIENTATION,       /**< Orientation */
	NYX_EVENT_SENSOR_PROXIMITY,     /**< Proximity */
	NYX_EVENT_SENSOR_ROTATION,      /**< Rotation */
	NYX_EVENT_SENSOR_SHAKE,         /**< Shake */
	NYX_EVENT_CUSTOM,           /**< Custom */
}
nyx_event_type_t;

struct nyx_event;

/**
 * Nyx handle to the event. Events are opaque to clients.
 */
typedef struct nyx_event *nyx_event_handle_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_EVENT_H_ */
