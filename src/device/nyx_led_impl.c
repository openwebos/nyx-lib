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
 * @file nyx_led_impl.c
 *
 * @brief implementation of NYX's public API for accessing LED
 * device.
 *
 *******************************************************************************
 */

#include "nyx_led_impl.h"

nyx_error_t nyx_led_set_brightness(nyx_device_handle_t handle,
                                   int32_t brightness)
{
	nyx_execute_return_function(led_set_brightness, LED, SET_BRIGHTNESS, handle,
	                            brightness);
}

nyx_error_t nyx_led_get_brightness(nyx_device_handle_t handle,
                                   int32_t *brightness_out_ptr)
{
	nyx_execute_return_function(led_get_brightness, LED, GET_BRIGHTNESS, handle,
	                            brightness_out_ptr);
}
