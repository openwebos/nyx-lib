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
 * @file nyx_core.h
 *
 */

/**
 * @brief Nyx's public core API.
 *
 * The core API provides methods for initializing and deinitializing
 * the library. It also provides methods for querying, at run-time,
 * the version of the loaded library instance.
 *
 */

#ifndef _NYX_CORE_H_
#define _NYX_CORE_H_

#include <stdint.h>

#include <nyx/common/nyx_macros.h>
#include <nyx/common/nyx_error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_core_public Core
* @ingroup nyx_public
* @{
*/

/**
 * Initializes Nyx library.
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_init(void);

/**
 * Deinitializes Nyx library.
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_deinit(void);

/**
 * Returns Nyx's library version.
 *
 * @return pointer to string containing Nyx version
 */
NYX_API_EXPORT const char *nyx_get_library_version(void);

/**
 * @brief Returns Nyx's major API version.
 *
 * The major version is incremented whenever the Nyx ABI changes in a binary-incompatible way.
 *
 * @return integer specifying API major version
 */
NYX_API_EXPORT int32_t nyx_get_api_version_major(void);

/**
 * @brief Returns Nyx's minor API version.
 *
 * The minor version is incremented whenever the Nyx ABI changes in a binary-compatible way.
 *
 * @return integer specifying the API minor version
 */
NYX_API_EXPORT int32_t nyx_get_api_version_minor(void);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_CORE_H_ */
