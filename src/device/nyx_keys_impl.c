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
 * @file nyx_keys_impl.c
 *
 * @brief implementation of NYX's public API for accessing keys
 * device and events it generates.
 *
 *******************************************************************************
 */

#include "nyx_keys_impl.h"

#define EVENT_HANDLE_TO_EVENT_KEYS(handle, event_keys)   \
    nyx_event_t* e = (nyx_event_t*)handle;    \
    CHECK_EVENT(e)                            \
    CHECK_EVENT_TYPE(e, NYX_EVENT_KEYS)       \
    event_keys = (nyx_event_keys_t*) e

nyx_error_t nyx_keys_event_get_key(nyx_event_handle_t handle,
                                   int32_t *key_out_ptr)
{
	nyx_event_keys_t *keys_event;
	EVENT_HANDLE_TO_EVENT_KEYS(handle, keys_event);
	*key_out_ptr = keys_event->key;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_keys_event_get_key_type(nyx_event_handle_t handle,
                                        nyx_key_type_t *key_type_out_ptr)
{
	nyx_event_keys_t *keys_event;
	EVENT_HANDLE_TO_EVENT_KEYS(handle, keys_event);
	*key_type_out_ptr = keys_event->key_type;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_keys_event_get_key_is_press(nyx_event_handle_t handle,
        bool *key_is_press_out_ptr)
{
	nyx_event_keys_t *keys_event;
	EVENT_HANDLE_TO_EVENT_KEYS(handle, keys_event);
	*key_is_press_out_ptr = keys_event->key_is_press;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_keys_event_get_key_is_auto_repeat(nyx_event_handle_t handle,
        bool *key_is_auto_repeat_out_ptr)
{
	nyx_event_keys_t *keys_event;
	EVENT_HANDLE_TO_EVENT_KEYS(handle, keys_event);
	*key_is_auto_repeat_out_ptr = keys_event->key_is_auto_repeat;
	return NYX_ERROR_NONE;
}
