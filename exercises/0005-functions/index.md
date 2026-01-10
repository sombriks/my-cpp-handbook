# Functions

Like in many other languages, functions are the basic way to reuse code.

## Don't repeat yourself

Given a solved problem appearing again and again in the code, put the solution
inside a function is a nice way to avoid duplicated code, which usually is a bad
thing to do.

Using a function we write it once and use it everywhere.

## A good function name matters a lot

Like variables, better the name, lesser the chance of creating bugs. Also, the
more distant a name is from its usage, the longer the name gets in order to be
clear enough.

## Example function

This does nothing but is totally valid:

<<< exemplo-01.cc{cpp}

Compile and run it:

```bash
clang++ exemplo-01.cc -o exemplo-01
./exemplo-01
```

## Passing and receiving values

Back in time, there was a thing called procedure and it was a function capable
of multiple return values, while functions could return just one value.

Modern usage and definitions doesn't care about that anymore, since a function
can return multiple values the same wqy procedures did in any modern language.

People care more nowadays if the function has any side-effects and idempotency,
but those topics will be addressed only in the future.

In C++, functions has one return type and zero or more arguments:

<<< exemplo-02.cc{cpp}

For this example, we can use the [Make][make] tool and then run the generated
binary:

```bash
make
./exemplo-02
```

## Scope, copy and reference

Now things get funny.

By default, values are copied: two distinct variables points to distinct memory
addresses. If we need to share several results from a function, we either fill
out a struct (and return a copy of the results), pass pointers or we use
[the special `&` operator][ref-operator]:

<<< exemplo-03.cc{cpp}

That way we can use argument list as return values.

This is also a way to optimize memory usage: no copy of big arrays to the
argument list. Possibilites are infinite!

## Noteworthy

This time, a [Makefile][make] was used to ease the compile process:

<<< Makefile{make}

[make]: https://www.gnu.org/software/make/
[ref-operator]: https://en.cppreference.com/w/cpp/language/operator_member_access#Built-in_address-of_operator
