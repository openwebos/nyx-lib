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
 * @file nyx_sensor_bearing_common.h
 *
 */

#ifndef _NYX_SENSOR_BEARING_COMMON_H_
#define _NYX_SENSOR_BEARING_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_sensor_bearing_public Bearing Sensor
* @ingroup nyx_public
* @{
*/

/**
 * Definition of type for specifying location
 */
typedef struct
{
	float longitude;    /**< location longitude in degrees */
	float latitude;     /**< location latitude in degrees */
	float altitude;     /**< altitude in meters */
} nyx_sensor_bearing_location_t;

/**
 * Definition of bearing event type.
 */
typedef struct
{

	float magnetic;     /**< magnetic bearing in degrees */
	float true_bearing; /**< true bearing in degrees */
	float confidence;   /**< confidence of bearing values in percent (%) */

} nyx_sensor_bearing_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif


#endif /* _NYX_SENSOR_BEARING_COMMON_H_ */
