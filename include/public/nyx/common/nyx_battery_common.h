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
 * @file nyx_battery_common.h
 *
 */


#ifndef _NYX_BATTERY_COMMON_H_
#define _NYX_BATTERY_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_battery_public Battery
* @ingroup nyx_public
* @brief Nyx's public battery API.
* @{
*/

/**
 * Struct to get current battery readings
 */
typedef struct
{
	bool present;       /** True if the battery is present */
	bool charging;      /** True if the battery is being charged currently */
	int32_t percentage; /** Battery capacity in percentage */
	int32_t temperature;    /** In celsius */
	int32_t current;    /** In mA */
	int32_t voltage;    /** In mV */
	float capacity;     /** In mAh*/
	int32_t avg_current;    /** In mA */
	float capacity_raw; /** In mAh*/
	float capacity_full40;  /** In mAh*/
	int32_t age;
} nyx_battery_status_t;

/**
 * Battery Charging Parameters
 */
typedef struct
{
	int32_t charge_min_temp_c;      /** Temperature below which charging is turned off */
	int32_t charge_max_temp_c;      /** Temperature above which charging is turned off */
	int32_t battery_crit_max_temp;      /** Temperature above which device is shut down */
	bool skip_battery_authentication;   /** Is battery authentication required (True/False) */
} nyx_battery_ctia_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_BATTERY_COMMON_H_ */
