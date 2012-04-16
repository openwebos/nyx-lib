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


include(${NYX_COMPONENT_UTILS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config/nyx_version.h.in ${PROJECT_SOURCE_DIR}/include/nyx/common/nyx_version.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config/nyx_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config/nyx_config.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config/nyx.pc.in ${CMAKE_CURRENT_SOURCE_DIR}/config/nyx.pc @ONLY)

find_package(Glib2 REQUIRED)

nyx_component(core)
nyx_component(device)
nyx_component(utils)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}")
	nyx_component(${TARGET})
endif ()

include_directories(
	${Glib2_INCLUDE_DIRS}
	${Glib2_Config_INCLUDE_DIRS}
	../include
	${CMAKE_CURRENT_SOURCE_DIR}/config/
	${CMAKE_CURRENT_SOURCE_DIR}/core/
	.
)

add_library(nyx
	SHARED
	${NYX_SOURCE}
)

target_link_libraries(nyx
	${Glib2_LIBRARIES}
	dl
	pthread
	rt
)


set_target_properties(nyx PROPERTIES DEFINE_SYMBOL NYX_SHARED)
set_target_properties(nyx PROPERTIES DEFINE_SYMBOL NYX_EXPORT)
set_target_properties(nyx PROPERTIES VERSION ${NYX_LIBRARY_VERSION} SOVERSION ${NYX_API_VERSION_MAJOR})

install(DIRECTORY ../include/ DESTINATION include/ PATTERN "*.swp" EXCLUDE)
install(TARGETS nyx LIBRARY DESTINATION lib${LIB_SUFFIX}/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/config/nyx.pc DESTINATION lib/pkgconfig)
