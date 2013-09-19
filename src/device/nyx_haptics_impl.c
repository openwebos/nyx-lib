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
 * @file nyx_haptics_impl.c
 *
 * @brief nyx haptics implementation
 *
 *******************************************************************************
 */

#include "nyx_haptics_impl.h"

nyx_error_t nyx_haptics_vibrate(nyx_device_handle_t handle,
                                nyx_haptics_configuration_t configuration)
{
	nyx_execute_return_function(haptics_vibrate, HAPTICS, VIBRATE, handle,
	                            configuration);
}

nyx_error_t nyx_haptics_cancel(nyx_device_handle_t handle, int32_t effect_id)
{
	nyx_execute_return_function(haptics_cancel, HAPTICS, CANCEL, handle, effect_id);
}

nyx_error_t nyx_haptics_cancel_all(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_HAPTICS);
	nyx_haptics_cancel_all_function_t f_ptr = LOOKUP_METHOD(d,
	        NYX_HAPTICS_CANCEL_ALL_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_haptics_get_effect_id(nyx_device_handle_t handle,
                                      int32_t *haptics_id_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_HAPTICS);
	nyx_haptics_device_t *a = (nyx_haptics_device_t *)d;
	*haptics_id_out_ptr = a->haptic_effect_id;
	return NYX_ERROR_NONE;

}

nyx_error_t nyx_haptics_set_dampening_factor(nyx_device_handle_t handle,
        int32_t dampening_factor)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_HAPTICS);
	nyx_haptics_device_t *a = (nyx_haptics_device_t *)d;
	a->dampening_factor = dampening_factor;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_haptics_get_dampening_factor(nyx_device_handle_t handle,
        int32_t *dampening_factor_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_HAPTICS);
	nyx_haptics_device_t *a = (nyx_haptics_device_t *)d;
	*dampening_factor_out_ptr = a->dampening_factor;
	return NYX_ERROR_NONE;
}
