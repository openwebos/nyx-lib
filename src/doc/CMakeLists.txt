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

# Allow developers to define NYX_DOC_LOCATION, and thus specify the
# root directory under which all documentation will be placed.

if (NOT NYX_DOC_LOCATION)
    set(NYX_DOC_LOCATION "${CMAKE_BINARY_DIR}/doc")
else()
# Make sure relative paths are relative to the binary directory, not
# this source directory.
    if (NOT IS_ABSOLUTE "${NYX_DOC_LOCATION}")
        set (NYX_DOC_LOCATION "${CMAKE_BINARY_DIR}/${NYX_DOC_LOCATION}")
    endif()
endif()

set(NYX_DOC_LOCATION "${NYX_DOC_LOCATION}" CACHE PATH "The directory in which documentation will be created")

message("")
message(STATUS "-- ${CMAKE_PROJECT_NAME} documentation will be created in ${NYX_DOC_LOCATION}")
message("")

# Create the doxygen input files with all the correct paths etc.

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.modules.in ${NYX_DOC_LOCATION}/Doxyfile.modules @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.client.in ${NYX_DOC_LOCATION}/Doxyfile.client @ONLY)

# Add a target called "docs" (i.e., make docs). 
# doxygen and dot (from graphviz) are expected to be available.
add_custom_target(docs 
                  doxygen ./Doxyfile.modules
                  COMMAND doxygen ./Doxyfile.client
                  SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.client.in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.modules.in
                  WORKING_DIRECTORY ${NYX_DOC_LOCATION} )
