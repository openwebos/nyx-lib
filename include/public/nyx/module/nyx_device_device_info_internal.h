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
 * @file nyx_device_device_info_internal.h
 *
 * @brief Internal implementation of the device_info private fields
 *
 */


#ifndef _NYX_DEVICE_DEVICE_INFO_INTERNAL_H_
#define _NYX_DEVICE_DEVICE_INFO_INTERNAL_H_

#include <nyx/module/nyx_device_internal.h>

typedef struct {
	nyx_device_t original;
	char* product_name;
	char* device_name;
	int32_t hardware_id;
	char* nduid_str;
	char* serial_number;
	char* hardware_revision;
	char* product_sku;
} nyx_device_info_device_t;

#endif /* _NYX_DEVICE_DEVICE_INFO_INTERNAL_H_ */
