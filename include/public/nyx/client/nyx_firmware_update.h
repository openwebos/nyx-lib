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
 * @file nyx_firmware_update.h
 *
 * @brief Nyx's public API for accessing and updating firmware on a device.
 *
 */


#ifndef _NYX_FIRMWARE_UPDATE_H_
#define _NYX_FIRMWARE_UPDATE_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_firmware_update_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_firmware__update_public Firmware Update
* @ingroup nyx_public
* @{
*/

/**
 * Query the device and return the current firmware version.
 *
 * @param[in]   handle - the device handle
 * @param[out]  version_out_ptr - firmware version on device
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_firmware_update_query_current_version(
    nyx_device_handle_t handle, char **version_out_ptr);


/**
 * Get an iterator to all firmware images that are available to flash.
 *
 * @param[in]   handle - the device handle
 * @param[out]  iterator_out_ptr - an iterator to the list of available
 *          firmware images for thedevice
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_firmware_update_get_available_versions_iterator(
    nyx_device_handle_t handle,
    nyx_firmware_update_iterator_handle_t *iterator_out_ptr);

/**
 * Get the version of the next firmware image that is available.  Note that
 * the versions are returned in reverse order, so that the latest firmware
 * version will be returned on the first call.
 *
 * @param[in]   handle - the device handle
 * @param[in]   iterator - iterator to list of available firmware images
 * @param[out]  version_out_ptr - firmware version that is available to flash
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_firmware_update_get_next_available_version(
    nyx_device_handle_t handle, nyx_firmware_update_iterator_handle_t iterator,
    nyx_firmware_version_info_handle_t *version_out_ptr);

/**
 * Release memory and any other resources associated with a specified iterator.
 *
 * @param[in]   handle - the device handle
 * @param[in]   iterator - iterator to be released
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t
nyx_firmware_update_release_available_versions_iterator(
    nyx_device_handle_t handle, nyx_firmware_update_iterator_handle_t iterator);

/**
 * Update the device's firmware to a specific version.
 * The firmware image that corresponds to the version specified will first be
 * verified.  After the image is updated, it will be verified that the firmware
 * was updated correctly.
 *
 * @param[in]   handle - the device handle
 * @param[in]   version - firmware version info of image to flash.  If NULL,
 *          then update the device to the latest available version.
 * @param[in]   force - if false, then the firmware will only be updated with
 *          a newer version; if true, firmware will be updated regardless of
 *          version (version check is skipped).
 * @param[out]  fd_out_ptr - the output from the flash command will be returned
 *          into this buffer.  If this parameter is NULL, then the output will
 *          be discarded.  If specified, then the caller is responsible for
 *          reading data from this file descriptor and closing it when finished.
 * @param[in]   done_callback - function that will be called when the flash
 *          update has ended.  If this parameter is specified, then the API call
 *          will return and run asynchronously.  If this parameter is NULL, then
 *          this routine will block until the flash update is complete.
 * @param[in]   context - An opaque pointer to user-supplied data.  This data
 *          will be passed to @p done_callback when it is called.
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_firmware_update_flash(nyx_device_handle_t handle,
        nyx_firmware_version_info_handle_t version, bool force, int32_t *fd_out_ptr,
        nyx_device_callback_function_t done_callback, void *context);


/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_FIRMWARE_UPDATE_H_ */
