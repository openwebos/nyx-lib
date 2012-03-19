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

# Try to find the glib-2.0 library:
# This will define:
# Glib2_FOUND - system has glib-2.0
# Glib2_INCLUDE_DIRS - the glib-2.0 include directory and any dependencies
# Glib2_LIBRARIES - the glib-2.0 library and any dependencies

include(LibFindMacros)

find_program(PkgConfig NAMES pkg-config PATHS /usr/local/bin /usr/bin /bin)

set(${Glib2_LIB_DIRS} "")

if(PkgConfig)
       exec_program("${PkgConfig} --variable=libdir glib-2.0" OUTPUT_VARIABLE Glib2_LIB_DIRS)
endif(PkgConfig)

# Include directories
find_path(Glib2_INCLUDE_DIRS NAMES glib.h PATH_SUFFIXES glib-2.0)

find_path(Glib2_Config_INCLUDE_DIRS glibconfig.h PATH_SUFFIXES glib-2.0 glib-2.0/include lib/glib-2.0/include PATHS ${Glib2_LIB_DIRS}/glib-2.0/include)

# Find the library
find_library(Glib2_LIBRARIES NAMES glib-2.0)

libfind_process(Glib2)
