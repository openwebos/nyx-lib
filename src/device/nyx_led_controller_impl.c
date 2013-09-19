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
 *******************************************************************************
 * @file nyx_led_controller_impl.c
 *
 * @brief nyx led controller implementation
 *******************************************************************************
 */

#include "nyx_led_controller_impl.h"

nyx_error_t nyx_led_controller_execute_effect(nyx_device_handle_t handle,
        nyx_led_controller_effect_t effect)
{
	nyx_execute_return_function(led_controller_execute_effect, LED_CONTROLLER,
	                            EXECUTE_EFFECT, handle, effect);
}

nyx_error_t nyx_led_controller_stop(nyx_device_handle_t handle,
                                    nyx_led_controller_led_t led)
{
	nyx_execute_return_function(led_controller_stop, LED_CONTROLLER, STOP, handle,
	                            led);
}

nyx_error_t nyx_led_controller_get_state(nyx_device_handle_t handle,
        nyx_led_controller_led_t led, nyx_led_controller_state_t *state)
{
	nyx_execute_return_function(led_controller_get_state, LED_CONTROLLER, GET_STATE,
	                            handle, led, state);
}

nyx_error_t nyx_led_controller_set_abl_state(nyx_device_handle_t handle,
        nyx_led_controller_led_t led, nyx_led_controller_abl_state_t abl_state)
{
	nyx_execute_return_function(led_controller_set_abl_state, LED_CONTROLLER,
	                            SET_ABL_STATE, handle, led, abl_state);
}
