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
 * @file nyx_haptics_common.h
 *
 */

#ifndef _NYX_HAPTICS_COMMON_H_
#define _NYX_HAPTICS_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_haptics_public Haptics
* @ingroup nyx_public
* @{
*/



/**
 * This type is an enum describing the types of haptics effects
 */
typedef enum {
	NYX_HAPTICS_EFFECT_UNDEFINED = 0,   /**< value NYX_HAPTICS_EFFECT_UNDEFINED. */
	NYX_HAPTICS_EFFECT_RINGTONE,        /**< value NYX_HAPTICS_EFFECT_RINGTONE. */
	NYX_HAPTICS_EFFECT_ALERT,       /**< value NYX_HAPTICS_EFFECT_ALERT. */
	NYX_HAPTICS_EFFECT_NOTIFICATION,    /**< value NYX_HAPTICS_EFFECT_NOTIFICATION. */
	NYX_HAPTICS_EFFECT_TAPDOWN,     /**< value NYX_HAPTICS_EFFECT_TAPDOWN. */
	NYX_HAPTICS_EFFECT_TAPUP,       /**< value NYX_HAPTICS_EFFECT_TAPUP. */


}
nyx_haptics_effect_type_t;


/**
 * This type is an enum describing the direction for a custom haptics effect
 */
typedef enum
{
    NYX_HAPTICS_DIRECTION_RIGHT,        /**< value NYX_HAPTICS_DIRECTION_RIGHT. */
    NYX_HAPTICS_DIRECTION_LEFT,     /**< value NYX_HAPTICS_DIRECTION_LEFT. */

} nyx_haptics_direction_t;

typedef struct
{
	int32_t period;
	int32_t duration;
	nyx_haptics_direction_t direction;
	nyx_haptics_effect_type_t type;

} nyx_haptics_configuration_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_HAPTICS_COMMON_H_ */
