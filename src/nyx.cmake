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

macro(nyx_component dir)
	set(BASE_NYX_SUBDIR ${NYX_SUBDIR})
	if (NYX_SUBDIR)
		set(NYX_SUBDIR "${NYX_SUBDIR}/${dir}")
	else()
		set(NYX_SUBDIR "${CMAKE_CURRENT_SOURCE_DIR}/${dir}")
	endif()

	add_subdirectory(${dir} ${dir})
	set(NYX_SUBDIR ${BASE_NYX_SUBDIR})

	# make sure portability source is propogated to parent
	# if this isn't the top-level portability directory
	# don't want to leak variables unnecessarily
	if (NYX_SUBDIR)
		set(NYX_INCLUDES "${NYX_INCLUDES}" PARENT_SCOPE)
		set(NYX_SOURCE "${NYX_SOURCE}" PARENT_SCOPE)
		set(NYX_LIBS "${NYX_LIBS}" PARENT_SCOPE)
	else()
		message("Sources = ${NYX_SOURCE}")
	endif()
endmacro()

macro(nyx_include)
	foreach (inc ${ARGV})
		if (NOT "${inc}" MATCHES ^/)
			set(inc "${NYX_SUBDIR}/${inc}")
		endif()
		list(APPEND NYX_INCLUDES ${inc})
	endforeach()
	set(NYX_INCLUDES ${NYX_INCLUDES} PARENT_SCOPE)
endmacro(nyx_include)

macro(add_nyx_source)
	foreach (src ${ARGV})
		if (NOT "${src}" MATCHES ^/)
			set(src "${NYX_SUBDIR}/${src}")
		endif()
		list(APPEND NYX_SOURCE ${src})
	endforeach()
	set(NYX_SOURCE ${NYX_SOURCE} PARENT_SCOPE)
endmacro()

macro(add_nyx_libs)
	list(APPEND NYX_LIBS ${ARGV})
	set(NYX_LIBS ${NYX_LIBS} ${ARGV} PARENT_SCOPE)
endmacro()
	