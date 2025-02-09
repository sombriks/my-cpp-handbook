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
