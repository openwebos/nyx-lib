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
 * @file nyx_firmware_update_impl.c
 *
 * @brief implementation of NYX's public API for accessing and updating FIRMWARE
 * device.
 *
 *******************************************************************************
 */

#include "nyx_firmware_update_impl.h"

nyx_error_t nyx_firmware_update_query_current_version(nyx_device_handle_t
        handle, char **version_out_ptr)
{
	nyx_execute_return_function(firmware_update_query_current_version,
	                            FIRMWARE_UPDATE, QUERY_CURRENT_VERSION, handle, version_out_ptr);
}

nyx_error_t nyx_firmware_update_get_available_versions_iterator(
    nyx_device_handle_t handle,
    nyx_firmware_update_iterator_handle_t *iterator_out_ptr)
{
	nyx_execute_return_function(firmware_update_get_available_versions_iterator,
	                            FIRMWARE_UPDATE, GET_AVAILABLE_VERSIONS_ITERATOR, handle, iterator_out_ptr);
}

nyx_error_t nyx_firmware_update_get_next_available_version(
    nyx_device_handle_t handle, nyx_firmware_update_iterator_handle_t iterator,
    nyx_firmware_version_info_handle_t *version_out_ptr)
{
	nyx_execute_return_function(firmware_update_get_next_available_version,
	                            FIRMWARE_UPDATE, GET_NEXT_AVAILABLE_VERSION, handle, iterator, version_out_ptr);
}

nyx_error_t nyx_firmware_update_release_available_versions_iterator(
    nyx_device_handle_t handle, nyx_firmware_update_iterator_handle_t iterator)
{
	nyx_execute_return_function(firmware_update_release_available_versions_iterator,
	                            FIRMWARE_UPDATE, RELEASE_AVAILABLE_VERSIONS_ITERATOR, handle, iterator);
}

nyx_error_t nyx_firmware_update_flash(nyx_device_handle_t handle,
                                      nyx_firmware_version_info_handle_t version, bool force, int32_t *fd_out_ptr,
                                      nyx_device_callback_function_t done_callback, void *context)
{
	nyx_execute_return_function(firmware_update_flash, FIRMWARE_UPDATE, FLASH,
	                            handle, version, force, fd_out_ptr, done_callback, context);
}

