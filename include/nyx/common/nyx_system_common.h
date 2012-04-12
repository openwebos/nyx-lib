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
	NYX_SYSTEM_NORMAL_SHUTDOWN=0,
	NYX_SYSTEM_EMERG_SHUTDOWN,
	NYX_SYSTEM_TEST_SHUTDOWN,
} nyx_system_shutdown_type_t;

/**
 * Nyx MSM status codes
 */
#define NYX_SYSTEM_MSM_PARTITION_MOUNTED  1	/**</media/internal partition is mounted */
#define NYX_SYSTEM_MSM_DRIVER_AVAILABLE   2	/**< MSM driver is available */
#define NYX_SYSTEM_MSM_HOST_CONNECTED     4	/**< Device is connected to a host */
#define NYX_SYSTEM_MSM_MODE_ON            8	/**< Device is in MSM mode */

typedef int32_t nyx_system_msm_state_t;

/**
 * Erase types
 */
typedef enum {
	NYX_SYSTEM_ERASE_VAR=0,
	NYX_SYSTEM_ERASE_ALL,
	NYX_SYSTEM_ERASE_MEDIA,
	NYX_SYSTEM_WIPE,
	NYX_SYSTEM_TEST_ERASE,
} nyx_system_erase_type_t;


/**
 * nyx_system_set_msm_mode action codes
 */
typedef enum {
	NYX_SYSTEM_MSM_ENABLE=0,		/**< Enable MSM mode	*/
	NYX_SYSTEM_MSM_DISABLE,			/**< Disable MSM mode	*/
	NYX_SYSTEM_MSM_DISABLE_AFTER_FSCK,	/**< Disable MSM mode after running fsck */
} nyx_system_msm_action_t;

/**
 *  nyx_system_set_msm_mode return codes
 */
typedef enum {
	NYX_SYSTEM_MSM_SUCCESS = 0,		/**< MSM entry/exit success */
	NYX_SYSTEM_MSM_DRIVER_UNAVAILABLE,	/**< MSM driver is unavailable */
	NYX_SYSTEM_MSM_HOST_NOT_CONNECTED,	/**< Device is not connected to host */
	NYX_SYSTEM_MSM_UNMOUNT_FAILURE,		/**< Failed to unmount partition */
	NYX_SYSTEM_MSM_MOUNT_FAILURE,		/**< Failed to mount partition */
	NYX_SYSTEM_MSM_FSCK_PROBLEM,		/**< Fsck found issues*/
	NYX_SYSTEM_MSM_PARTITION_REFORMATTED,	/**< Reformatted partition */
	NYX_SYSTEM_MSM_PARTITION_REFORMATTED_FSCK_PROBLEM,	/**< Reformatted partition,also fsck found problem */
	NYX_SYSTEM_MSM_MOUNT_FAILURE_AFTER_REFORMAT, /**< Failed to mount partition even after reformat */
} nyx_system_msm_return_code_t;


/**
 * Qos profile structure
 * (Any field set to -1 will mean that field is not applicable)
 */

typedef struct nyx_qos_profile {
	uint32_t floor_freq;			/**< Floor (min) frequency */
	int32_t min_cpus;			/**< Min. number of cpus required */
} nyx_qos_profile_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_SYSTEM_COMMON_H_ */
