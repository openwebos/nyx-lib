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
		set(NYX_SUBDIR "${dir}")
	endif()

	add_subdirectory(${dir})

	set(NYX_SUBDIR ${BASE_NYX_SUBDIR})

	if (NYX_SUBDIR)
		set(NYX_SOURCE "${NYX_SOURCE}" PARENT_SCOPE)
	endif()
endmacro()

macro(add_nyx_source)
	foreach (src ${ARGV})
		list(APPEND NYX_SOURCE "${NYX_SUBDIR}/${src}")
	endforeach()
	set(NYX_SOURCE ${NYX_SOURCE} PARENT_SCOPE)
endmacro()
