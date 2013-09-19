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
 * @file nyx_mass_storage_mode_common.h
 *
 */


#ifndef _NYX_MASS_STORAGE_MODE_COMMON_H_
#define _NYX_MASS_STORAGE_MODE_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_mass_storage_mode_public Mass Storage Mode
* @ingroup nyx_public
* @{
*/

/**
 * Nyx Mass Storage Mode status codes
 */
#define NYX_MASS_STORAGE_MODE_PARTITION_MOUNTED  1  /**</media/internal partition is mounted */
#define NYX_MASS_STORAGE_MODE_DRIVER_AVAILABLE   2  /**< Mass Storage Mode driver is available */
#define NYX_MASS_STORAGE_MODE_HOST_CONNECTED     4  /**< Device is connected to a host */
#define NYX_MASS_STORAGE_MODE_MODE_ON            8  /**< Device is in Mass Storage Mode mode */

typedef int32_t nyx_mass_storage_mode_state_t;

/**
 * nyx_mass_storage_mode_set_mode action codes
 */
typedef enum
{
    NYX_MASS_STORAGE_MODE_ENABLE = 0,   /**< Enable Mass Storage Mode mode  */
    NYX_MASS_STORAGE_MODE_DISABLE,          /**< Disable Mass Storage Mode mode */
    NYX_MASS_STORAGE_MODE_DISABLE_AFTER_FSCK,   /**< Disable Mass Storage Mode mode after running fsck */
} nyx_mass_storage_mode_action_t;

/**
 *  nyx_mass_storage_mode_set_mode return codes
 */
typedef enum
{
    NYX_MASS_STORAGE_MODE_SUCCESS = 0,      /**< Mass Storage Mode entry/exit success */
    NYX_MASS_STORAGE_MODE_DRIVER_UNAVAILABLE,   /**< Mass Storage Mode driver is unavailable */
    NYX_MASS_STORAGE_MODE_HOST_NOT_CONNECTED,   /**< Device is not connected to host */
    NYX_MASS_STORAGE_MODE_UNMOUNT_FAILURE,      /**< Failed to unmount partition */
    NYX_MASS_STORAGE_MODE_MOUNT_FAILURE,        /**< Failed to mount partition */
    NYX_MASS_STORAGE_MODE_FSCK_PROBLEM,     /**< Fsck found issues*/
    NYX_MASS_STORAGE_MODE_PARTITION_REFORMATTED,    /**< Reformatted partition */
    NYX_MASS_STORAGE_MODE_PARTITION_REFORMATTED_FSCK_PROBLEM,   /**< Reformatted partition,also fsck found problem */
    NYX_MASS_STORAGE_MODE_MOUNT_FAILURE_AFTER_REFORMAT, /**< Failed to mount partition even after reformat */
} nyx_mass_storage_mode_return_code_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_MASS_STORAGE_MODE_COMMON_H_ */
