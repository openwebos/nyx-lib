# @@@LICENSE
#
#      Copyright (c) 2010-2014 LG Electronics, Inc.
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

# The values for following variables can be set from command line
# NYX_MODULE_DIR - Location of installed nyx modules
# NYX_MODULE_MOCK_DIR - Location of mock modules (if any)

cmake_minimum_required(VERSION 2.8.7)

project(nyx)

set(NYX_API_VERSION_MAJOR 6)
set(NYX_API_VERSION_MINOR 1)

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC7)
webos_component(${NYX_API_VERSION_MAJOR} ${NYX_API_VERSION_MINOR} 0)

set(NYX_LIB_ROOT ${WEBOS_INSTALL_LIBDIR}/nyx CACHE PATH "Nyx internal executables install root path")
set(NYX_CMD_MODULE_DIR ${NYX_LIB_ROOT}/nyxcmd CACHE PATH "nyx-cmd modules directory path")
set(NYX_MODULE_DIR ${NYX_LIB_ROOT}/modules CACHE PATH "Nyx modules directory path")
set(NYX_MODULE_MOCK_DIR ${NYX_LIB_ROOT}/modules.mock CACHE PATH "Nyx mock modules directory path")
set(NYX_MODULE_PREFIX nyx)
set(NYX_MODULE_SUFFIX .module)

webos_add_linker_options(ALL --no-undefined --as-needed)
webos_add_compiler_flags(ALL -Wall -g -std=c99)
webos_add_compiler_flags(ALL -D_GNU_SOURCE=1)
webos_add_compiler_flags(DEBUG -O0 -DDEBUG -D_DEBUG)
webos_add_compiler_flags(RELEASE -DNDEBUG)

add_definitions(-DNYX_MODULE_PREFIX=\"${NYX_MODULE_PREFIX}\")
add_definitions(-DNYX_MODULE_SUFFIX=\"${NYX_MODULE_SUFFIX}\")
add_definitions(-DNYX_MODULE_DIR=\"${NYX_MODULE_DIR}\")
add_definitions(-DNYX_MODULE_MOCK_DIR=\"${NYX_MODULE_MOCK_DIR}\")

include(FindPkgConfig)

#Check that we have glib-2.0
pkg_check_modules(GLIB2 REQUIRED glib-2.0)
include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS_OTHER})

webos_configure_header_files(src/core)
webos_configure_header_files(include/public INSTALL)

include_directories(include/public src/core)

file(GLOB NYX_SOURCE src/core/*.c src/device/*.c src/utils/*.c)
add_library(nyx SHARED ${NYX_SOURCE})
target_link_libraries(nyx ${GLIB2_LIBRARIES} dl pthread rt)

webos_build_pkgconfig()
webos_build_library()

webos_config_build_doxygen(doc module_api.doxy client_api.doxy)
