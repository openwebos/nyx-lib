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
 * @file nyx_charger_common.h
 *
 */


#ifndef _NYX_CHARGER_COMMON_H_
#define _NYX_CHARGER_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_charger_public Charging
* @ingroup nyx_public
* @{
*/


/**
 * Charger types connected to the system
 */
#define NYX_CHARGER_PC_CONNECTED    1
#define NYX_CHARGER_WALL_CONNECTED  2
#define NYX_CHARGER_INDUCTIVE_CONNECTED 4
#define NYX_CHARGER_DIRECT_CONNECTED    8

/**
 * Charger types powering the system
 */

#define NYX_CHARGER_USB_POWERED     1
#define NYX_CHARGER_INDUCTIVE_POWERED   2
#define NYX_CHARGER_DIRECT_POWERED  4

#define NYX_DOCK_SERIAL_NUMBER_LEN  32

/**
 * Struct to get charger status
 */

typedef struct nyx_charger_status
{
	int32_t charger_max_current;        /** Max current that can be drawn from any charger connected*/
	int32_t connected;          /** ORing of all charger types connected */
	int32_t powered;            /** ORing of all charger types powering the device */
	bool is_charging;           /** True if device is being charged from a charger with sufficient capacity */
	char dock_serial_number[NYX_DOCK_SERIAL_NUMBER_LEN]; /** Serial number of dock (if connected) */
} nyx_charger_status_t;



#define NYX_NO_NEW_EVENT 0          /** No new event generated */
#define NYX_CHARGER_CONNECTED 1         /** Charge source present */
#define NYX_CHARGER_DISCONNECTED 2      /** No charge source present */
#define NYX_CHARGER_FAULT   4       /** Some charging fault detected */
#define NYX_CHARGE_COMPLETE 8       /** Charging completed */
#define NYX_CHARGE_RESTART  16      /** Restart charging */
#define NYX_BATTERY_PRESENT 32      /** Battery is present */
#define NYX_BATTERY_ABSENT  64      /** Battery is removed */
#define NYX_BATTERY_CRITICAL_VOLTAGE 128    /** Battery voltage below threshold */
#define NYX_BATTERY_TEMPERATURE_LIMIT 256   /** Battery temperature below/above limits */


typedef int32_t nyx_charger_event_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_CHARGER_COMMON_H_ */
