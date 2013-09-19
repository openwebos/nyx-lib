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
 * @file nyx_async.c
 *
 * @brief nyx async implementation
 *
 *******************************************************************************
 */

#include <pthread.h>
#include <stdlib.h>

#include <nyx/nyx_client.h>
#include <nyx/nyx_module.h>

struct callback_data
{
	nyx_device_t *device_ptr;
	nyx_device_callback_function_t callback;
	nyx_callback_status_t status;
	void *context;
};

static void *callback_thread(void *ptr)
{
	struct callback_data *d = (struct callback_data *)ptr;

	d->callback(d->device_ptr, d->status, d->context);

	free(ptr);
	return NULL;
}

nyx_error_t nyx_utils_async_callback(nyx_device_t *device_in_ptr,
                                     nyx_device_callback_function_t callback, nyx_callback_status_t status,
                                     void *context)
{
	if (NULL == device_in_ptr)
	{
		nyx_warn("%s: device pointer is null, no device to use in call", __FUNCTION__);
		return NYX_ERROR_INVALID_VALUE;
	}

	if (NULL == callback)
	{
		nyx_warn("%s: callback pointer is null, no callback to call", __FUNCTION__);
		return NYX_ERROR_INVALID_VALUE;
	}

	struct sched_param param;

	pthread_attr_t thread_attr;

	pthread_attr_init(&thread_attr);

	pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);

	pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);

	pthread_attr_setinheritsched(&thread_attr, PTHREAD_EXPLICIT_SCHED);

	param.sched_priority = sched_get_priority_max(SCHED_OTHER);

	pthread_attr_setschedparam(&thread_attr, &param);

	if (pthread_attr_setstacksize(&thread_attr, 65536))
	{
		nyx_error(
		    "%s: Could not set thread stack size for display_brightness_thread.",
		    __FUNCTION__);
		return NYX_ERROR_GENERIC;
	}

	pthread_t thread;
	struct callback_data *d = (struct callback_data *)calloc(sizeof(
	                              struct callback_data), 1);

	d->device_ptr = device_in_ptr;
	d->callback = callback;
	d->status = status;
	d->context = context;

	if (pthread_create(&thread, &thread_attr, callback_thread, d))
	{
		nyx_error(
		    "%s: Could not set thread stack size for display_brightness_thread.",
		    __FUNCTION__);
		free(d);
		return NYX_ERROR_GENERIC;
	}

	return NYX_ERROR_NONE;
}
