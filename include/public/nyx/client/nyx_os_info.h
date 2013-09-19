/* @@@LICENSE
*
*      Copyright (c) 2013 LG Electronics
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
 * @file nyx_os_info.h
 *
 */

/**
 * @brief Nyx's public API for accessing OS info.
 *
 */

#ifndef _NYX_OS_INFO_H_
#define _NYX_OS_INFO_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_os_info_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_os_info_public OS Info
* @ingroup nyx_public
* @{
*/

/**
 * @brief   Get the os information.
 *
 * @param[in]   handle - handle to the device
 * @param[in]   type - type of information to retrieve
 *
 * @param[out]  val - location into which the pointer to the string information
 *              is copied; it will always be NUL-terminated
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 *   - NYX_ERROR_INVALID_HANDLE if given handle is NULL
 *   - NYX_ERROR_NOT_IMPLEMENTED if query for given 'type' is not implemented
 *   - NYX_ERROR_INVALID_VALUE if 'type' is not valid
 *   - NYX_ERROR_DEVICE_UNAVAILABLE if value or device for given 'type' is not available

 */
NYX_API_EXPORT nyx_error_t nyx_os_info_query(nyx_device_handle_t handle,
        nyx_os_info_query_t type, const char **val);

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* _NYX_OS_INFO_H_ */
