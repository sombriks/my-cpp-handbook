# Modularity

A very important aspect of any software project is how easy is to maintain it.
New features, bug correction, those aspects has direct impact on cost and
overall quality.

In any software development methodology, separation of concerns is key to add
those qualities into the codebase.

## Why and when break the source into several files

Simplest answer is _separation of concerns_, but let's try to exemplify what
does it really means.

Supposer our program needs to store contact info into files. Some functions are
dedicated to get the data, other to validate it and finally some function do the
needed logic to store and retrieve contacts from file correctly.

From those 3 major concerns, 2 are clearly tightly coupled, data acquisition and
validation, but file handling can abstract a lot from what should be in files.

Given that, the source code can be rearranged in a way that such concerns dwells
into distinct source files.

## Header files

The following example samples the source code split:

```cpp
// complex-op.cc
int complex_op(int a, int b)
{
  return a+b; // let's pretend this is a long, complex operation
}
```

The source using this complex operation follows:

```cpp
// main.cc
#include <iostream>

int main(int argc, char **argv)
{
  std::cout << complex_op(2,2) << std::endl;
  return 0;
}
```

An attempt to compile and run the code the way it is results in the following:

```bash
sombriks@lucien 0008-modularity $ make
[ 33%] Building CXX object CMakeFiles/distinct-files.dir/01-distinct-files/complex-op.cc.o
[ 66%] Building CXX object CMakeFiles/distinct-files.dir/01-distinct-files/main.cc.o
/home/sombriks/git/my-cpp-handbook/exercises/0008-modularity/01-distinct-files/main.cc: In function ‘int main(int, char**)’:
/home/sombriks/git/my-cpp-handbook/exercises/0008-modularity/01-distinct-files/main.cc:6:16: error: ‘complex_op’ was not declared in this scope
    6 |   std::cout << complex_op(2, 2) << std::endl;
      |                ^~~~~~~~~~
make[2]: *** [CMakeFiles/distinct-files.dir/build.make:90: CMakeFiles/distinct-files.dir/01-distinct-files/main.cc.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/distinct-files.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
```

To solve that issue, the **function prototype** must be available to `main.cc`:

```cpp
// main.cc
#include <iostream>

int complex_op(int,int); // parameter names are optional

int main(int argc, char **argv)
{
  std::cout << complex_op(2,2) << std::endl;
  return 0;
}
```

Since some functions can be needed on several places in a program, it is also a
common practice to keep function prototypes in their own file as well and simply
_include_ them:

```cpp
// main.cc
#include <iostream>
#include "complex-op.h"

int main(int argc, char **argv)
{
  std::cout << complex_op(2,2) << std::endl;
  return 0;
}
```

A _header file_  is a special source file that holds the function signatures,
constant declarations, everything your program offers but doesn't hold any
implementation. It's a direct C language heritage.

```cpp
// complex-op.h

// parameter names are optional
int complex_op(int, int);
```

## The (dirty) namespace

While source separation permits bigger and more complex programs to be created
more easily, bigger programs introduces new challenges.

For example, what happens if two distinct source files defines the same function
name?

```bash
sombriks@lucien 0008-modularity $ make
[ 42%] Built target distinct-files
[ 57%] Building CXX object CMakeFiles/namespaces.dir/02-namespaces/complex-op-v2.cc.o
[ 71%] Building CXX object CMakeFiles/namespaces.dir/02-namespaces/complex-op.cc.o
[ 85%] Building CXX object CMakeFiles/namespaces.dir/02-namespaces/main.cc.o
[100%] Linking CXX executable namespaces
/usr/bin/ld: CMakeFiles/namespaces.dir/02-namespaces/complex-op.cc.o: na função "complex_op(int, int)":
complex-op.cc:(.text+0x0): múltiplas definições de "complex_op(int, int)"; CMakeFiles/namespaces.dir/02-namespaces/complex-op-v2.cc.o:complex-op-v2.cc:(.text+0x0): definido primeiro aqui
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/namespaces.dir/build.make:129: namespaces] Error 1
make[1]: *** [CMakeFiles/Makefile2:111: CMakeFiles/namespaces.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
```

A simple solution would be to use a different name for the function, however
this is not always possible. Name issues plagued C projects since ages ago.

In C++, we can use **[namespaces][namespace]** to avoid name clashes:

```cpp
// complex-op.hh

// parameter names are optional
int complex_op(int, int);

namespace v2
{
  int complex_op(int, int);
}
```

The implementation itself needs a few tweaks as well:

```cpp
// complex-op-v2.cc
#include "complex-op.hh"

int v2::complex_op(int a, int b)
{
  return a * b;
}
```

And finally the usage:

```cpp
// main.cc
#include <iostream>
#include "complex-op.hh"

int main(int argc, char **argv)
{
  std::cout
      << complex_op(2, 2) << std::endl
      << v2::complex_op(2, 2) << std::endl;
  return 0;
}
```

## 'New' C++ modules

C++ keeps evolving and although it keeps C compatibility, new features are there
to improve performance and developer experience.

[Modules][modules] aims to solve the performance hit a project suffers when
solving header files dependency graphs:

```cpp
// complex-op.cc
export module complex_op;

export int complex_op(int a, int b)
{
  return a - b; // let's pretend this is a long, complex operation
}
```

Then the module can be used like this:

```cpp
// main.cc
#include <iostream>

import complex_op;

int main(int argc, char **argv)
{
  std::cout << complex_op(2, 2) << std::endl;
  return 0;
}
```

One important thing about modules is although the standard is 5 years old by the
time of writing of this handbook, compilers still diverges on how to build
modules. it has direct impact on project setup:

```cmake
cmake_minimum_required(VERSION 3.20)
project(modularity)

file(GLOB distinct_files_src "01-distinct-files/*.cc")
add_executable(distinct-files ${distinct_files_src})

file(GLOB namespaces_src "02-namespaces/*.cc")
add_executable(namespaces ${namespaces_src})

file(GLOB modules_src "03-modules/*.cc")
add_executable(modules ${modules_src})
target_compile_options(modules PRIVATE -std=c++20 -fmodules-ts)
```

For module build properly on g++, `-std=c++20 -fmodules-ts` flags must be
provided, but flags for other compilers [are different][clang-modules].

## Build examples

Configure the CMake project and call make as usual:

```bash
cd 0008-modularity
cmake .
make
```

[namespace]: https://learn.microsoft.com/cpp/cpp/namespaces-cpp?view=msvc-170
[modules]: https://en.cppreference.com/w/cpp/language/modules
[clang-modules]: https://clang.llvm.org/docs/StandardCPlusPlusModules.html#standard-c-named-modules
