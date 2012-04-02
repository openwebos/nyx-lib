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
 * @file nyx_device_info_common.h
 *
 */

#ifndef _NYX_DEVICE_INFO_COMMON_H_
#define _NYX_DEVICE_INFO_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_device_info_public Device Info
* @ingroup nyx_public
* @{
*/

typedef enum {
	NYX_DEVICE_INFO_START = 0,
	NYX_DEVICE_INFO_BATT_CH,
	NYX_DEVICE_INFO_BATT_RSP,
	NYX_DEVICE_INFO_BOARD_TYPE,
	NYX_DEVICE_INFO_BT_ADDR,
	NYX_DEVICE_INFO_CARRIER,
	NYX_DEVICE_INFO_DEVICE_NAME,
	NYX_DEVICE_INFO_DM_CL_AUTH_NAME,
	NYX_DEVICE_INFO_DM_CL_AUTH_PW,
	NYX_DEVICE_INFO_DM_CL_NONCE,
	NYX_DEVICE_INFO_DM_SETS,
	NYX_DEVICE_INFO_DM_SVR_AUTH_PW,
	NYX_DEVICE_INFO_DM_SVR_NONCE,
	NYX_DEVICE_INFO_HARDWARE_REVISION,
	NYX_DEVICE_INFO_INSTALLER,
	NYX_DEVICE_INFO_KEYBOARD_TYPE,
	NYX_DEVICE_INFO_LAST_RESET_TYPE,
	NYX_DEVICE_INFO_MODEM_PRESENT,
	NYX_DEVICE_INFO_NDUID,
	NYX_DEVICE_INFO_PART_NUMBER,
	NYX_DEVICE_INFO_PRODUCT_ID,
	NYX_DEVICE_INFO_PRODUCT_SKU,
	NYX_DEVICE_INFO_PRODUCTION_NAME,
	NYX_DEVICE_INFO_RADIO_TYPE,
	NYX_DEVICE_INFO_RAM_SIZE,
	NYX_DEVICE_INFO_SERIAL_NUMBER,
	NYX_DEVICE_INFO_STORAGE_FREE,
	NYX_DEVICE_INFO_STORAGE_SIZE,
	NYX_DEVICE_INFO_WIFI_ADDR,
	NYX_DEVICE_INFO_END
} nyx_device_info_type_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INFO_COMMON_H_ */
