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
 * @file nyx_bluetooth_input_detect_common.h
 *
 */

#ifndef _NYX_BLUETOOTH_INPUT_DETECT_COMMON_H_
#define _NYX_BLUETOOTH_INPUT_DETECT_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_bluetooth_input_detect_public Bluetooth Input Detection
* @ingroup nyx_public
* @{
*/

/**
 * This type is an enum describing the type of the bluetooth_input_detect event.
 */
typedef enum {
	NYX_BLUETOOTH_INPUT_DETECT_EVENT_UNDEFINED =
	    0,     /**< value NYX_BLUETOOTH_INPUT_DETECT_EVENT_UNDEFINED. */
	    NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_ID_ADD,     /**< value NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_ID_ADD. */
	    NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_ID_REMOVE,  /**< value NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_ID_REMOVE. */
	    NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_KEYBOARD_TYPE,  /**< value NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_KEYBOARD_TYPE. */
	    NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_COUNTRY,    /**< value NYX_BLUETOOTH_INPUT_DETECT_EVENT_DEVICE_COUNTRY. */

}
nyx_bluetooth_input_detect_event_type_t;

typedef struct
{
	nyx_bluetooth_input_detect_event_type_t event_type;
	int32_t value;

} nyx_bluetooth_input_detect_event_item_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_BLUETOOTH_INPUT_DETECT_COMMON_H_ */
