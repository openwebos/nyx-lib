/* @@@LICENSE
*
*      Copyright (c) 2013-2014 LG Electronics
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
 * @file nyx_os_info_common.h
 *
 */

#ifndef _NYX_OS_INFO_COMMON_H_
#define _NYX_OS_INFO_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_os_info_public OS Info
* @ingroup nyx_public
* @{
*/

typedef enum {
	NYX_OS_INFO_CORE_OS_NAME,
	NYX_OS_INFO_CORE_OS_RELEASE,
	NYX_OS_INFO_CORE_OS_RELEASE_CODENAME,

	NYX_OS_INFO_CORE_OS_KERNEL_VERSION,    // Implemented later
	NYX_OS_INFO_CORE_OS_KERNEL_CONFIG,     // Implemented later

	NYX_OS_INFO_WEBOS_NAME,
	NYX_OS_INFO_WEBOS_RELEASE,
	//NYX_OS_INFO_WEBOS_BUILD will be deprecated, use NYX_OS_INFO_WEBOS_BUILD_ID instead
	NYX_OS_INFO_WEBOS_BUILD,
	NYX_OS_INFO_WEBOS_BUILD_ID = NYX_OS_INFO_WEBOS_BUILD,
	NYX_OS_INFO_WEBOS_RELEASE_CODENAME,
	NYX_OS_INFO_WEBOS_IMAGENAME,
	NYX_OS_INFO_WEBOS_API_VERSION,
	NYX_OS_INFO_WEBOS_PRERELEASE,
	NYX_OS_INFO_MANUFACTURING_VERSION,
	// NYX_OS_INFO_MANUFACTURING_VERSION will be deprecated,
	// use NYX_OS_INFO_WEBOS_MANUFACTURING_VERSION instead
	NYX_OS_INFO_WEBOS_MANUFACTURING_VERSION = NYX_OS_INFO_MANUFACTURING_VERSION,
	NYX_OS_INFO_ENCRYPTION_KEY_TYPE
}
nyx_os_info_query_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_OS_INFO_COMMON_H_ */
