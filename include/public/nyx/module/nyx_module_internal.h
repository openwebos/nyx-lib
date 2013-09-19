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
 * @file nyx_module_internal.h
 *
 * @brief  Definition of the data structures and functions and function types
 * used by the NYX's internal implementation and modules implementing particular
 * device.
 *
 */

#ifndef _NYX_MODULE_INTERNAL_H_
#define _NYX_MODULE_INTERNAL_H_

#include <nyx/module/nyx_device_internal.h>
#include <nyx/module/nyx_device_haptics_internal.h>
#include <nyx/module/nyx_device_display_internal.h>

/**
 * declare the module type and name
 *
 * @param[in]   _type - device type this module implements
 * @param[in]   _name - name of the module
 *
 */

#define NYX_DECLARE_MODULE(_type, _name) \
    int32_t _nyx_module_get_api_version_major () { return NYX_API_VERSION_MAJOR; } \
    int32_t _nyx_module_get_api_version_minor () { return NYX_API_VERSION_MINOR; } \
    const char* _nyx_module_get_name () { return _name; } \
    nyx_device_type_t _nyx_module_get_type () { return _type; }

/**
 * set the name of the newly created device.
 *
 * @param[in]   instance - instance passed into nyx_open_function.
 * @param[in]   device_in_ptr - pointer to the device on which to set the name
 * @param[in]   name_str - name to set.
 *
 * @return nyx_error_t that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
nyx_error_t nyx_module_set_name(nyx_instance_t instance,
                                nyx_device_t *device_in_ptr, const char *name_str);

/**
 * set the description of the newly created device.
 *
 * @param[in]   instance - instance passed into nyx_open_function.
 * @param[in]   device_in_ptr - pointer to the device on which to set the description
 * @param[in]   description_str - description string to set on the device.
 *
 * @return nyx_error_t that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
nyx_error_t nyx_module_set_description(nyx_instance_t instance,
                                       nyx_device_t *device_in_ptr, const char *description_str);

/**
 * set the method for the newly created device.
 *
 * @param[in]   instance - instance passed into nyx_open_function.
 * @param[in]   device_in_ptr - pointer to the device on which to set the method
 * @param[in]   method - method to be set
 * @param[in]   symbol_str - symbol for the method to use.
 *
 * @return nyx_error_t that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
nyx_error_t nyx_module_register_method(nyx_instance_t instance,
                                       nyx_device_t *device_in_ptr, module_method_t method, const char *symbol_str);

/**
 * retrieves the argument count of the currently opened module.
 *
 * @param[in]   instance - instance passed into nyx_open_function.
 * @param[out]  argument_count_out_ptr - pointer to store the argument count.
 *
 * @return nyx_error_t that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
nyx_error_t nyx_module_get_argument_count(nyx_instance_t instance,
        int32_t *argument_count_out_ptr);

/**
 * retrieves the argument at the index.
 *
 * @param[in]   instance - instance passed into nyx_open_function.
 * @param[in]   argument_index - index of the argument value to get.
 * @param[out]  argument_value_out_ptr - pointer to the value of the argument.
 *
 * @return nyx_error_t that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
nyx_error_t nyx_module_get_argument_value(nyx_instance_t instance,
        int32_t argument_index, char **argument_value_out_ptr);

#endif /* _NYX_MODULE_INTERNAL_H_ */
