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

struct nyx_core {
	GMainContext* main_context;
	GMainLoop* main_loop;
	pthread_t worker;
};

static struct nyx_core nyx_core;

static void *nyx_worker_thread(void *arg)
{
	g_main_loop_run(nyx_core.main_loop);

	return NULL;
}

typedef struct typeStringPair
{
	nyx_device_type_t type;
	const char * typeString;
} typeStringPair_t;

static const typeStringPair_t mapTypeToString[] =
{
	{NYX_DEVICE_GENERIC, 			"Generic"},
	{NYX_DEVICE_LED, 			"Led"},
	{NYX_DEVICE_TOUCHPANEL, 		"Touchpanel"},
	{NYX_DEVICE_SENSOR_ACCELERATION, 	"SensorAcceleration"},
	{NYX_DEVICE_SENSOR_ALS, 		"SensorAls"},
	{NYX_DEVICE_SENSOR_ANGULAR_VELOCITY, 	"SensorAngularVelocity"},
	{NYX_DEVICE_SENSOR_BEARING, 		"SensorBearing"},
	{NYX_DEVICE_SENSOR_GRAVITY, 		"SensorGravity"},
	{NYX_DEVICE_SENSOR_LINEAR_ACCELERATION,	"SensorLinearAcceleration"},
	{NYX_DEVICE_SENSOR_MAGNETIC_FIELD, 	"SensorMagneticField"},
	{NYX_DEVICE_SENSOR_ORIENTATION, 	"SensorOrientation"},
	{NYX_DEVICE_SENSOR_PROXIMITY, 		"SensorProximity"},
	{NYX_DEVICE_SENSOR_ROTATION, 		"SensorRotation"},
	{NYX_DEVICE_SENSOR_SHAKE, 		"SensorShake"},
	{NYX_DEVICE_KEYS, 			"Keys"},
	{NYX_DEVICE_LED_CONTROLLER, 		"MicroControllerLEDs"},
	{NYX_DEVICE_HAPTICS, 			"Haptics"},
	{NYX_DEVICE_BLUETOOTH_INPUT_DETECT, 	"BluetoothInputDetect"},
	{NYX_DEVICE_DEVICE_INFO, 		"DeviceInfo"},
	{NYX_DEVICE_DISPLAY, 			"Display"},
	{NYX_DEVICE_CHARGER, 			"Charger"},
	{NYX_DEVICE_BATTERY, 			"Battery"},
	{NYX_DEVICE_FIRMWARE_UPDATE, 		"FirmwareUpdate"},
	{NYX_DEVICE_SYSTEM, 			"System"},
	{NYX_DEVICE_MEMORY,			"Memory"},
	{NYX_DEVICE_MEDIA_CAMERA, 		"Camera"}
};

const char* nyx_core_device_type_to_string(nyx_device_type_t type)
{
	size_t i;
	const char *name = NULL;

	for (i = 0; i < sizeof(mapTypeToString) / sizeof(mapTypeToString[0]);
			++i) {
		if (mapTypeToString[i].type == type) {
			name = mapTypeToString[i].typeString;
			break;
		}
	}

	return name;
}

GMainLoop* nyx_core_get_mainloop()
{
	return nyx_core.main_loop;
}

GMainContext* nyx_core_get_maincontext()
{
	return nyx_core.main_context;
}

nyx_error_t nyx_core_init()
{
	nyx_log_init();

	nyx_core.main_context = g_main_context_new();
	if (NULL == nyx_core.main_context) {
		nyx_error( "Unable to create GmainContext\n");
		return NYX_ERROR_GENERIC;
	}

	nyx_core.main_loop = g_main_loop_new(nyx_core.main_context, FALSE);
	if (NULL == nyx_core.main_loop) {
		nyx_error("Unable to create GmainLoop\n");
		return NYX_ERROR_GENERIC;
	}

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
		nyx_error("Unable to create pthread attribute\n");
		return NYX_ERROR_GENERIC;
	}

	if (pthread_create(&nyx_core.worker, &attr, nyx_worker_thread, 0)
			!= 0) {
		nyx_error("Unable to create worker thread\n");
		return NYX_ERROR_GENERIC;
	}
	return NYX_ERROR_NONE;
}

nyx_error_t nyx_core_deinit(void)
{
	g_main_loop_quit(nyx_core.main_loop);
	return NYX_ERROR_NONE;
}

