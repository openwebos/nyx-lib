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
 * @file nyx_device_impl.h
 *
 * @brief internal header file.
 *
 *******************************************************************************
 */

#ifndef _NYX_DEVICE_IMPL_H_
#define _NYX_DEVICE_IMPL_H_

#include <glib.h>
#include <nyx/nyx_client.h>
#include <nyx/nyx_module.h>

#define CHECK_DEVICE(_d) {if (0 == _d) { \
    nyx_error ("invalid handle"); \
    return NYX_ERROR_INVALID_HANDLE; \
}}
#define CHECK_DEVICE_TYPE(_d,_t) {if ((_d)->type != _t) { \
    nyx_error ("wrong device type"); \
    return NYX_ERROR_WRONG_DEVICE_TYPE; \
}}
#define CHECK_DEVICE_METHOD(_d,_method) {if (0 == _d->method_ptr[_method]) { \
    nyx_error ("method " #_method " not implemented"); \
    return NYX_ERROR_NOT_IMPLEMENTED; \
}}
/*  FIXME: This null pointer check is a workaround that averts additional
    glib error messages from the output in the case of any badly written
    test logic that passes in a null table (glib returns zero anyway in
    this same scenario) */
#define LOOKUP_METHOD(_d,_method) \
    (((GHashTable*)_d->method_hash_table == NULL) ? 0 : (g_hash_table_lookup ((GHashTable*)_d->method_hash_table, GINT_TO_POINTER(_method))))

#define CHECK_EVENT(_e) {if (0 == _e) { \
    nyx_error ("invalid handle"); \
    return NYX_ERROR_INVALID_HANDLE; \
}}
#define CHECK_EVENT_TYPE(_e,_t) {if ((_e)->type != _t) { \
    nyx_error ("wrong event type"); \
    return NYX_ERROR_WRONG_DEVICE_TYPE; \
}}
#define nyx_execute_return_function(_f,_t,_m,_h,...) \
    nyx_device_t* d = (nyx_device_t*)_h; \
    CHECK_DEVICE(d); \
    CHECK_DEVICE_TYPE(d, NYX_DEVICE_##_t); \
    nyx_##_f##_function_t _f_ptr = \
        LOOKUP_METHOD(d, NYX_##_t##_##_m##_MODULE_METHOD); \
    if(_f_ptr) \
        return _f_ptr(d, __VA_ARGS__); \
    else \
        return NYX_ERROR_NOT_IMPLEMENTED;

#endif /* _NYX_DEVICE_IMPL_H_ */
