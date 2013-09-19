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
 * @file nyx_keys_common.h
 *
 */

#ifndef _NYX_KEYS_COMMON_H_
#define _NYX_KEYS_COMMON_H_

#include <nyx/common/nyx_device.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_keys_public Keys
* @ingroup nyx_public
* @brief Nyx's public API for accessing a keyboard device and the events
*     it generates.
* @{
*/

/**
 * This type is an enum describing the type of the keyboard event.
 * If keyboard_key_type_standard is returned, keys are defined by Linux keycodes.
 * If keyboard_key_type_custom is returned, keys are specific to webOS and their
 *     values should be referenced from nyx_keys_custom_key_t.
 */
typedef enum {
	NYX_KEY_TYPE_UNDEFINED,             /**< value keyboard_key_type_undefined. */
	NYX_KEY_TYPE_STANDARD,              /**< value keyboard_key_type_standard. */
	NYX_KEY_TYPE_CUSTOM,                /**< value keyboard_key_type_custom. */
}
nyx_key_type_t;


/**
 * This type is an enum describing the webOS-specific keys.
 */
typedef enum
{
    NYX_KEYS_CUSTOM_KEY_UNDEFINED,          /**< value NYX_KEYS_CUSTOM_KEY_UNDEFINED. */
    NYX_KEYS_CUSTOM_KEY_VOL_UP,         /**< value NYX_KEYS_CUSTOM_KEY_VOL_UP. */
    NYX_KEYS_CUSTOM_KEY_VOL_DOWN,           /**< value NYX_KEYS_CUSTOM_KEY_VOL_DOWN. */
    NYX_KEYS_CUSTOM_KEY_POWER_ON,           /**< value NYX_KEYS_CUSTOM_KEY_POWER_ON. */
    NYX_KEYS_CUSTOM_KEY_HOME,                  /**< value NYX_KEYS_CUSTOM_KEY_HOME. */
    NYX_KEYS_CUSTOM_KEY_RINGER_SW,          /**< value NYX_KEYS_CUSTOM_KEY_RINGER_SW. */
    NYX_KEYS_CUSTOM_KEY_SLIDER_SW,          /**< value NYX_KEYS_CUSTOM_KEY_SLIDER_SW. */
    NYX_KEYS_CUSTOM_KEY_HEADSET_BUTTON,     /**< value NYX_KEYS_CUSTOM_KEY_HEADSET_BUTTON. */
    NYX_KEYS_CUSTOM_KEY_HEADSET_PORT,       /**< value NYX_KEYS_CUSTOM_KEY_HEADSET_PORT. */
    NYX_KEYS_CUSTOM_KEY_HEADSET_PORT_MIC,       /**< value NYX_KEYS_CUSTOM_KEY_HEADSET_PORT_MIC. */
    NYX_KEYS_CUSTOM_KEY_OPTICAL,            /**< value NYX_KEYS_CUSTOM_KEY_OPTICAL. */

    NYX_KEYS_CUSTOM_KEY_MEDIA_PLAY,         /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_PLAY. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_PAUSE,        /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_PAUSE. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_STOP,         /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_STOP. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_NEXT,         /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_NEXT. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_PREVIOUS,     /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_PREVIOUS. */

    NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_ALL,       /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_ALL. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_TRACK,     /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_TRACK. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_NONE,      /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_REPEAT_NONE. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_SHUFFLE_ON,       /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_SHUFFLE_ON. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_SHUFFLE_OFF,      /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_SHUFFLE_OFF. */

    NYX_KEYS_CUSTOM_KEY_VOL_MUTE,           /**< value NYX_KEYS_CUSTOM_KEY_VOL_MUTE. */
    NYX_KEYS_CUSTOM_KEY_SEARCH,         /**< value NYX_KEYS_CUSTOM_KEY_SEARCH. */
    NYX_KEYS_CUSTOM_KEY_DASHBOARD,          /**< value NYX_KEYS_CUSTOM_KEY_DASHBOARD. */
    NYX_KEYS_CUSTOM_KEY_BRIGHTNESS_UP,      /**< value NYX_KEYS_CUSTOM_KEY_BRIGHTNESS_UP. */
    NYX_KEYS_CUSTOM_KEY_BRIGHTNESS_DOWN,        /**< value NYX_KEYS_CUSTOM_KEY_BRIGHTNESS_DOWN. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_PLAYPAUSE,        /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_PLAYPAUSE. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_REWIND,       /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_REWIND. */
    NYX_KEYS_CUSTOM_KEY_MEDIA_FASTFORWARD,      /**< value NYX_KEYS_CUSTOM_KEY_MEDIA_FASTFORWARD. */
} nyx_keys_custom_key_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_KEYS_COMMON_H_ */
