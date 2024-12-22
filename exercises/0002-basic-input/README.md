# Basic input

It is important in any modern program be able to receive information at runtime
instead of know all needed values at compile time.

Yes, there are advantages about knowing all inputs at compile time, such as
speed optimizations, but true reusable programs can process somewhat arbitrary
input.

## How to build

```bash
clang++ input-arguments.cc -o input-arguments
```

The other two samples can be built in a similar way.

## How to run

```bash
./input-arguments Leonardo
```

## Noteworthy

By adding the `using namespace std` declaration, we can save a few characters of
code. Just `cout` instead of `std::cout`. But beware, by doing that, we lost a
bit of clarity and makes the namespace a little dirty.

C++ has a very neat string class, so you don't need to worry about memory
allocation when reading user input in a interactive way.
