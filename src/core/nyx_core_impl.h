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
 * @file nyx_core_impl.h
 *
 * @brief This is a header file of the nyx core implementation
 ********************************************************************************/

#ifndef _NYX_CORE_IMPL_H_
#define _NYX_CORE_IMPL_H_

#include <glib.h>
#include <nyx/nyx_client.h>

nyx_error_t nyx_core_init(void);
nyx_error_t nyx_core_deinit(void);
const char *nyx_core_device_type_to_string(nyx_device_type_t type);

#endif /* _NYX_CORE_IMPL_H_ */
