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

/********************************************************************************
 * @file nyx_core_impl.c
 *
 * @brief This is a part of the nyx core implementation
 ********************************************************************************/

#include <stdlib.h>
#include <pthread.h>
#include <nyx/common/nyx_error.h>
#include <nyx/module/nyx_log.h>

#include "nyx_core_impl.h"

typedef struct typeStringPair
{
	nyx_device_type_t type;
	const char *typeString;
} typeStringPair_t;

static const typeStringPair_t mapTypeToString[] =
{
	{NYX_DEVICE_GENERIC,            "Generic"},
	{NYX_DEVICE_LED,            "Led"},
	{NYX_DEVICE_TOUCHPANEL,         "Touchpanel"},
	{NYX_DEVICE_SENSOR_ACCELERATION,    "SensorAcceleration"},
	{NYX_DEVICE_SENSOR_ALS,         "SensorAls"},
	{NYX_DEVICE_SENSOR_ANGULAR_VELOCITY,    "SensorAngularVelocity"},
	{NYX_DEVICE_SENSOR_BEARING,         "SensorBearing"},
	{NYX_DEVICE_SENSOR_GRAVITY,         "SensorGravity"},
	{NYX_DEVICE_SENSOR_LINEAR_ACCELERATION, "SensorLinearAcceleration"},
	{NYX_DEVICE_SENSOR_MAGNETIC_FIELD,  "SensorMagneticField"},
	{NYX_DEVICE_SENSOR_ORIENTATION,     "SensorOrientation"},
	{NYX_DEVICE_SENSOR_PROXIMITY,       "SensorProximity"},
	{NYX_DEVICE_SENSOR_ROTATION,        "SensorRotation"},
	{NYX_DEVICE_SENSOR_SHAKE,       "SensorShake"},
	{NYX_DEVICE_KEYS,           "Keys"},
	{NYX_DEVICE_LED_CONTROLLER,         "MicroControllerLEDs"},
	{NYX_DEVICE_HAPTICS,            "Haptics"},
	{NYX_DEVICE_BLUETOOTH_INPUT_DETECT,     "BluetoothInputDetect"},
	{NYX_DEVICE_DEVICE_INFO,        "DeviceInfo"},
	{NYX_DEVICE_DISPLAY,            "Display"},
	{NYX_DEVICE_CHARGER,            "Charger"},
	{NYX_DEVICE_BATTERY,            "Battery"},
	{NYX_DEVICE_FIRMWARE_UPDATE,        "FirmwareUpdate"},
	{NYX_DEVICE_SYSTEM,             "System"},
	{NYX_DEVICE_MEMORY,         "Memory"},
	{NYX_DEVICE_MEDIA_CAMERA,       "Camera"},
	{NYX_DEVICE_MASS_STORAGE_MODE,      "MassStorageMode"},
	{NYX_DEVICE_OS_INFO,        "OSInfo"},
	{NYX_DEVICE_SECURITY,           "Security"},
};

const char *nyx_core_device_type_to_string(nyx_device_type_t type)
{
	size_t i;
	const char *name = NULL;

	for (i = 0; i < sizeof(mapTypeToString) / sizeof(mapTypeToString[0]);
	        ++i)
	{
		if (mapTypeToString[i].type == type)
		{
			name = mapTypeToString[i].typeString;
			break;
		}
	}

	return name;
}

nyx_error_t nyx_core_init()
{
	nyx_log_init();

	return NYX_ERROR_NONE;
}

nyx_error_t nyx_core_deinit(void)
{
	return NYX_ERROR_NONE;
}

