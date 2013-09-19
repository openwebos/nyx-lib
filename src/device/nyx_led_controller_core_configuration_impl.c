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
 * @file nyx_led_controller_core_configuration_impl.c
 *
 * @brief nyx led controller core implementation
 *******************************************************************************
 */

#include "nyx_led_controller_core_configuration_impl.h"
#include <stdlib.h>

typedef struct
{
	int32_t brightness;

	int32_t center_fade_in;
	int32_t center_fade_out;

	int32_t side_fade_in;
	int32_t side_fade_out;

	int32_t fade_in;
	int32_t fade_out;

	int32_t start_delay;
	int32_t fade_out_delay;
	int32_t duration;

	int32_t pulse_ramp;
	int32_t pulse_duration;
	int32_t pulse_delay;

	int32_t repeat;
	int32_t repeat_delay;

	int32_t first_in;
	int32_t first_out;
	int32_t second_in;
	int32_t second_out;
	int32_t third_out;

	int32_t direction;

	bool final;

} nyx_led_controller_core_configuration;


nyx_error_t nyx_led_controller_core_configuration_create(
    nyx_led_controller_effect_type_t effect_type,
    nyx_led_controller_core_configuration_handle_t *handle_ptr)
{
	nyx_led_controller_core_configuration *configuration =
	    (nyx_led_controller_core_configuration *)calloc(sizeof(
	                nyx_led_controller_core_configuration), 1);

	if (NULL == configuration)
	{
		return NYX_ERROR_OUT_OF_MEMORY;
	}

	configuration->final = false;

	/* common settings */
	switch (effect_type)
	{
		case NYX_LED_CONTROLLER_EFFECT_LED_DOUBLE_PULSE:
			configuration->pulse_ramp = 150;
			configuration->pulse_duration = 100;
			configuration->pulse_delay = 100;
			configuration->repeat_delay = 3000;
			configuration->repeat = 1;
			break;

		case NYX_LED_CONTROLLER_EFFECT_LED_FADE:
			configuration->center_fade_in = 200;
			configuration->center_fade_out = 300;
			configuration->side_fade_in = 200;
			configuration->side_fade_out = 600;
			break;

		case NYX_LED_CONTROLLER_EFFECT_FULL_FADE:
			configuration->first_in = 100;
			configuration->first_out = 500;
			configuration->second_in = 100;
			configuration->second_out = 400;
			configuration->third_out = 300;
			configuration->direction = NYX_LED_CONTROLLER_DIRECTION_LEFT;
			break;

		case NYX_LED_CONTROLLER_EFFECT_LED_PULSATE:
			configuration->start_delay = 0;
			configuration->fade_in = 1500;
			configuration->fade_out = 1500;
			configuration->duration = 200;
			configuration->repeat_delay = 4000;
			configuration->repeat = 1;
			break;

		default:
			break;

	}

	*handle_ptr = (nyx_led_controller_core_configuration_handle_t)configuration;

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_led_controller_core_configuration_set_param(
    nyx_led_controller_core_configuration_handle_t handle,
    nyx_led_controller_parameter_type_t param, int32_t new_value)
{
	nyx_led_controller_core_configuration *configuration =
	    (nyx_led_controller_core_configuration *) handle;


	switch (param)
	{
		case NYX_LED_CONTROLLER_CORE_EFFECT_BRIGHTNESS:
			configuration->brightness = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_IN:
			configuration->center_fade_in = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_OUT:
			configuration->center_fade_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_IN:
			configuration->side_fade_in = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_OUT:
			configuration->side_fade_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_IN:
			configuration->fade_in = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT:
			configuration->fade_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_START_DELAY:
			configuration->start_delay = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT_DELAY:
			configuration->fade_out_delay = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_DURATION:
			configuration->duration = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_RAMP:
			configuration->pulse_ramp = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DURATION:
			configuration->pulse_duration = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DELAY:
			configuration->pulse_delay = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT:
			configuration->repeat = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT_DELAY:
			configuration->repeat_delay = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_IN:
			configuration->first_in = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_OUT:
			configuration->first_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_IN:
			configuration->second_in = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_OUT:
			configuration->second_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_THIRD_OUT:
			configuration->third_out = new_value;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_DIRECTION:
			configuration->direction = new_value;
			break;

		default:
			break;
	}

	return NYX_ERROR_NONE;
}


nyx_error_t nyx_led_controller_core_configuration_get_param(
    nyx_led_controller_core_configuration_handle_t handle,
    nyx_led_controller_parameter_type_t param, int32_t *value)
{
	nyx_led_controller_core_configuration *configuration =
	    (nyx_led_controller_core_configuration *) handle;

	switch (param)
	{
		case NYX_LED_CONTROLLER_CORE_EFFECT_BRIGHTNESS:
			*value = configuration->brightness;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_IN:
			*value = configuration->center_fade_in;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_CENTER_FADE_OUT:
			*value = configuration->center_fade_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_IN:
			*value = configuration->side_fade_in;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SIDE_FADE_OUT:
			*value = configuration->side_fade_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_IN:
			*value = configuration->fade_in;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT:
			*value = configuration->fade_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_START_DELAY:
			*value = configuration->start_delay;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FADE_OUT_DELAY:
			*value = configuration->fade_out_delay;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_DURATION:
			*value = configuration->duration;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_RAMP:
			*value = configuration->pulse_ramp;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DURATION:
			*value = configuration->pulse_duration;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_PULSE_DELAY:
			*value = configuration->pulse_delay;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT:
			*value = configuration->repeat;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_REPEAT_DELAY:
			*value = configuration->repeat_delay;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_IN:
			*value = configuration->first_in;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_FIRST_OUT:
			*value = configuration->first_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_IN:
			*value = configuration->second_in;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_SECOND_OUT:
			*value = configuration->second_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_THIRD_OUT:
			*value = configuration->third_out;
			break;

		case NYX_LED_CONTROLLER_CORE_EFFECT_DIRECTION:
			*value = configuration->direction;
			break;

		default:
			break;
	}

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_led_controller_core_configuration_finalize(
    nyx_led_controller_core_configuration_handle_t handle)
{

	nyx_led_controller_core_configuration *configuration =
	    (nyx_led_controller_core_configuration *) handle;
	configuration->final = true;

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_led_controller_core_configuration_is_finalized(
    nyx_led_controller_core_configuration_handle_t handle, bool *value_out_ptr)
{
	nyx_led_controller_core_configuration *configuration =
	    (nyx_led_controller_core_configuration *) handle;
	*value_out_ptr = configuration->final;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_led_controller_core_configuration_release(
    nyx_led_controller_core_configuration_handle_t handle)
{
	free(handle);
	return NYX_ERROR_NONE;
}
