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
 * @file nyx_led_controller_core_configuration_common.h
 *
 */


#ifndef _NYX_LED_CONTROLLER_CORE_CONFIGURATION_COMMON_H_
#define _NYX_LED_CONTROLLER_CORE_CONFIGURATION_COMMON_H_

#include <nyx/common/nyx_macros.h>
#include <nyx/common/nyx_error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_led_controller_core_configuration_public LED Controller Core Configuration
* @ingroup nyx_public
* @brief Nyx's public LED Controller Core Configuration API.
* @{
*/

/**
 * @brief Defines valid direction values for LED controller devices
 */
typedef enum {
	NYX_LED_CONTROLLER_DIRECTION_UNDEFINED = 0, /**< none, */
	NYX_LED_CONTROLLER_DIRECTION_RIGHT,     /**< right */
	NYX_LED_CONTROLLER_DIRECTION_LEFT,      /**< left */
	NYX_LED_CONTROLLER_DIRECTION_UP,        /**< up */
	NYX_LED_CONTROLLER_DIRECTION_DOWN,      /**< down */
	NYX_LED_CONTROLLER_DIRECTION_FORWARD,       /**< forward */
	NYX_LED_CONTROLLER_DIRECTION_REVERSE,       /**< reverse */
}
nyx_led_controller_effect_direction_t;


/**
 * @brief Defines the parameters used by @ref nyx_led_controller_core_configuration_set_param().
 */
typedef enum
{
    NYX_LED_CONTROLLER_CORE_EFFECT_BRIGHTNESS,      /**< brightness */

    NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_IN,      /**< center_fade_in */
    NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_OUT,     /**< center_fade_out */

    NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_IN,        /**< side_fade_in */
    NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_OUT,       /**< side_fade_out */

    NYX_LED_CONTROLLER_CORE_EFFECT_FADE_IN,         /**< fade_in */
    NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT,        /**< fade_out */

    NYX_LED_CONTROLLER_CORE_EFFECT_START_DELAY,     /**< start_delay */
    NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT_DELAY,      /**< fade_out_delay */
    NYX_LED_CONTROLLER_CORE_EFFECT_DURATION,        /**< duration */

    NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_RAMP,      /**< pulse_ramp */
    NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DURATION,      /**< pulse_duration */
    NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DELAY,     /**< pulse_delay */


    NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT,          /**< repeat */
    NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT_DELAY,        /**< repeat_delay */

    NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_IN,        /**< first_in */
    NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_OUT,       /**< first_out */
    NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_IN,       /**< second_in */
    NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_OUT,      /**< second_out */
    NYX_LED_CONTROLLER_CORE_EFFECT_THIRD_OUT,       /**< third_out */

    NYX_LED_CONTROLLER_CORE_EFFECT_DIRECTION,       /**< direction */


} nyx_led_controller_parameter_type_t;

/**
 * @brief Define the various effects for an led core configuration.
 *
 * @see nyx_led_controller_core_configuration_create()
 */
typedef enum
{
    NYX_LED_CONTROLLER_EFFECT_UNDEFINED     = 0,    /**< none, */
    NYX_LED_CONTROLLER_EFFECT_LED_FADE,     /**< brightness, center_fade_in, center_fade_out, side_fade_in, side_fade_out */
    NYX_LED_CONTROLLER_EFFECT_FULL_FADE,        /**< brightness, first_in, first_out, second_in, second_out, third_out, direction */
    NYX_LED_CONTROLLER_EFFECT_LED_PULSATE,      /**< brightness, start_delay, fade_in, fade_out, duration, repeat_delay, repeat */
    NYX_LED_CONTROLLER_EFFECT_LED_DOUBLE_PULSE, /**< brightness, pulse_ramp, pulse_duration, pulse_delay, repeat_delay, repeat */
    NYX_LED_CONTROLLER_EFFECT_LED_RAMP_TO,      /**< brightness, duration */
    NYX_LED_CONTROLLER_EFFECT_LED_SET,      /**< brightness */
    NYX_LED_CONTROLLER_EFFECT_WATERDROP,        /**< brightness, center_fade_in, center_fade_out, side_fade_in, side_fade_out, direction */
    NYX_LED_CONTROLLER_EFFECT_SEESAW,       /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_LIGHTBAR_SWIPE,   /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_LIGHTBAR_FULL_SWIPE,  /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_SWIPE,        /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_FULL_SWIPE,       /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_FADE_OFF,     /**< brightness, duration, direction */
    NYX_LED_CONTROLLER_EFFECT_SYNC_FADE_TO,     /**< brightness1, brightness2, duration */
} nyx_led_controller_effect_type_t;

struct nyx_led_controller_core_configuration;
typedef struct nyx_led_controller_core_configuration
		*nyx_led_controller_core_configuration_handle_t;

/**
 * Get the value of a parameter in an LED core configuration.
 *
 * @param[in]   handle - the configuration handle
 * @param[in]   param - the parameter to retrieve
 * @param[out]  value_out_ptr - pointer to store value of parameter
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_get_param(
    nyx_led_controller_core_configuration_handle_t handle,
    nyx_led_controller_parameter_type_t param, int32_t *value_out_ptr);

/**
 * Query whether an LED core configuration is finalized.
 *
 * @param[in]   handle - the configuration handle
 * @param[out]  value_out_ptr - pointer to store answer
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_is_finalized(
    nyx_led_controller_core_configuration_handle_t handle, bool *value_out_ptr);


/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_LED_CONTROLLER_CORE_CONFIGURATION_COMMON_H_ */
