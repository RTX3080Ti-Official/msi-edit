=============================
Project Licensing Guidelines
=============================

To make the licensing status of this project as clear as possible, it uses 
the Software Package Data Exchange (SPDX) license identifiers.

The project source code is generally provided under the terms of the 
GPL-2.0, as specified in the COPYING file.

License Directory Structure
===========================

The LICENSES/ directory contains the full text of all licenses used in 
this project, organized as follows:

- ``LICENSES/preferred/``: Contains the main project license (GPL-2.0).
- ``LICENSES/exceptions/``: Contains specific linking exceptions, notably
  the ImGui-exception allowing interaction with MIT-licensed graphics code.
- ``LICENSES/3rdparty/``: Contains licenses for third-party libraries 
  redistributed or linked with this project (e.g., MIT for Dear ImGui).

How to apply license information
================================

Individual source files should not contain full license "boilerplate." 
Instead, they must contain an SPDX-License-Identifier at the very first 
line of the file.

For standard project files::

  // SPDX-License-Identifier: GPL-2.0-only

For files that are purely part of the ImGui integration layer::

  // SPDX-License-Identifier: MIT

Third-party libraries
=====================

This project links against Dear ImGui. While the project logic remains 
GPL-2.0, the Dear ImGui library remains under the MIT license. The 
``ImGui-exception`` ensures that linking these components does not 
violate the terms of either license.

For more information on SPDX, see: https://spdx.org/