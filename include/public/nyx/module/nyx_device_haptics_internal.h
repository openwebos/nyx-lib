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
 * @file nyx_device_haptics_internal.h
 *
 */


#ifndef _NYX_DEVICE_HAPTICS_INTERNAL_H_
#define _NYX_DEVICE_HAPTICS_INTERNAL_H_

#include <nyx/module/nyx_device_internal.h>

struct nyx_haptics_data;
typedef struct nyx_haptics_data *nyx_haptics_data_handle_t;

typedef struct
{
	nyx_device_t original;
	int32_t haptic_effect_id;
	int32_t dampening_factor;
	nyx_haptics_data_handle_t data;
} nyx_haptics_device_t;

#endif /* _NYX_DEVICE_HAPTICS_INTERNAL_H_ */
