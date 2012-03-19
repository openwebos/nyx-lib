# @@@LICENSE
#
#      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# LICENSE@@@

include(${NYX_COMPONENT_UTILS})

add_nyx_source(
	nyx_battery_impl.c
	nyx_bluetooth_input_detect_impl.c
	nyx_charger_impl.c
	nyx_device_impl.c
	nyx_device_info_impl.c
	nyx_display_impl.c
	nyx_firmware_update_impl.c
	nyx_haptics_impl.c
	nyx_keys_impl.c
	nyx_led_impl.c
	nyx_led_controller_impl.c
	nyx_led_controller_core_configuration_impl.c
	nyx_system_impl.c
	nyx_touchpanel_impl.c
)

add_nyx_source(
    nyx_sensor_als_impl.c
    nyx_sensor_acceleration_impl.c
    nyx_sensor_angular_velocity_impl.c
    nyx_sensor_bearing_impl.c
    nyx_sensor_gravity_impl.c
    nyx_sensor_linear_acceleration_impl.c
    nyx_sensor_magnetic_field_impl.c
    nyx_sensor_orientation_impl.c
    nyx_sensor_proximity_impl.c
    nyx_sensor_rotation_impl.c
    nyx_sensor_shake_impl.c
)
