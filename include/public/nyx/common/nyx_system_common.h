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
 * @file nyx_system_common.h
 *
 */


#ifndef _NYX_SYSTEM_COMMON_H_
#define _NYX_SYSTEM_COMMON_H_

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_system_public System
* @ingroup nyx_public
* @{
*/

/**
 * Shutdown/Reboot type.
 */
typedef enum {
	NYX_SYSTEM_NORMAL_SHUTDOWN = 0,
	NYX_SYSTEM_EMERG_SHUTDOWN,
	NYX_SYSTEM_TEST_SHUTDOWN,
}
nyx_system_shutdown_type_t;

/**
 * Erase types
 */
typedef enum
{
    NYX_SYSTEM_ERASE_VAR = 0,       // Erase all downloaded applications, and the
    // settings and data of all applications
    // (including the browser cache, and those
    // found under /home)
    NYX_SYSTEM_ERASE_ALL,           // Perform the equivalent of a factory reset
    NYX_SYSTEM_ERASE_MEDIA,         // Erase all user-created files, typically media files.
    NYX_SYSTEM_WIPE,                // Can be a secure wipe.
    NYX_SYSTEM_TEST_ERASE,          // Used for testing the API. Does not erase anything.
    NYX_SYSTEM_ERASE_DEVELOPER      // Erase developer-mode related files.
} nyx_system_erase_type_t;

/**
 * Qos profile structure
 * (Any field set to -1 will mean that field is not applicable)
 */

typedef struct nyx_qos_profile
{
	uint32_t floor_freq;            /**< Floor (min) frequency */
	int32_t min_cpus;           /**< Min. number of cpus required */
} nyx_qos_profile_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SYSTEM_COMMON_H_ */

