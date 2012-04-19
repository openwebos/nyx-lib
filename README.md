nyx-lib
=======

Nyx is the webOS portability layer used to isolate the remainder of webOS from dependencies on the hardware and core OS upon which it is running. It is implemented as a shared library that exposes a uniform client API and that expects to call into a series of platform-dependent modules that implement the API for a particular device.

This is the repository for nyx-lib, the shared library.

How to Build on Linux
=====================

## Dependencies

Below are the tools and library (and their minimum versions) required to build nyx-lib:

* cmake 2.6
* gcc 4.3
* glib-2.0 2.16
* make (any version)
* pkg-config 0.22

## Building

Once you have downloaded the source, execute the following to build it:

    $ mkdir BUILD
    $ cd BUILD
    $ cmake ..
    $ make
    $ sudo make install

The header files will be installed under

    /usr/local/include/nyx

and the libraries under

    /usr/local/lib

You can install it elsewhere by supplying a value for _CMAKE\_INSTALL\_PREFIX_ when invoking _cmake_. For example:

    $ cmake -D CMAKE_INSTALL_PREFIX:STRING=$HOME/projects/openwebos ..
    $ make
    $ make install
    
will install the header files under

    $HOME/projects/openwebos/include/nyx
    
and the libraries under

    $HOME/projects/openwebos/lib
    
directory.

## Generating documentation

Nyx generates two sets of documentation, reflecting that fact that it the APIs it presents to 
application and module writers are different.

The tool required to generate the documentation is:

* doxygen 1.6.3
* graphviz 2.20.2 

Once you have run cmake, execute the following to generate the documentation:

$ make docs

To view the generated HTML documentation, point your browser to either of the following

    doc/module_api/html/index.html
    doc/client_api/html/index.html

in your build directory.

Just as you can do out-of-tree builds, Nyx allows you to place the documentation files anywhere
you wish by overriding the NYX_DOC_LOCATION variable on the cmake command line. For example, 

    $ cmake -D NYX_DOC_LOCATION:PATH=$HOME/documentation/nyx-lib ..
    $ make docs

will place the documentation directories (module_api and client_api) under the 

    $HOME/documentation/nyx-lib 

directory.

The provided path may be absolute or relative. Relative paths are 'relative' to the build directory.

# Copyright and License Information

All content, including all source code files and documentation files in this repository are: 

 Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.

All content, including all source code files and documentation files in this repository are:
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this content except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

