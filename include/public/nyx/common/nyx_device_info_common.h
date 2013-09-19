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

/**
* Enumerants for selecting an information field when calling nyx_device_info_get_info
*
* Except where indicated, all returned values are constant while a device is running
* (i.e. between reboots).
*/

typedef enum {
	NYX_DEVICE_INFO_BATT_CH,        /**< Battery challenge */
	NYX_DEVICE_INFO_BATT_RSP,       /**< Battery response */

	NYX_DEVICE_INFO_BOARD_TYPE,     /**< Board type, e.g. "topaz-3G" */
	NYX_DEVICE_INFO_BT_ADDR,        /**< Bluetooth address */

	NYX_DEVICE_INFO_DEVICE_NAME,    /**< The value of WEBOS_TARGET_MACHINE for
                                         the device, as provided by cmake-modules-webos. */

	NYX_DEVICE_INFO_HARDWARE_REVISION, /**< Revision number for the hardware */
	NYX_DEVICE_INFO_INSTALLER,      /**< Tool used to install the image */
	NYX_DEVICE_INFO_KEYBOARD_TYPE,  /**< Refers to the keyboard built into the device */
	NYX_DEVICE_INFO_LAST_RESET_TYPE, /**< Reason code for last reboot (may come from /proc/cmdline) */
	NYX_DEVICE_INFO_MODEM_PRESENT,  /**< Cellular modem built into the device: "Y" or "N" */
	NYX_DEVICE_INFO_NDUID,          /**< Unique identifier for the device */
	NYX_DEVICE_INFO_PRODUCT_ID,     /**< Internal ID code for the product line */
	NYX_DEVICE_INFO_RADIO_TYPE,     /**< Internal ID code for the radio type */
	NYX_DEVICE_INFO_RAM_SIZE,       /**< Value as specified on the product data sheet */
	NYX_DEVICE_INFO_SERIAL_NUMBER,  /**< Unique serial number for the device */
	NYX_DEVICE_INFO_STORAGE_FREE,   /**< Amount of free storage available to apps, will not be constant */
	NYX_DEVICE_INFO_STORAGE_SIZE,   /**< Value as specified on the product data sheet */
	NYX_DEVICE_INFO_WIFI_ADDR,      /**< WiFi MAC Address */
	NYX_DEVICE_INFO_HARDWARE_ID,    /**< Internal ID code for the specific MACHINE */
}
nyx_device_info_type_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INFO_COMMON_H_ */
