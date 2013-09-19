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
 * @file nyx_macros.h
 *
 * @brief Definition of NYX's macros.
 *
 */

#ifndef _NYX_MACROS_H_
#define _NYX_MACROS_H_

#define NYX_API_EXPORT __attribute__((visibility("default")))
#define NYX_API_IMPORT __attribute__((visibility("default")))
#define NYX_API_LOCAL __attribute__((visibility("hidden")))
#define NYX_API_INTERNAL __attribute__((visibility("internal")))

#if _GNUC__

#define NYX_FORMAT_ARG(index) __attribute__((format_arg(index)))
#define NYX_FORMAT_FUNC(archetype, stringIndex, firstToCheck) __attribute__((format(archetype, stringIndex, firstToCheck)))
#define NYX_PRINTF_FORMAT_FUNC(stringIndex, firstToCheck) NYX_FORMAT_FUNC(printf, stringIndex, firstToCheck)

#else

#define NYX_FORMAT_ARG(index)
#define NYX_FORMAT_FUNC(archetype, stringIndex, firstToCheck)
#define NYX_PRINTF_FORMAT_FUNC(stringIndex, firstToCheck)

#endif

#endif // _NYX_MACROS_H_

