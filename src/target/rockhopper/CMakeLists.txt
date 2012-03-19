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

set (CMAKE_SHARED_MODULE_PREFIX "nyx")
set (CMAKE_SHARED_MODULE_SUFFIX ".module")
# Use multiarch paths
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
set (NYX_MODULE_DIR "/lib/aarch64-linux-gnu/nyx/modules")
set (NYX_MODULE_MOCK_DIR "/lib/aarch64-linux-gnu/nyx/modules.mock")
else()
set (NYX_MODULE_DIR "/lib/arm-linux-gnueabi/nyx/modules")
set (NYX_MODULE_MOCK_DIR "/lib/arm-linux-gnueabi/nyx/modules.mock")
endif()
