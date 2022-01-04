# CppCommon

![Linux (clang)](https://github.com/chronoxor/CppCommon/actions/workflows/build-linux-clang.yml/badge.svg)
![Linux (gcc)](https://github.com/chronoxor/CppCommon/actions/workflows/build-linux-gcc.yml/badge.svg)
<br/>
![MacOS](https://github.com/chronoxor/CppCommon/actions/workflows/build-macos.yml/badge.svg)
<br/>
![Windows (Cygwin)](https://github.com/chronoxor/CppCommon/actions/workflows/build-windows-cygwin.yml/badge.svg)
![Windows (MinGW)](https://github.com/chronoxor/CppCommon/actions/workflows/build-windows-mingw.yml/badge.svg)
![Windows (MSYS2)](https://github.com/chronoxor/CppCommon/actions/workflows/build-windows-msys2.yml/badge.svg)
![Windows (Visual Studio)](https://github.com/chronoxor/CppCommon/actions/workflows/build-windows-vs.yml/badge.svg)

C++ Common Library contains reusable components and patterns for error and
exceptions handling, filesystem manipulations, math, string format and
encoding, shared memory, threading, time management and others.

[CppCommon API reference](https://chronoxor.github.io/CppCommon/index.html)

# Contents
  * [Features](#features)
  * [Requirements](#requirements)
  * [How to build?](#how-to-build)

# Features
* Cross platform (Linux, MacOS, Windows)
* Exception handling model
* Filesystem manipulations
* String encoding converters
* String format using [{fmt} library](http://fmtlib.net)
* CPU, memory, environment
* Shared memory
* Stack trace
* UUID generator
* Thread extensions (priority, affinity, yield)
* Thread barrier, latch
* Synchronization primitives
* Named synchronization primitives
* Producer/consumer queues
* Time management
* Utilities

# Requirements
* Linux (binutils-dev uuid-dev)
* MacOS
* Windows 10
* [cmake](https://www.cmake.org)
* [gcc](https://gcc.gnu.org)
* [git](https://git-scm.com)
* [gil](https://github.com/chronoxor/gil.git)
* [python3](https://www.python.org)

Optional:
* [clang](https://clang.llvm.org)
* [CLion](https://www.jetbrains.com/clion)
* [Cygwin](https://cygwin.com)
* [MSYS2](https://www.msys2.org)
* [MinGW](https://mingw-w64.org/doku.php)
* [Visual Studio](https://www.visualstudio.com)

# How to build?

### Install [gil (git links) tool](https://github.com/chronoxor/gil)
```shell
pip3 install gil
```

### Setup repository
```shell
git clone https://github.com/chronoxor/CppCommon.git
cd CppCommon
gil update
```

### Linux
```shell
cd build
./unix.sh
```

### MacOS
```shell
cd build
./unix.sh
```

### Windows (Cygwin)
```shell
cd build
unix.bat
```

### Windows (MSYS2)
```shell
cd build
unix.bat
```

### Windows (MinGW)
```shell
cd build
mingw.bat
```

### Windows (Visual Studio)
```shell
cd build
vs.bat
```
