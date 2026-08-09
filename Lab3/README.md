# CP5609 Lab 3

## Overview

This folder contains the Lab 3 work for the QtPackMan project. The lab focuses on Qt GUI structure, MVC design, coding standards, memory management, and Doxygen documentation.

## Main Work Completed

- Analysed the QtPackMan MVC structure.
- Improved memory management using destructors.
- Added a virtual destructor to `BoardObject`.
- Added destructor support for `ListBoardObjects`.
- Added destructor support for `Model`.
- Updated `Controller` destructor to release owned objects.
- Added a `Doxyfile` for Doxygen documentation.
- Added a `doc` target to the Makefile.
- Created a UML class diagram.
- Created an MVC / interaction diagram.
- Prepared a Lab 3 report.

## Important Files

- `QtPackMan.d/` – source code and Makefile.
- `diagrams/Lab3_UML_Class_Diagram.png` – UML class diagram.
- `diagrams/Lab3_MVC_Interaction_Diagram.png` – MVC and runtime interaction diagram.
- `report/Lab3_Report.pdf` – final Lab 3 report.

## Doxygen

A Doxygen configuration file was added as:

```text
QtPackMan.d/Doxyfile
```

The Makefile includes a documentation target:

```bash
mingw32-make doc
```

or:

```bash
make doc
```

This generates HTML documentation if Doxygen is installed locally.

## Submission

This lab is submitted through the shared GitHub repository link.
