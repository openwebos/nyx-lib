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
 * @file nyx_touchpanel_impl.c
 *
 * @brief implementation of NYX's public API for accessing touchpanel
 * device and events it generates.
 *
 *******************************************************************************
 */
#include "nyx_touchpanel_impl.h"

nyx_error_t nyx_touchpanel_event_get_type(nyx_event_handle_t handle,
        nyx_touchpanel_event_type_t *type_out_ptr)
{
	nyx_event_t *e = (nyx_event_t *)handle;
	CHECK_EVENT(e);
	CHECK_EVENT_TYPE(e, NYX_EVENT_TOUCHPANEL);

	nyx_event_touchpanel_t *a = (nyx_event_touchpanel_t *)e;
	*type_out_ptr = a->type;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_touchpanel_event_get_touches(nyx_event_handle_t handle,
        nyx_touchpanel_event_item_t **touches_out_ptr,
        int32_t *count_out_ptr)
{
	nyx_event_t *e = (nyx_event_t *)handle;
	CHECK_EVENT(e);
	CHECK_EVENT_TYPE(e, NYX_EVENT_TOUCHPANEL);

	nyx_event_touchpanel_t *a = (nyx_event_touchpanel_t *)e;

	*touches_out_ptr = a->item_array;
	*count_out_ptr = a->item_count;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_touchpanel_set_active_scan_rate(nyx_device_handle_t handle,
        uint32_t active_scan_rate_in)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_scan_rate_function_t f = LOOKUP_METHOD(d,
	                                 NYX_TOUCHPANEL_SET_ACTIVE_SCAN_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, active_scan_rate_in);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_touchpanel_get_active_scan_rate(nyx_device_handle_t handle,
        uint32_t *active_scan_rate_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_scan_rate_function_t f = LOOKUP_METHOD(d,
	                                 NYX_TOUCHPANEL_GET_ACTIVE_SCAN_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, active_scan_rate_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_touchpanel_set_idle_scan_rate(nyx_device_handle_t handle,
        uint32_t idle_scan_rate_in)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_scan_rate_function_t f = LOOKUP_METHOD(d,
	                                 NYX_TOUCHPANEL_SET_IDLE_SCAN_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, idle_scan_rate_in);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_touchpanel_get_idle_scan_rate(nyx_device_handle_t handle,
        uint32_t *idle_scan_rate_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_scan_rate_function_t f = LOOKUP_METHOD(d,
	                                 NYX_TOUCHPANEL_GET_IDLE_SCAN_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, idle_scan_rate_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_touchpanel_set_mode(nyx_device_handle_t handle,
                                    int32_t mode_mask)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_int_function_t f = LOOKUP_METHOD(d,
	                           NYX_TOUCHPANEL_SET_MODE_MODULE_METHOD);

	if (f)
	{
		return f(d, mode_mask);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_touchpanel_get_mode(nyx_device_handle_t handle,
                                    int32_t *mode_mask_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_int_function_t f = LOOKUP_METHOD(d,
	                           NYX_TOUCHPANEL_GET_MODE_MODULE_METHOD);

	if (f)
	{
		return f(d, mode_mask_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}



