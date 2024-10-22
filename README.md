# game

## Prerequisites

| Software                             | Version               | Description        |
|--------------------------------------|-----------------------|--------------------|
| [CLion](https://jetbrains.com/clion) | `>= 2023.1`           | IDE                |
| [MinGW](https://mingw-w64.org)       | `>= 9.0` (Bundled)    | Compiler           |
| [CMake](https://cmake.org)           | `>= 3.25.2` (Bundled) | Builder            |
| [GDB](https://cmake.org)             | `>= 12.1` (Bundled)   | Debugger           |
| [vcpkg](https://vcpkg.io)            | `>= 2022-12-14`       | Dependency Manager |

## Setup

1. Make sure you installed everything from the prerequisites section.
2. Run `vcpkg install` to download and install the dependencies.

> On Windows, make sure to enable developer mode, so it is possible for the
> build system to create symlinks.
