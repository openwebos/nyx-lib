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
 * @file nyx_sensor_shake_common.h
 *
 */

#ifndef _NYX_SENSOR_SHAKE_COMMON_H_
#define _NYX_SENSOR_SHAKE_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_shake_public Shake Sensor
* @ingroup nyx_public
* @{
*/

/**
 * An enum that describes the state of shaking on device.
 */
typedef enum {
	NYX_SENSOR_SHAKE_NONE,      /**< Device is not shaking */
	NYX_SENSOR_SHAKE_START,     /**< Device has started shaking */
	NYX_SENSOR_SHAKE_SHAKING,   /**< Device continues to shake */
	NYX_SENSOR_SHAKE_STOP,      /**< Device has stopped shaking */
}
nyx_sensor_shake_state_t;

typedef struct
{

	nyx_sensor_shake_state_t
	state;    /**< shaking state of type @ref nyx_sensor_shake_state_t. */
	float  magnitude;           /**< magnitude of shaking in meters per (second)^2 ?? */

} nyx_sensor_shake_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SENSOR_SHAKE_COMMON_H_ */
