/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
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

/**
 * @brief	Get the hardware identification number.
 *      This helps in identifying the hardware type of the device in use
 *      from among the different available types.
 *
 * @param[in] 	handle - handle to the device
 * @param[out]	hw_id_out_ptr - hardware type id 
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_info_get_hardware_id(nyx_device_handle_t handle, int32_t* hw_id_out_ptr);

/**
 * @brief	Get the device information.
 *
 * @param[in] 	handle - handle to the device
 * @param[in] 	type - type of information to retrieve
 *
 * @param[out]	dest - location into which the string information is copied;
 *              it will always be NUL-terminated
 *
 * @param[in]	dest_len - length of destination string (non-zero)
 *
 * @return error code 
 *   - NYX_ERROR_NONE if operation is successful
 *   - NYX_ERROR_VALUE_OUT_OF_RANGE if 'dest_len' is too small to hold the
 *     return value, including a terminating NUL.
 */
NYX_API_EXPORT nyx_error_t nyx_device_info_get_info(nyx_device_handle_t handle, nyx_device_info_type_t type, char* dest, size_t dest_len);


/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INFO_H_ */
