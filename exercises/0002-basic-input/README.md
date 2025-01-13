# Basic input

It is important in any modern program be able to receive information at runtime
instead of know all needed values at compile time.

Yes, there are advantages about knowing all inputs at compile time, such as
speed optimizations, but true reusable programs can process somewhat arbitrary
input.

In this exercise we sample the 3 basic ways to capture external information: by
arguments, environment and interactively.

## How to build

```bash
clang++ input-arguments.cc -o input-arguments
clang++ input-environment.cc -o input-environment
clang++ input-interactive.cc -o input-interactive
```

## How to run

```bash
./input-arguments Leonardo
USER=Leonardo ./input-environment
./input-interactive # or "echo 'Leonardo' | ./input-interactive"
```

## Noteworthy

By adding the `using namespace std` declaration, we can save a few characters of
code. Just `cout` instead of `std::cout`. But beware, by doing that, we lost a
bit of clarity and makes the namespace a little dirty.

C++ has a very neat string class, so you don't need to worry about memory
allocation when reading user input in a interactive way.
