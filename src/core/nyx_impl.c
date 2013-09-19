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
 * @file nyx_impl.c
 *
 * @brief This is part of the nyx core implementation
 ********************************************************************************/

//#include "nyx_impl.h"
#include "nyx_core_impl.h"
#include "nyx_config.h"
#include <nyx/common/nyx_version.h>

nyx_error_t nyx_init(void)
{
	nyx_error_t error = NYX_ERROR_NONE;

	error = nyx_core_init();

	return error;
}

nyx_error_t nyx_deinit(void)
{
	nyx_error_t error = NYX_ERROR_NONE;

	error = nyx_core_deinit();

	return error;
}

const char *nyx_get_library_version(void)
{
	return NYX_LIBRARY_VERSION;
}

int32_t nyx_get_api_version_major(void)
{
	return NYX_API_VERSION_MAJOR;
}

int32_t nyx_get_api_version_minor(void)
{
	return NYX_API_VERSION_MINOR;
}

