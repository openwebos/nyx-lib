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
 * @file nyx_device_impl.c
 *
 * @brief implementation of NYX's public API for accessing generic
 * device and events it generates.
 *
 *******************************************************************************
 */

#include <dlfcn.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include <nyx/nyx_client.h>
#include <nyx/nyx_module.h>
#include "nyx_device_impl.h"
#include "nyx_core_impl.h"

typedef int32_t (*_nyx_module_get_api_version_major_function_t)(void);
typedef int32_t (*_nyx_module_get_api_version_minor_function_t)(void);
typedef const char *(*_nyx_module_get_name_function_t)(void);
typedef nyx_device_type_t (*_nyx_module_get_type_function_t)(void);

struct nyx_device_iterator
{
	GSList *list;
	GSList *current;
};

struct nyx_instance_data
{
	void *module_ptr;
	gchar **tokens;
	int32_t token_count;
};

static int32_t _static_scan_directory(const char *directory_str,
                                      const char *type_str, nyx_device_filter_t filter,
                                      struct nyx_device_iterator *iterator_in_out_ptr)
{
	struct dirent *dp;
	int32_t count = 0;
	int32_t prefix_length = strlen(NYX_MODULE_PREFIX);
	int32_t suffix_length = strlen(NYX_MODULE_SUFFIX);
	int32_t type_str_length = strlen(type_str);

	DIR *dir = opendir(directory_str);

	while ((dp = readdir(dir)) != NULL)
	{
		int32_t filename_str_length = strlen(dp->d_name);

		if (filename_str_length > prefix_length + type_str_length + suffix_length)
		{
			// the device id has at least one character. This is a security check.
			if (0 == strncmp(NYX_MODULE_PREFIX, dp->d_name, prefix_length))
			{
				// it starts with a prefix!
				if (0 == strncmp(type_str, dp->d_name + prefix_length, type_str_length))
				{
					// it has the right device type!
					if (0 == strncmp(NYX_MODULE_SUFFIX,
					                 dp->d_name + filename_str_length - suffix_length, suffix_length))
					{
						// we have the right suffix and prefix.
						const char *id_str = (char *)strndup(dp->d_name + prefix_length +
						                                     type_str_length, filename_str_length - prefix_length - type_str_length -
						                                     suffix_length);
						iterator_in_out_ptr->list = g_slist_prepend(iterator_in_out_ptr->list,
						                            (gpointer)id_str);
						count++;
					}
				}
			}
		}
	}

	closedir(dir);

	return count;
}

