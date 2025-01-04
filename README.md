# Easter Date Calculator

## Description

This program calculates and displays the date of Easter for a given year. It is based on examples from:

1. ["The GNU C Reference Manual"](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
2. [GNU `getopt` manual](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)

## Usage

```bash
./easterdt [options]
```

## Build

In the project release, you can find pre-compiled versions of the Easter Date Calculator for **x86-64 Linux** and **x86-64 Windows**. These binaries offer the easiest way to try the software. However, you may prefer to compile it yourself for architectural or customization reasons.

### Compilation Instructions

To compile the C file, several methods can be used. One of the most widely accepted and well-known tools is **GCC** (GNU Compiler Collection). It works exceptionally well on UNIX-like systems and comes pre-installed on most popular Linux distributions.

The basic command to compile using GCC is:

```bash
gcc -o file file.c
```

### Other Platforms

Although GCC does not provide native support for platforms like Windows, the [official documentation](https://gcc.gnu.org/install/binaries.html) list links to binaries for other platforms.

#### Links to GCC Binaries:

- **AIX**:
  - [AIX Open Source Packages (AIX5L AIX 6.1 AIX 7.1)](http://www.perzl.org/aix/).
- [DOS—DJGPP](http://www.delorie.com/djgpp/).
- **macOS**:
  - The [Homebrew](https://brew.sh/) package manager;
  - [MacPorts](https://www.macports.org/).
- **Microsoft Windows**:
  - The [Cygwin](https://sourceware.org/cygwin/) project;
  - The [MinGW](https://osdn.net/projects/mingw/) and [mingw-w64](https://www.mingw-w64.org/) projects.
- **OpenPKG**
  - [OpenPKG](http://www.openpkg.org/) offers binaries for quite a number of platforms.
- **GFortran**:
  - The [GFortran](https://gcc.gnu.org/wiki/GFortranBinaries) Wiki has links to GNU Fortran binaries for several platforms.
