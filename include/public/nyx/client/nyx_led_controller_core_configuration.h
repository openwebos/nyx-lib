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
 * @file nyx_led_controller_core_configuration.h
 *
 */


#ifndef _NYX_LED_CONTROLLER_CORE_CONFIGURATION_H_
#define _NYX_LED_CONTROLLER_CORE_CONFIGURATION_H_

#include <nyx/common/nyx_led_controller_core_configuration_common.h>

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
 * Create an LED core configuration.
 *
 * @param[in]   effect_type - effect type for core configuration
 * @param[out]  handle_ptr - pointer to a handle to store handle for the
 *              newly created configuration
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_create(
    nyx_led_controller_effect_type_t effect_type,
    nyx_led_controller_core_configuration_handle_t *handle_ptr);

/*
 * Set a parameter in an LED core configuration.
 *
 *  The following parameters are required for each effect:
 *
 *  NYX_LED_CONTROLLER_EFFECT_LED_FADE
 *      fade leds in the following pattern:
 *
 *                                        brightness
 *                                       v
 *                  center_fade_in -->  /\
 *                       (in ms)       /  \
 *                                    /    \ <-center_fade_out
 *           CenterLED  _____________/      \     (in ms)
 *                                           \
 *                                            \____(brightness = 0)
 *
 *                                       brightness
 *                                       v
 *                  side_fade_in -->    /\
 *                       (in ms)       /  \
 *                                    /    \ <-side_fade_out
 *           SideLED    _____________/      \     (in ms)
 *                                           \
 *                                            \____(brightness = 0)
 *  requires:
 *      brightness,
 *      center_fade_in
 *      center_fade_out
 *      side_fade_in,
 *      side_fade_out
 *
 *  default values:
 *      center_fade_in = 200
 *      center_fade_out = 300
 *      side_fade_in = 200
 *      side_fade_out = 600
 *
 *
 *  NYX_LED_CONTROLLER_EFFECT_FULL_FADE
 *      fade left, right, center leds:
 *
 *                                        brightness
 *                                        v
 *                         first_in -->  /\
 *                        (in ms)       /  \
 *                                     /    \ <-first_out
 *            (Led1)     _____________/      \     (in ms)
 *                                            \
 *                                             \____(brightness = 0)
 *
 *
 *                                        brightness
 *                                        v
 *                        second_in -->  /\
 *                        (in ms)       /  \
 *                                     /    \ <-second_out
 *             (CenterLed)____________/      \     (in ms)
 *                                                     \
 *                                                      \____(brightness = 0)
 *
 *                      \
 *                       \
 *                        \ <-third_out
 *             (Led3)      \     (in ms)
 *                          \
 *                           \____(brightness = 0)
 *
 *
 *  requires:
 *      brightness,
 *      first_in,
 *      first_out,
 *      second_in,
 *      second_out,
 *      third_out,
 *      direction -- if direction is LEFT, then Led1 is LeftLED and Led3 is RightLED.
 *                -- if direction is RIGHT, then Led1 is RightLED and Led3 is LeftLED.
 *
 *
 *  default values:
 *      first_in = 100
 *      first_out = 500
 *      second_in = 100
 *      second_out = 400
 *      third_out = 300
 *      direction = NYX_LED_CONTROLLER_DIRECTION_LEFT
 *
 *  NYX_LED_CONTROLLER_EFFECT_LED_PULSATE
 *      Pulses the specific LED in the following manner:
 *
 *                                       brightness
 *                                    ________v_______
 *                      fade_in -->  /  fade_delay    \
 *                       (in ms)    /     (in ms)      \
 *                                 /                    \ <-fade_out
 *           _____________________/                      \     (in ms)
 *              start_delay                               \
 *               (in ms)                                   \
 *                                                          \
 *                                                           \    brightness = 0
 *                                                            \__________________
 *                                                                 repeat_delay
 *                                                                  (in ms)
 *
 *  requires:
 *     brightness,
 *     start_delay,
 *     fade_in,
 *     fade_out,
 *     duration,
 *     repeat_delay,
 *     repeat
 *
 *  default values:
 *     start_delay = 0
 *     fade_in = 1500
 *     fade_out = 1500
 *     duration = 200
 *     repeat_delay = 4000
 *     repeat = 1
 *
 *  NYX_LED_CONTROLLER_EFFECT_LED_DOUBLE_PULSE
 *      pulse the led twice in the following manner:
 *
 *                 brightness                                      brightness
 *              ________v_______                              ________v_______
 * pulse_ramp->/ pulse_duration \                pulse_ramp  / pulse_duration \
 * (in ms)    /     (in ms)      \                     L>   /   (in ms)        \
 *           /                    \ <-pulse_ramp           /                    \ <-pulse_ramp
 *        __/                      \     (in ms)          /                      \
 *                                  \                    /                        \
 *                                   \  brightness = 0  /                          \
 *                                    \________________/                            \______________
 *                                      pulse_delay                                    repeat_delay
 *                                      (in ms)                                          (in ms)
 *  requires:
 *      brightness,
 *      pulse_ramp,
 *      pulse_duration,
 *      pulse_delay,
 *      repeat_delay,
 *      repeat
 *
 *  default values:
 *      pulse_ramp = 150
 *      pulse_duration = 100
 *      pulse_delay = 100
 *      repeat_delay = 3000
 *      repeat = 1
 *
 *
 *  NYX_LED_CONTROLLER_EFFECT_LED_RAMP_TO
 *      set led from current brightness level to specified brightness in duration (ms) using a linear slope.
 *
 *         __ brightness
 *        /
 *       /
 *      / <-- duration (in ms)
 *     /
 *    /
 *
 *  requires:
 *     brightness
 *     duration
 *
 *  NYX_LED_CONTROLLER_EFFECT_LED_SET
 *      set led to specified brightness
 *  requires:
 *     brightness
 *
 *  NYX_LED_CONTROLLER_EFFECT_WATERDROP
 * This creates a squence of the center fading in, then fading out while the
 *     side leds fade in and out.  If reversed, the center led will us side_fade_in/side_fade_out
 *     and vice versa
 *                                              brightness
 *                                               v
 *                             center_fade_in   /\
 *                               (in ms)       /  \
 *                                            /    \ <-center_fade_out
 *            (LED 1)           _____________/      \     (in ms)
 *                                                   \
 *                                                    \____(brightness = 0)
 *
 *                                                 brightness
 *                                                 v
 *                                side_fade_in-->  /\
 *                                  (in ms)       /  \
 *                                               /    \ <-side_fade_out
 *            (LED 2 starts when LED 1__________/      \     (in ms)
 *                  finishes first ramp)                \
 *                                                       \____(brightness = 0)
 *  requires:
 *     brightness,
 *     center_fade_in
 *     center_fade_out
 *     side_fade_in
 *     side_fade_out
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_SEESAW
 *  A series of 4 serial ramps:
 *     RAMP 1:  LED1 ramps to brightness in duration (ms), then triggers
 *     RAMP 2:  LED2 ramps to brightness in duration (ms), then triggers
 *     RAMP 3:  LED1 ramps to (brightness = 0) in duration (ms), then triggers
 *     RAMP 4:  LED2 ramps to (brightness = 0) in duration (ms)
 *  if direction is not reverse, then LED1 = center led, LED2 = side leds
 *  if direction is reverse, then LED1 = side leds, LED2 = center led
 *
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_LIGHTBAR_SWIPE
 *  A series of 4 sets of serial ramps:
 *      RAMP1:  LED1 ramps from brightness to (brightness = 0) in duration (ms), then triggers
 *      RAMP2:  LED1 ramps from (brightness = 0) to brightness in duration (ms), LED2 ramps from brightness to (brightness = 0) in duration, then
 *      RAMP3:  LED2 ramps from (brightness = 0) to brightness in duration (ms), LED3 ramps from brightness to (brightness = 0) in duration, then
 *      RAMP4:  LED3 ramps from (brightness = 0) to brightness in duration (ms).
 * if direction is left, then LED1 = right, LED2 = center, LED3 = left
 * if direction is not left, then LED1 = left, LED2 = center, LED3 = right
 *
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_LIGHTBAR_FULL_SWIPE
  *  A series of 5 sets of serial ramps:
 *      RAMP1:  LED1 ramps from brightness to (brightness = 0) in duration (ms)
 *      RAMP2:  LED2 ramps from brightness to (brightness = 0) in duration (ms), then triggers
 *      RAMP3:  LED1 ramps from (brightness = 0) to brightness in duration (ms), LED3 ramps from brightness to (brightness = 0) in duration, then
 *      RAMP4:  LED2 ramps from (brightness = 0) to brightness in duration (ms)
 *      RAMP5:  LED3 ramps from (brightness = 0) to brightness in duration (ms).
 * if direction is left, then LED1 = right, LED2 = center, LED3 = left
 * if direction is not left, then LED1 = left, LED2 = center, LED3 = right
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_SWIPE
  *  A series of 4 sets of serial ramps:
 *      RAMP1:  LED1 ramps from (brightness = 0) to brightness in duration (ms), then triggers
 *      RAMP2:  LED1 ramps from brightness to (brightness = 0) in duration (ms), LED2 ramps from (brightness = 0) to brightness in duration, then
 *      RAMP3:  LED2 ramps from brightness to (brightness = 0) in duration (ms), LED3 ramps from (brightness = 0) to brightness in duration, then
 *      RAMP4:  LED3 ramps from brightness to (brightness = 0) in duration (ms).
 * if direction is left, then LED1 = right, LED2 = center, LED3 = left
 * if direction is not left, then LED1 = left, LED2 = center, LED3 = right
 *
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_FULL_SWIPE
 *  A series of 5 sets of serial ramps:
 *      RAMP1:  LED1 ramps from (brightness = 0) to brightness in duration (ms)
 *      RAMP2:  LED2 ramps from (brightness = 0) to brightness in duration (ms), then triggers
 *      RAMP3:  LED1 ramps from brightness to (brightness = 0) in duration (ms), LED3 ramps from (brightness = 0) to brightness in duration, then
 *      RAMP4:  LED2 ramps from brightness to (brightness = 0) in duration (ms)
 *      RAMP5:  LED3 ramps from brightness to (brightness = 0) in duration (ms).
 * if direction is left, then LED1 = right, LED2 = center, LED3 = left
 * if direction is not left, then LED1 = left, LED2 = center, LED3 = right
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 *
 *  NYX_LED_CONTROLLER_EFFECT_FADE_OFF
  *  A series of 3 serial ramps:
 *      RAMP1:  LED1 ramps from brightness to (brightness = 0) in duration (ms)
 *      RAMP2:  LED2 ramps from brightness to (brightness = 0) in duration (ms)
 *      RAMP3:  LED3 ramps from brightness to (brightness = 0) in duration (ms)
 * if direction is left, then LED1 = right, LED2 = center, LED3 = left
 * if direction is not left, then LED1 = left, LED2 = center, LED3 = right
 *  requires:
 *  requires:
 *     brightness,
 *     duration,
 *     direction
 */
/**
 * @brief Set a parameter in an LED core configuration.
 *
 * @param[in]   handle - the configuration handle
 * @param[in]   param - the parameter to modify
 * @param[in]   new_value - the new value to set parameter to
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_set_param(
    nyx_led_controller_core_configuration_handle_t handle,
    nyx_led_controller_parameter_type_t param, int32_t new_value);

/**
 * Finalize an LED core configuration.
 * Meant to be a potential optimization point.
 * An LED core execute command cannot be completed unless the configuration
 * is finalized.
 *
 * @param[in]   handle - the configuration handle
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_finalize(
    nyx_led_controller_core_configuration_handle_t handle);

/**
 * Release memory associated with a handle.
 * Should be called when the handle is no longer needed.
 *
 * @param[in]   handle - the configuration handle
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_led_controller_core_configuration_release(
    nyx_led_controller_core_configuration_handle_t handle);



/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_LED_CONTROLLER_CORE_CONFIGURATION_H_ */
