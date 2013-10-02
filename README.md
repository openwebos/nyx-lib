nyx-lib
=======
Summary
-------
Open webOS Platform Portability Layer

Description
-----------

Nyx is the platform portability layer used to isolate the remainder of
Open webOS from dependencies on the hardware and core OS upon which it
is running. It is implemented as a shared library that exposes a uniform
client API and that expects to call into a series of platform-dependent
modules that implement the API for a particular device.

This is the repository for nyx-lib, the shared library.

How to Build on Linux
=====================

## Dependencies

Below are the tools and libraries (and their minimum versions) required to build nyx-lib:

* cmake  (version required by openwebos/cmake-modules-webos)
* gcc 4.6.3
* glib-2.0 2.32.1
* make (any version)
* openwebos/cmake-modules-webos 1.0.0 RC5
* pkg-config 0.26

## Building

Once you have downloaded the source, enter the following to build it (after
changing into the directory under which it was downloaded):

    $ mkdir BUILD
    $ cd BUILD
    $ cmake ..
    $ make
    $ sudo make install

The directory under which the files are installed defaults to `/usr/local/webos`.
You can install them elsewhere by supplying a value for `WEBOS_INSTALL_ROOT`
when invoking `cmake`. For example:

    $ cmake -D WEBOS_INSTALL_ROOT:PATH=$HOME/projects/openwebos ..
    $ make
    $ make install

will install the files in subdirectories of `$HOME/projects/openwebos`.

Specifying `WEBOS_INSTALL_ROOT` also causes `pkg-config` to look in that tree
first before searching the standard locations. You can specify additional
directories to be searched prior to this one by setting the `PKG_CONFIG_PATH`
environment variable.

If not specified, `WEBOS_INSTALL_ROOT` defaults to `/usr/local/webos`.

To configure for a debug build, enter:

    $ cmake -D CMAKE_BUILD_TYPE:STRING=Debug ..

To see a list of the make targets that `cmake` has generated, enter:

    $ make help

You may also specify the values for `NYX_MODULE_DIR` and `NYX_MODULE_MOCK_DIR` from 
command line. For example:

    $ cmake -D NYX_MODULE_DIR:PATH=$HOME/nyx/modules ..
    $ make
    $ sudo make install

The default settings are extracted from the variables `nyx_module_dir`and `nyx_module_mock_dir`
in nyx.pc.

## Uninstalling

From the directory where you originally ran `make install`, enter:

 $ [sudo] make uninstall

You will need to use `sudo` if you did not specify `WEBOS_INSTALL_ROOT`.

## Generating Documentation

Nyx generates two sets of documentation, reflecting that fact that the APIs
it presents to application and module writers are different.

The tools required to generate the documentation are:

- doxygen 1.7.6.1
- graphviz 2.26.3

Once you have run `cmake`, enter the following to generate the documentation:

    $ make docs

To view the generated HTML documentation, point your browser to either of the
following

    Documentation/nyx/module_api/html/index.html
    Documentation/nyx/client_api/html/index.html

in your build directory.

To install the generated documentation, enter:

    $ [sudo] make install-docs

The documentation will be installed to `usr/share/doc/nyx/module_api/html`and
`usr/share/doc/nyx/client_api/html` under the tree defined by the value of 
`WEBOS_INSTALL_ROOT` (or its default).

You will need to use `sudo` if you did not specify `WEBOS_INSTALL_ROOT`.

# Copyright and License Information

Unless otherwise specified, all content, including all source code files and
documentation files in this repository are:

Copyright (c) 2010-2013 LG Electronics, Inc.

Unless otherwise specified or set forth in the NOTICE file, all content,
including all source code files and documentation files in this repository are:
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this content except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


