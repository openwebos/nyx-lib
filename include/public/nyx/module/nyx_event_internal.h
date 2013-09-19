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
 * @file nyx_event_internal.h
 *
 * @brief Definition of the event structures used by the NYX's internal
 * implementation and modules implementing particular device.
 *
 */

#ifndef _NYX_EVENT_INTERNAL_H_
#define _NYX_EVENT_INTERNAL_H_

#include <stdint.h>

struct nyx_event
{
	nyx_event_type_t type;
	int64_t timestamp;
	void *_device;
};
typedef struct nyx_event nyx_event_t;


typedef struct nyx_event_keys
{
	nyx_event_t _parent;

	nyx_key_type_t key_type;
	int32_t key;
	bool key_is_press;
	bool key_is_auto_repeat;

} nyx_event_keys_t;

typedef struct nyx_event_bluetooth_input_detect
{

	nyx_event_t _parent;
	nyx_bluetooth_input_detect_event_item_t item;

} nyx_event_bluetooth_input_detect_t;

typedef struct
{
	nyx_event_t _parent;
	nyx_sensor_acceleration_event_item_t item;

} nyx_event_sensor_acceleration_t;

typedef struct nyx_event_sensor_angular_velocity
{
	nyx_event_t _parent;
	nyx_sensor_angular_velocity_event_item_t item;

} nyx_event_sensor_angular_velocity_t;

typedef struct nyx_event_sensor_bearing
{
	nyx_event_t _parent;
	nyx_sensor_bearing_event_item_t item;

} nyx_event_sensor_bearing_t;

typedef struct nyx_event_sensor_gravity
{
	nyx_event_t _parent;
	nyx_sensor_gravity_event_item_t item;

} nyx_event_sensor_gravity_t;

typedef struct nyx_event_sensor_linear_acceleration
{
	nyx_event_t _parent;
	nyx_sensor_linear_acceleration_event_item_t item;

} nyx_event_sensor_linear_acceleration_t;

typedef struct nyx_event_sensor_magnetic_field
{
	nyx_event_t _parent;
	nyx_sensor_magnetic_field_event_item_t item;

} nyx_event_sensor_magnetic_field_t;

typedef struct nyx_event_sensor_orientation
{
	nyx_event_t _parent;
	nyx_sensor_orientation_event_item_t item;

} nyx_event_sensor_orientation_t;

typedef struct nyx_event_sensor_rotation
{
	nyx_event_t _parent;
	nyx_sensor_rotation_event_item_t item;

} nyx_event_sensor_rotation_t;

typedef struct nyx_event_sensor_shake
{
	nyx_event_t _parent;
	nyx_sensor_shake_event_item_t item;

} nyx_event_sensor_shake_t;

#endif /* _NYX_EVENT_INTERNAL_H_ */
