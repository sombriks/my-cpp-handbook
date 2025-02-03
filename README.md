# [my-cpp-handbook][repo]

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

- Hello world
- Basic input (environment, arguments, interactive)
- Primitive types
- Basic control flow structures
- Functions
- Pointers
- Basic IO (files)
- Modularity (how to separate and organize code)
- Custom types and Classes
- Templates
- Compilation and compilers
- Project structure
- Other noteworthy libraries
- Intermediate IO (socket networking)
- Concurrency
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

[repo]: https://github.com/sombriks/my-cpp-handbook
[my-golang-handbook]: <https://github.com/sombriks/my-golang-handbook>
[c]: https://iso-9899.info/wiki/The_Standard
[cpp-comitee]: https://isocpp.org/std/the-committee
[get-fedora]: https://fedoraproject.org/workstation/
[gcc]: https://gcc.gnu.org/
[clang]: https://clang.llvm.org/cxx_status.html
