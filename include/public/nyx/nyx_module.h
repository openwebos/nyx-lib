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
 * @file nyx_module.h
 *
 */

#ifndef _NYX_MODULE_H_
#define _NYX_MODULE_H_

#include <nyx/common/nyx_version.h>
#include <nyx/common/nyx_macros.h>
#include <nyx/common/nyx_error.h>
#include <nyx/common/nyx_event.h>
#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_core.h>

#include <nyx/common/nyx_battery_common.h>
#include <nyx/common/nyx_bluetooth_input_detect_common.h>

#include <nyx/common/nyx_battery_common.h>
#include <nyx/common/nyx_bluetooth_input_detect_common.h>
#include <nyx/common/nyx_charger_common.h>
#include <nyx/common/nyx_device_info_common.h>
#include <nyx/common/nyx_os_info_common.h>

#include <nyx/common/nyx_display_common.h>
#include <nyx/common/nyx_firmware_update_common.h>
#include <nyx/common/nyx_haptics_common.h>
#include <nyx/common/nyx_keys_common.h>
#include <nyx/common/nyx_led_controller_common.h>
#include <nyx/common/nyx_led_controller_core_configuration_common.h>
#include <nyx/common/nyx_sensor_acceleration_common.h>
#include <nyx/common/nyx_sensor_angular_velocity_common.h>
#include <nyx/common/nyx_sensor_bearing_common.h>
#include <nyx/common/nyx_sensor_gravity_common.h>
#include <nyx/common/nyx_sensor_linear_acceleration_common.h>
#include <nyx/common/nyx_sensor_magnetic_field_common.h>
#include <nyx/common/nyx_sensor_orientation_common.h>
#include <nyx/common/nyx_sensor_rotation_common.h>
#include <nyx/common/nyx_sensor_shake_common.h>
#include <nyx/common/nyx_system_common.h>
#include <nyx/common/nyx_mass_storage_mode_common.h>
#include <nyx/common/nyx_touchpanel_common.h>
#include <nyx/common/nyx_security_common.h>

#include <nyx/module/nyx_log.h>
#include <nyx/module/nyx_device_internal.h>
#include <nyx/module/nyx_module_internal.h>

#endif /* _NYX_MODULE_H_ */
