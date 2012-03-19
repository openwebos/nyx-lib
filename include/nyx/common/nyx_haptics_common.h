/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
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
typedef enum
{
    HAPTICS_EFFECT_UNDEFINED = 0,   /**< value HAPTICS_EFFECT_UNDEFINED. */
    HAPTICS_EFFECT_RINGTONE,        /**< value HAPTICS_EFFECT_RINGTONE. */
    HAPTICS_EFFECT_ALERT,           /**< value HAPTICS_EFFECT_ALERT. */
    HAPTICS_EFFECT_NOTIFICATION,    /**< value HAPTICS_EFFECT_NOTIFICATION. */
    HAPTICS_EFFECT_TAPDOWN,         /**< value HAPTICS_EFFECT_TAPDOWN. */
    HAPTICS_EFFECT_TAPUP,           /**< value HAPTICS_EFFECT_TAPUP. */


} nyx_haptics_effect_type_t;


/**
 * This type is an enum describing the direction for a custom haptics effect
 */
typedef enum
{
    HAPTICS_DIRECTION_RIGHT,        /**< value HAPTICS_DIRECTION_RIGHT. */
    HAPTICS_DIRECTION_LEFT,         /**< value HAPTICS_DIRECTION_LEFT. */

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
