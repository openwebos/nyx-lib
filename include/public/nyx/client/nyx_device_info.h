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
 * @file nyx_device_info.h
 *
 */

/**
 * @brief Nyx's public API for accessing device info.
 *
 */

#ifndef _NYX_DEVICE_INFO_H_
#define _NYX_DEVICE_INFO_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_device_info_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_device_info_public Device Info
* @ingroup nyx_public
* @{
*/

/* nyx_device_info_get_info is deprecated */
/**
 * @deprecated  Use nyx_device_info_query instead.
 * @brief   Get the device information.
 *
 * @param[in]   handle - handle to the device
 * @param[in]   type - type of information to retrieve
 *
 * @param[out]  dest - location into which the string information is copied;
 *              it will always be NUL-terminated
 *
 * @param[in]   dest_len - length of destination string (non-zero)
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 *   - NYX_ERROR_VALUE_OUT_OF_RANGE if 'dest_len' is too small to hold the
 *     return value, including a terminating NUL.
 */
NYX_API_EXPORT nyx_error_t nyx_device_info_get_info(nyx_device_handle_t handle,
        nyx_device_info_type_t type, char *dest, size_t dest_len);

/**
 * @brief   Query the device information.
 *
 * @param[in]   handle - handle to the device
 * @param[in]   type - type of information to retrieve
 *
 * @param[out]  dest - location into which the pointer to the string information
 *              is copied; it will always be NUL-terminated
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 *   - NYX_ERROR_INVALID_HANDLE if given handle is NULL
 *   - NYX_ERROR_NOT_IMPLEMENTED if query for given 'type' is not implemented
 *   - NYX_ERROR_INVALID_VALUE if 'type' is not valid */

NYX_API_EXPORT nyx_error_t nyx_device_info_query(nyx_device_handle_t handle,
        nyx_device_info_type_t type, const char **dest);


/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INFO_H_ */
