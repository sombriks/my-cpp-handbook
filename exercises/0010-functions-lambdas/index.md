# Pointer to function, function types, lambdas and std::function

C++ offer great flexibility regarding how to declare and use functions.

It inherits all that plain C can do and offers nice, extra features in the
language and in the std lib.

## Pointers

pointers can store addresses, and functions has addresses as well. Therefore,
this is valid C++ code:

<<< pointer-to-function.cc

The `void (*f)(int &)` might look like a bit clumsy, but the parenthesis around
_*f_ make sure that you ton't mistype the return type (for example _int*_
instead of _int_).

## Function types

## Lambdas

## std::function

## How to build

## How to run

## Noteworthy
