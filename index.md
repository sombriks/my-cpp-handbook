---
# https://vitepress.dev/reference/default-theme-home-page
layout: home
hero:
  name: "My C++ handbook"
  text: "Simple guide on how to get things done using C++"
  tagline: Quick reference of good ways to do things in C++
---
# Getting started

Small exercises and experiments on the C++ language.

Each exercise tries to cope some core aspect of the language, but focused on how
to solve problemas using it.

Complexity will grow with each exercise, and the background history as well.
It's the same formula from [my golang handbook][my-golang-handbook].

Think about C++ is to think about the computer history itself. The language
predates the internet and was born to ease the task of writing core things, like
operating systems and network stacks. There is one standard, yet there are many
idioms, many libraries, many compilers.

The language is still evolving. And yet it still holds great retrocompatibility
with [C][c] language. This is both the blessing and the curse of C++.

## Base agenda

We are covering at least the following topics:

- [Hello world](exercises/0001-hello-world/)
- [Basic input](exercises/0002-basic-input/) (environment, arguments, interactive)
- [Primitive types](exercises/0003-primitive-types/)
- [Basic control flow structures](exercises/0004-control-structures/)
- [Functions](exercises/0005-functions/) (part 1)
- [Pointers](exercises/0006-pointers/)
- [Basic IO](exercises/0007-basic-file-io/) (files)
- [Modularity](exercises/0008-modularity/) (how to separate and organize code)
- [Classes](exercises/0009-classes/)
- [Functions part two](exercises/0010-functions-lambdas/)
- Compilation and compilers
- Project structure
- Other noteworthy libraries
- Intermediate IO (socket networking)
- Concurrency (threads)
- Cross-Compiling

## Why C++?

It is a quite easy task to talk bad about C++. The time the language took to
evolve and offer basic things didn't help either.

But it's flexible and  modern, [actively evolving][cpp-comitee], adding modern
features without lose the compatibility with C or 'the past'.

## Requirements

This guide was mostly written and tested on [Fedora Linux][get-fedora], with
either [gcc][gcc] or [clang][clang] compilers. However, it is supposed to be
possible to run those exercises in any operating system with a standard C++
compiler and runtime library.

## How this handbook is structured

Each exercise has a README with specific context and instructions on how to
build and run the sample code. Sometimes it's just a single source file,
sometimes a more structured project.

[my-golang-handbook]: <https://github.com/sombriks/my-golang-handbook>
[c]: https://iso-9899.info/wiki/The_Standard
[cpp-comitee]: https://isocpp.org/std/the-committee
[get-fedora]: https://fedoraproject.org/workstation/
[gcc]: https://gcc.gnu.org/
[clang]: https://clang.llvm.org/cxx_status.html
