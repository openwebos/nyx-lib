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
 * @file nyx_error.h
 *
 */

/**
 * @brief Nyx's public error interface.
 *
 */

#ifndef _NYX_ERROR_H_
#define _NYX_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_error_public Errors
* @ingroup nyx_public
* @{
*/


/**
 * Error codes returned from Nyx API functions.
 */
typedef enum {
	NYX_ERROR_NONE,             /**< Operation successful */
	NYX_ERROR_INVALID_HANDLE,       /**< Invalid handle passed to an API function */
	NYX_ERROR_WRONG_DEVICE_TYPE,        /**< Operation not defined for the supplied device */
	NYX_ERROR_DEVICE_NOT_EXIST,     /**< Device does not exist */
	NYX_ERROR_TOO_MANY_OPENS,       /**< Reached maximum opens allowed on device */
	NYX_ERROR_OUT_OF_MEMORY,        /**< Out of memory */
	NYX_ERROR_DEVICE_UNAVAILABLE,       /**< Device not present OR Connection to device not available */
	NYX_ERROR_UNSUPPORTED_DEVICE_TYPE,  /**< No support for this device type currently */
	NYX_ERROR_INVALID_VALUE,        /**< Value passed to an API function is not valid */
	NYX_ERROR_NOT_IMPLEMENTED,      /**< The method/function has not been implemented by module */
	NYX_ERROR_INVALID_EVENT_TYPE,       /**< Event is of a wrong type for this operation */
	NYX_ERROR_INVALID_OPERATION,        /**< This operation cannot be performed at this time */
	NYX_ERROR_INVALID_FILE_ACCESS,      /**< The requested access to the file is not allowed >**/
	NYX_ERROR_VALUE_OUT_OF_RANGE,       /**< The resulting value was out of range >**/
	NYX_ERROR_NOT_FOUND,            /**< Could not find the requested value >**/
	NYX_ERROR_GENERIC,          /**< Generic NYX_LOG_ERROR */
	NYX_ERROR_ALREADY_UP_TO_DATE,       /**< Firmware is already up-to-date */
	NYX_ERROR_BAD_CHECKSUM,         /**< Bad checksum */
	NYX_ERROR_INCOMPATIBLE_LIBRARY,     /**< The available nyx-lib is incompatible with the ABI the caller or module expects */
}
nyx_error_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_ERROR_H_ */
