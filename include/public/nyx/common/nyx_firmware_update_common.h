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
 * @file nyx_firmware_update_common.h
 *
 */


#ifndef _NYX_FIRMWARE_UPDATE_COMMON_H_
#define _NYX_FIRMWARE_UPDATE_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_firmware__update_public Firmware Update
* @ingroup nyx_public
* @brief Nyx's public firmware update API.
* @{
*/

#define NYX_FIRMWARE_VERSION_MAX_SIZE 60

struct nyx_firmware_update_iterator;
typedef struct nyx_firmware_update_iterator
		*nyx_firmware_update_iterator_handle_t;

/**
 * nyx_firmware_version_info
 *
 * Structure used to flash a new image to device.  This structure is also returned by iterating versions
 * using @ref nyx_firmware_update_get_next_available_version().  Note that either the @p version or @p uri members
 * may be NULL (but not both).  If both values are specified, then the #uri will be used and the #version string
 * ignored.
 */
struct nyx_firmware_version_info
{
	char *version;      /**< Version string of a firmware image */
	char *uri;      /**< Location of the image (typically a filename path) */
};
typedef struct nyx_firmware_version_info *nyx_firmware_version_info_handle_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_FIRMWARE_UPDATE_COMMON_H_ */
