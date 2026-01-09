# The Hello World

Outputs 'Hello World!' in the console.

<<< hello.cc{cpp}

## How to build

```bash
g++ hello.cc -o hello
```

if you have clang instead:

```bash
clang++ hello.cc -o hello
```

## How to run

```bash
./hello
```

## The modern C++ hello world

C++ keeps evolving and new, major features are coming. [Modules][cpp-modules],
for instance, offers faster compile time for big projects and drift away from
classic header files. So, our [modern hello world][hello-modern] follows:

<<< hello-modern.cc{cpp}

Modules are still considered experimental so you need two command lines to make
it work using g++:

```bash
# precompile the module
g++ -fmodules-ts -std=c++23 -x c++-system-header iostream
# follow normal compilation path
g++ -fmodules-ts -std=c++23 hello-modern.cc -o hello-modern
```

## The C compatibility

A lot of weird stuff we see in C++ are "due historical reasons". By that read:
keep C++ code a compatible superset of C.

It's perfectly possible to write modern, safe C++ code nowadays, but is also
possible to write it as unsafe as you want. The regular C++ developer wants
freedom and flexibility, there already lots of safe languages out there, like
java, go, python, you name it.

## Noteworthy

Since the advent of multitasking, all that modern computer needs to work is an
Operating System (or [Control Program][control-program], if you ar that old) and
a compiler (or an interpreted language, such as [BASIC][basic]). Things are like
that because the programs need to be compiled for that specific combination of
hardware and OS.

[control-program]: https://www.youtube.com/watch?v=IKzleg4AcXg
[basic]: https://en.wikipedia.org/wiki/Commodore_BASIC
[cpp-modules]: https://en.cppreference.com/w/cpp/language/modules
[hello-modern]: ./hello-modern.cc
