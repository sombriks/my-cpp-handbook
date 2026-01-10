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

<<< 01-distinct-files/complex-op.cc{cpp}

The source using this complex operation follows:

<<< 01-distinct-files/main-no-prototype.cc{cpp}

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

<<< 01-distinct-files/main-plus-prototype.cc{cpp}

Since some functions can be needed on several places in a program, it is also a
common practice to keep function prototypes in their own file as well and simply
_include_ them:

<<< 01-distinct-files/main.cc{cpp}

A _header file_  is a special source file that holds the function signatures,
constant declarations, everything your program offers but doesn't hold any
implementation. It's a direct C language heritage.

<<< 01-distinct-files/complex-op.h{cpp}

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
this is not always possible. Name issues plagued C projects for ages.

In C++, we can use **[namespaces][namespace]** to avoid name clashes:

<<< 02-namespaces/complex-op.hh{cpp}

The implementation itself needs a few tweaks as well:

<<< 02-namespaces/complex-op-v2.cc{cpp}

And finally the usage:

<<< 02-namespaces/main.cc{cpp}

## 'New' C++ modules

C++ keeps evolving and although it keeps C compatibility, new features are there
to improve performance and developer experience.

[Modules][modules] aims to solve the performance hit a project suffers when
solving header files dependency graphs:

<<< 03-modules/complex-op.cc{cpp}

Then the module can be used like this:

<<< 03-modules/main.cc{cpp}

One important thing about modules is although the standard is 5 years old by the
time of writing of this handbook, compilers still diverges on how to build
modules. it has direct impact on project setup:

<<< CMakeLists.txt{cmake}

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
