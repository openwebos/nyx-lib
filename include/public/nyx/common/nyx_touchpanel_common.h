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
 * @file nyx_touchpanel_common.h
 *
 */

#ifndef __NYX_TOUCHPANEL_COMMON_H__
#define __NYX_TOUCHPANEL_COMMON_H__

#include <nyx/common/nyx_device.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
* @defgroup nyx_touchpanel_public Touchpanel
* @ingroup nyx_public
* @{
*/


/**
 * This type is an enum describing the touchpanel event.
 */
typedef enum {
	NYX_TOUCHPANEL_EVENT_TYPE_INVALID,      /**< value NYX_TOUCHPANEL_EVENT_TYPE_INVALID. */
	NYX_TOUCHPANEL_EVENT_TYPE_TOUCH,        /**< value NYX_TOUCHPANEL_EVENT_TYPE_TOUCH. */
	NYX_TOUCHPANEL_EVENT_TYPE_SCAN_COMPLETE,    /**< value NYX_TOUCHPANEL_EVENT_TYPE_SCAN_COMPLETE. */

}
nyx_touchpanel_event_type_t;

/**
 * This type is an enum describing the state of the touchpanel event.
 */
typedef enum
{
    NYX_TOUCHPANEL_STATE_UNDEFINED = -1,    /**< value NYX_TOUCHPANEL_STATE_UNDEFINED. */
    NYX_TOUCHPANEL_STATE_DOWN,      /**< value NYX_TOUCHPANEL_STATE_DOWN. */
    NYX_TOUCHPANEL_STATE_UP,        /**< value NYX_TOUCHPANEL_STATE_UP. */
    NYX_TOUCHPANEL_STATE_MOVE,      /**< value NYX_TOUCHPANEL_STATE_MOVE. */
} nyx_touchpanel_state_t;

/**
 * This type is an enum used for setting current mode of the touchpanel.
 */
typedef enum
{
    NYX_TOUCHPANEL_MODE_DEFAULT = 0,        /**< value NYX_TOUCHPANEL_MODE_DEFAULT. */
    NYX_TOUCHPANEL_MODE_VIRTUAL_KEYBOARD = 1,   /**< value NYX_TOUCHPANEL_MODE_VIRTUAL_KEYBOARD. */
} nyx_touchpanel_mode_t;

typedef struct
{

	int64_t timestamp;      /**< value timestamp of touch event. */
	uint32_t finger;        /**< value finger of touch event. */
	nyx_touchpanel_state_t state;   /**< value state of touch event. */
	int32_t x;          /**< value x coordinate of touch event. */
	int32_t y;          /**< value y coordinate of touch event. */
	int32_t gestureKey;     /**< value gestureKey is the raw gesture key value to be interpretted by caller */
	int32_t xVelocity;      /**< value xVelocity is the xVelocity associated with the gestureKey */
	int32_t yVelocity;      /**< value yVelocity is the yVelocity associated with the gestureKey */
	float weight;           /**< value weight of touch event. */

} nyx_touchpanel_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif // __NYX_TOUCHPANEL_COMMON_H__

