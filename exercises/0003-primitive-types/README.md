# Minimum needed abou types

Some languages are called dynamic-typed languages because the programmer doesn't
need to care about the size a variable will assume in memory or if it's a number
or character, structure, whatever.

Some languages are statically typed, meaning that once you declare a variable,
you must also inform its type. Then attempts to set that typed variable with
other data type will result in compilation error.

Sure, there is type casting, but it's a runtime resort and not always will give
you the desired result.

C++ is statically typed, all variable sizes are set at compile time.

## Variable size and hardware architecture

By size we mean the needed memory size to represent a value of that type. And
depending on cpu architecture, that size nay vary based om how much memory can
be addressed at once. Some types, such as `byte`, has a well-know size across
all modern cpu architectures, others will vary.

## How to build

```bash
clang++ -Wall sample-types.cc -o sample-types
```

## How to run

```bash
./sample-types
```

## Noteworthy

More complete guide on basic types can be found [here][ctypes].

[ctypes]: https://en.cppreference.com/w/cpp/language/type
