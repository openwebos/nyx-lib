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
 * @file nyx_event_sensor_als_internal.h
 *
 * @brief Definition of the event structures used by the NYX's internal
 * implementation and modules implementing als
 *
 */

#ifndef _NYX_EVENT_SENSOR_ALS_INTERNAL_H_
#define _NYX_EVENT_SENSOR_ALS_INTERNAL_H_

#include "nyx_event_internal.h"

typedef struct
{
	int32_t intensity_in_lux;
} nyx_sensor_als_event_item_t;


typedef struct
{
	nyx_event_t _parent;
	nyx_sensor_als_event_item_t item;

} nyx_event_sensor_als_t;

#endif /* _NYX_EVENT_SENSOR_ALS_INTERNAL_H_ */
