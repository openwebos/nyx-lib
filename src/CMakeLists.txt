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

# Make sure the build system's version of this component matches what we're building.
# The intent is for it to pass in COMPONENT_VERSION via the command line.
if(DEFINED NYX_COMPONENT_VERSION)
	if (NOT (NYX_LIBRARY_VERSION STREQUAL NYX_COMPONENT_VERSION))
		message(FATAL_ERROR "Component version from build system (${NYX_COMPONENT_VERSION}) != configured version (${NYX_LIBRARY_VERSION})")
	endif()
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/" ${CMAKE_MODULE_PATH})

set(DEFAULT_TARGET "ubuntu" CACHE INTERNAL "The default core OS for which to build")

# Should specify a core OS product (ubuntu, rockhopper, etc.)
if(NOT TARGET)
	set(TARGET "${DEFAULT_TARGET}")
	message(WARNING "No TARGET variable specified - defaulting to ${TARGET}")
endif()
set(TARGET ${TARGET} CACHE string "The core OS for which to build")

# Get the target-specific configuration (if any).
include(${CMAKE_CURRENT_SOURCE_DIR}/target/${TARGET}/CMakeLists.txt OPTIONAL RESULT_VARIABLE TARGET_CONFIG)

if(NOT TARGET)
	message(FATAL_ERROR "No TARGET variable specified")
endif()

if(TARGET)
	string(TOUPPER ${TARGET} TARGET_TOUPPER)
	string(REPLACE "-" "_" TARGET_TOUPPER_UNDERSCORE ${TARGET_TOUPPER})
	add_definitions(-DNYX_CORE_OS_${TARGET_TOUPPER_UNDERSCORE})
endif()

# fmessage-length=0: Make sure that errors & messages are printed on 1 line.
macro(add_flags flags)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flags}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags}")
endmacro()

macro(add_debug_flags flags)
	if (NOT CMAKE_BUILD_TYPE MATCHES ^Release$)
		set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${flags}")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${flags}")
	endif()
endmacro()

macro(add_release_flags flags)
	if (CMAKE_BUILD_TYPE MATCHES ^Release$)
		set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} ${flags}")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} ${flags}")
	endif()
endmacro()

macro(add_linker_flags flags)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${flags}")
endmacro()

set(NYX_COMPONENT_UTILS "${CMAKE_CURRENT_SOURCE_DIR}/nyx.cmake")

# Can't enable Werror yet
# add_flags("-Werror")
add_flags("-Wall -pipe -g -std=c99")
add_debug_flags("-O0 -DDEBUG -D_DEBUG")
add_release_flags("-DNDEBUG")

# XXX Using add_linker_flags() fails to add them to the link command line -- why??
add_flags("-Wl,--no-undefined")
# XXX The libraries that come with gcc fail when --no-allow-shlib-undefined is specified
#add_flags("-Wl,--no-allow-shlib-undefined")

add_definitions(-D_GNU_SOURCE=1)
add_definitions(-DNYX_MODULE_PREFIX=\"${CMAKE_SHARED_MODULE_PREFIX}\")
add_definitions(-DNYX_MODULE_SUFFIX=\"${CMAKE_SHARED_MODULE_SUFFIX}\")
add_definitions(-DNYX_MODULE_DIR=\"${NYX_MODULE_DIR}\")
add_definitions(-DNYX_MODULE_MOCK_DIR=\"${NYX_MODULE_MOCK_DIR}\")
message("NYX_MODULE_DIR      set to ${NYX_MODULE_DIR}")
message("NYX_MODULE_MOCK_DIR set to ${NYX_MODULE_MOCK_DIR}")
message("NYX_MODULE_PREFIX   set to ${CMAKE_SHARED_MODULE_PREFIX}")
message("NYX_MODULE_SUFFIX   set to ${CMAKE_SHARED_MODULE_SUFFIX}")

include(lib.cmake)

add_subdirectory(doc)
