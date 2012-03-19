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
	nyx_device_info_start = 0,
	nyx_device_info_batt_ch,
	nyx_device_info_batt_rsp,
	nyx_device_info_board_type,
	nyx_device_info_bt_addr,
	nyx_device_info_carrier,
	nyx_device_info_device_name,
	nyx_device_info_dm_cl_auth_name,
	nyx_device_info_dm_cl_auth_pw,
	nyx_device_info_dm_cl_nonce,
	nyx_device_info_dm_sets,
	nyx_device_info_dm_svr_auth_pw,
	nyx_device_info_dm_svr_nonce,
	nyx_device_info_hardware_revision,
	nyx_device_info_installer,
	nyx_device_info_keyboard_type,
	nyx_device_info_last_reset_type,
	nyx_device_info_modem_present,
	nyx_device_info_nduid,
	nyx_device_info_part_number,
	nyx_device_info_product_id,
	nyx_device_info_product_sku,
	nyx_device_info_production_name,
	nyx_device_info_radio_type,
	nyx_device_info_ram_size,
	nyx_device_info_serial_number,
	nyx_device_info_storage_free,
	nyx_device_info_storage_size,
	nyx_device_info_wifi_addr,
	nyx_device_info_end
} nyx_device_info_type_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INFO_COMMON_H_ */
