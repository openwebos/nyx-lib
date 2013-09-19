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
 * @file nyx_mass_storage_mode.c
 *
 * @brief nyx Mass Storage Mode file
 *
 *******************************************************************************
 */

#include "nyx_device_impl.h"
#include "nyx_core_impl.h"
#include <nyx/nyx_module.h>

nyx_error_t nyx_mass_storage_mode_set_mode(nyx_device_handle_t handle,
        nyx_mass_storage_mode_action_t action, nyx_mass_storage_mode_return_code_t *ret)
{
	nyx_execute_return_function(mass_storage_mode_set_mode, MASS_STORAGE_MODE,
	                            SET_MODE, handle, action, ret);
}

nyx_error_t nyx_mass_storage_mode_get_state(nyx_device_handle_t handle,
        nyx_mass_storage_mode_state_t *state)
{
	nyx_execute_return_function(mass_storage_mode_get_state, MASS_STORAGE_MODE,
	                            GET_STATE, handle, state);
}

nyx_error_t nyx_mass_storage_mode_register_change_callback(
    nyx_device_handle_t handle, nyx_device_callback_function_t callback_func,
    void *context)
{
	nyx_execute_return_function(mass_storage_mode_register_change_callback,
	                            MASS_STORAGE_MODE, REGISTER_CHANGE_CALLBACK, handle, callback_func, context);
}

