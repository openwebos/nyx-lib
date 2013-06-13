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
 * @file nyx_client.h
 *
 * @brief NYX's main include file that includes all the necessary include files
 * to use NYX.
 *
 */

#ifndef _NYX_CLIENT_H_
#define _NYX_CLIENT_H_

#include <stdbool.h>
#include <stdint.h>

#include <nyx/common/nyx_version.h>
#include <nyx/common/nyx_macros.h>
#include <nyx/common/nyx_error.h>
#include <nyx/common/nyx_event.h>
#include <nyx/common/nyx_device.h>

#include <nyx/common/nyx_core.h>

#include <nyx/client/nyx_bluetooth_input_detect.h>
#include <nyx/client/nyx_haptics.h>
#include <nyx/client/nyx_keys.h>
#include <nyx/client/nyx_led.h>
#include <nyx/client/nyx_led_controller.h>
#include <nyx/client/nyx_led_controller_core_configuration.h>
#include <nyx/client/nyx_touchpanel.h>
#include <nyx/client/nyx_charger.h>
#include <nyx/client/nyx_battery.h>
#include <nyx/client/nyx_firmware_update.h>
#include <nyx/client/nyx_system.h>
#include <nyx/client/nyx_mass_storage_mode.h>
#include <nyx/client/nyx_display.h>
#include <nyx/client/nyx_device_info.h>
#include <nyx/client/nyx_os_info.h>

#include <nyx/client/nyx_sensor_acceleration.h>
#include <nyx/client/nyx_sensor_als.h>
#include <nyx/client/nyx_sensor_angular_velocity.h>
#include <nyx/client/nyx_sensor_bearing.h>
#include <nyx/client/nyx_sensor_gravity.h>
#include <nyx/client/nyx_sensor_linear_acceleration.h>
#include <nyx/client/nyx_sensor_magnetic_field.h>
#include <nyx/client/nyx_sensor_orientation.h>
#include <nyx/client/nyx_sensor_proximity.h>
#include <nyx/client/nyx_sensor_rotation.h>
#include <nyx/client/nyx_sensor_shake.h>

#include <nyx/client/nyx_security.h>

#endif /* _NYX_CLIENT_H_ */