nyx_error_t nyx_device_get_iterator(nyx_device_type_t type,
                                    nyx_device_filter_t filter, nyx_device_iterator_handle_t *iterator_out_ptr)
{
	const char *type_str = nyx_core_device_type_to_string(type);

	if (NULL == type_str)
	{
		return NYX_ERROR_WRONG_DEVICE_TYPE;
	}

	struct nyx_device_iterator *i = (struct nyx_device_iterator *)calloc(sizeof(
	                                    struct nyx_device_iterator), 1);

	int32_t count = _static_scan_directory(NYX_MODULE_DIR, type_str, filter, i);

	if (NYX_FILTER_INCLUDE_MOCK_DEVICES & filter)
	{
		count += _static_scan_directory(NYX_MODULE_MOCK_DIR, type_str, filter, i);
	}

	if (count == 0)
	{
		// no devices were found! we should retrun NULL!
		*iterator_out_ptr = NULL;
		nyx_device_release_iterator(i);
		return NYX_ERROR_NONE;
	}

	i->list = g_slist_reverse(i->list);
	i->current = i->list;

	*iterator_out_ptr = i;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_device_iterator_get_next_id(nyx_device_iterator_handle_t
        iterator, nyx_device_id_t *id_out_ptr)
{
	struct nyx_device_iterator *i = (struct nyx_device_iterator *)iterator;

	if (i->current)
	{
		nyx_device_id_t d = (nyx_device_id_t)i->current->data;
		i->current = i->current->next;
		*id_out_ptr = d;
		return NYX_ERROR_NONE;
	}

	*id_out_ptr = NULL;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_device_release_iterator(nyx_device_iterator_handle_t iterator)
{
	struct nyx_device_iterator *i = (struct nyx_device_iterator *)iterator;

	if (NULL != i)
	{
		i->current = i->list;

		while (i->current)
		{
			if (i->current->data)
			{
				free(i->current->data);
			}

			i->current = i->current->next;
		}

		g_slist_free(i->list);
		free((void *)i);
	}

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_module_set_name(nyx_instance_t instance,
                                nyx_device_t *device_in_ptr, const char *name_str)
{
	device_in_ptr->name = g_strndup(name_str, 256);
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_module_set_description(nyx_instance_t instance,
                                       nyx_device_t *device_in_ptr, const char *description_str)
{
	device_in_ptr->description = g_strndup(description_str, 1024);
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_module_register_method(nyx_instance_t instance,
                                       nyx_device_t *device_in_ptr, module_method_t method, const char *symbol_str)
{
	CHECK_DEVICE(device_in_ptr);

	struct nyx_instance_data *instance_data = (struct nyx_instance_data *)instance;

	void *f = dlsym(instance_data->module_ptr, symbol_str);

	if (NULL == f)
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}

	if (NULL == device_in_ptr->method_hash_table)
	{
		device_in_ptr->method_hash_table = g_hash_table_new(g_direct_hash,
		                                   g_direct_equal);
	}

	g_hash_table_replace((GHashTable *)device_in_ptr->method_hash_table,
	                     GINT_TO_POINTER(method), f);

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_module_get_argument_count(nyx_instance_t instance,
        int32_t *argument_count_out_ptr)
{
	struct nyx_instance_data *instance_data = (struct nyx_instance_data *)instance;
	*argument_count_out_ptr = instance_data->token_count;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_module_get_argument_value(nyx_instance_t instance,
        int32_t argument_index, char **argument_value_out_ptr)
{
	struct nyx_instance_data *instance_data = (struct nyx_instance_data *)instance;

	if (argument_index >= instance_data->token_count)
	{
		return NYX_ERROR_VALUE_OUT_OF_RANGE;
	}

	if (NULL !=  instance_data->tokens)
	{
		*argument_value_out_ptr = instance_data->tokens[argument_index];
	}
	else
	{
		*argument_value_out_ptr = NULL;
	}

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_device_open(nyx_device_type_t type, nyx_device_id_t id,
                            nyx_device_handle_t *handle_out_ptr)
{
	nyx_device_t *device = NULL;
	const char *type_str = nyx_core_device_type_to_string(type);

	if (NULL == type_str)
	{
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	/*
	 * let's open the library:
	 *
	 */

	gchar **tokens = g_strsplit(id, ":", -1);

	if (NULL == tokens)
	{
		return NYX_ERROR_INVALID_VALUE;
	}

	// TODO: make sure typeStr and id do not generate overflow.
	gchar *lib_name_str = g_strdup_printf("%s/%s%s%s%s", NYX_MODULE_DIR,
	                                      NYX_MODULE_PREFIX, type_str, tokens[0], NYX_MODULE_SUFFIX);
	void *module_ptr = dlopen(lib_name_str, RTLD_NOW);
	g_free(lib_name_str);

	if (NULL == module_ptr)
	{
		lib_name_str = g_strdup_printf("%s/%s%s%s%s", NYX_MODULE_MOCK_DIR,
		                               NYX_MODULE_PREFIX, type_str, tokens[0], NYX_MODULE_SUFFIX);
		module_ptr = dlopen(lib_name_str, RTLD_NOW);
		g_free(lib_name_str);
	}

	if (NULL == module_ptr)
	{
		nyx_error("module (%s%s%s%s) does not exist", NYX_MODULE_PREFIX, type_str, id,
		          NYX_MODULE_SUFFIX);
		nyx_error("in %s", NYX_MODULE_DIR);
		nyx_error("nor in  %s", NYX_MODULE_MOCK_DIR);
		return NYX_ERROR_DEVICE_NOT_EXIST;
	}

	nyx_open_function_t open_ptr = dlsym(module_ptr, "nyx_module_open");

	if (NULL == open_ptr)
	{
		nyx_error("module does not implement \"nyx_module_open\" method");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	nyx_close_function_t close_ptr = dlsym(module_ptr, "nyx_module_close");

	if (NULL == close_ptr)
	{
		nyx_error("module does not implement \"nyx_module_close\" method");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	_nyx_module_get_api_version_major_function_t  get_version_major_ptr = dlsym(
	            module_ptr, "_nyx_module_get_api_version_major");

	if (NULL == get_version_major_ptr)
	{
		nyx_error("module was not declared with NYX_DECLARE_MODULE");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	_nyx_module_get_api_version_minor_function_t get_version_minor_ptr = dlsym(
	            module_ptr, "_nyx_module_get_api_version_minor");

	if (NULL == get_version_minor_ptr)
	{
		nyx_error("module was not declared with NYX_DECLARE_MODULE");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	_nyx_module_get_name_function_t get_name_ptr = dlsym(module_ptr,
	        "_nyx_module_get_name");

	if (NULL == get_name_ptr)
	{
		nyx_error("module was not declared with NYX_DECLARE_MODULE");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	_nyx_module_get_type_function_t get_device_type_ptr = dlsym(module_ptr,
	        "_nyx_module_get_type");

	if (NULL == get_device_type_ptr)
	{
		nyx_error("module was not declared with NYX_DECLARE_MODULE");
		dlclose(module_ptr);
		return NYX_ERROR_UNSUPPORTED_DEVICE_TYPE;
	}

	if (get_version_major_ptr() != NYX_API_VERSION_MAJOR)
	{
		nyx_error("module API version (%i) is different from the library API version (%i)",
		          get_version_major_ptr(), NYX_API_VERSION_MAJOR);
		dlclose(module_ptr);
		return NYX_ERROR_INCOMPATIBLE_LIBRARY;
	}

	struct nyx_instance_data instance;

	instance.tokens = tokens;

	instance.token_count = 0;

	if (NULL != tokens)
	{
		while (tokens[instance.token_count] != NULL)
		{
			instance.token_count++;
		}
	}

	instance.module_ptr = module_ptr;

	nyx_error_t error = open_ptr((void *)&instance, &device);

	if (NYX_ERROR_NONE != error || NULL == device)
	{
		nyx_error("open device method failed");
		dlclose(module_ptr);
		return error;
	}

	device->module_ptr = module_ptr;
	device->type       = type;
	device->open_ptr   = open_ptr;
	device->close_ptr  = close_ptr;

	g_strfreev(instance.tokens);

	/*
	 * We are done, so we can return success to the user and the device handle.
	 */
	*handle_out_ptr = (nyx_device_handle_t)device;
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_device_close(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;

	CHECK_DEVICE(d);

	/*
	 * cleanup device local members after call to close because members
	 * might be used during the close.
	 *
	 * need to setup copy from device because call to close will deallocate
	 * device (d) structure (cant access device members through pointer d)
	 */
	nyx_device_t cache;
	memcpy(&cache, d, sizeof(cache));

	nyx_error_t error = cache.close_ptr(d);

	/*
	 * do rest of the cleanup using cache
	 */

	if (NULL != cache.method_hash_table)
	{
		g_hash_table_destroy((GHashTable *)cache.method_hash_table);
	}

	g_free(cache.name);
	g_free(cache.description);

	/*
	 * We are done so, we can close the module.
	 */
	dlclose(cache.module_ptr);

	return error;
}

nyx_error_t nyx_device_set_operating_mode(nyx_device_handle_t handle,
        nyx_operating_mode_t mode)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_operating_mode_function_t f = LOOKUP_METHOD(d,
	                                      NYX_SET_OPERATING_MODE_MODULE_METHOD);

	if (f)
	{
		return f(d, mode);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_get_operating_mode(nyx_device_handle_t handle,
        nyx_operating_mode_t *mode_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_operating_mode_function_t f = LOOKUP_METHOD(d,
	                                      NYX_GET_OPERATING_MODE_MODULE_METHOD);

	if (f)
	{
		return f(d, mode_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_get_event_source(nyx_device_handle_t handle,
                                        int32_t *source_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_event_source_function_t f = LOOKUP_METHOD(d,
	                                    NYX_GET_EVENT_SOURCE_MODULE_METHOD);

	if (f)
	{
		return f(d, source_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_get_event(nyx_device_handle_t handle,
                                 nyx_event_handle_t *event_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_event_function_t f = LOOKUP_METHOD(d, NYX_GET_EVENT_MODULE_METHOD);

	if (f)
	{
		return f(d, (nyx_event_t **)event_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_release_event(nyx_device_handle_t handle,
                                     nyx_event_handle_t event_handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_release_event_function_t f = LOOKUP_METHOD(d,
	                                 NYX_RELEASE_EVENT_MODULE_METHOD);

	if (f)
	{
		return f(d, (nyx_event_t *)event_handle);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_set_report_rate(nyx_device_handle_t handle,
                                       nyx_report_rate_t rate)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_report_rate_function_t f = LOOKUP_METHOD(d,
	                                   NYX_SET_REPORT_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, rate);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_get_report_rate(nyx_device_handle_t handle,
                                       nyx_report_rate_t *rate_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_report_rate_function_t f = LOOKUP_METHOD(d,
	                                   NYX_GET_REPORT_RATE_MODULE_METHOD);

	if (f)
	{
		return f(d, rate_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_set_property(nyx_device_handle_t handle,
                                    const char *property_name_in, void *property_value_in_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_set_property_function_t f = LOOKUP_METHOD(d,
	                                NYX_SET_PROPERTY_MODULE_METHOD);

	if (f)
	{
		return f(d, property_name_in, property_value_in_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_device_get_property(nyx_device_handle_t handle,
                                    const char *property_name_in, void **property_value_out_ptr)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	nyx_get_property_function_t f = LOOKUP_METHOD(d,
	                                NYX_GET_PROPERTY_MODULE_METHOD);

	if (f)
	{
		return f(d, property_name_in, property_value_out_ptr);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}
