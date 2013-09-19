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
 * @file nyx_event_touchpanel_internal.h
 *
 * @brief Definition of the event structures used by the NYX's internal
 * implementation and modules implementing touchpanel
 *
 */

#ifndef _NYX_EVENT_TOUCHPANEL_INTERNAL_H_
#define _NYX_EVENT_TOUCHPANEL_INTERNAL_H_

#include "nyx_event_internal.h"

#define NYX_MAX_TOUCH_EVENTS (20)

typedef struct
{
	nyx_event_t _parent;
	nyx_touchpanel_event_type_t type;
	nyx_touchpanel_event_item_t item_array[NYX_MAX_TOUCH_EVENTS];
	int32_t item_count;

} nyx_event_touchpanel_t;

#endif /* _NYX_EVENT_TOUCHPANEL_INTERNAL_H_ */
