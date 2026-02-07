# Pointer to function, function types, lambdas and std::function

C++ offer great flexibility regarding how to declare and use functions.

It inherits all that plain C can do and offers nice, extra features in the
language and in the std lib.

## Pointers

pointers can store addresses, and functions has addresses as well. Therefore,
this is valid C++ code:

<<< pointer-to-function.cc{cpp}

The `void (*f)(int &)` might look like a bit clumsy, but the parenthesis around
_*f_ make sure that you ton't mistype the return type (for example _int*_
instead of _int_).

### Function typedefs

Optionally, you can write a `typedef` to make it easier to the eye:

<<< function-typedef.cc{cpp}

It's possible now to write something like `ptf::func_t f = ptf::duplicator`.

## Lambdas

Pass functions around for later use deciding on the context is nice, however the
_context_ associated with it is limited.

For instance, you are constrained by the _function contract_ (how many
parameters, their types and return type) and this is all you get available when
the time comes.

This is also why the [opaque pointer parameter][opaque] is ofter present in
libraries consuming pointer to functions.

[opaque]: https://en.wikipedia.org/wiki/Opaque_pointer

On the other hand, _lambdas_ can carry references and values from the context
they came from:

<<< sample-lambda.cpp

Lambda has these key parts:

- **type**: the variable type for this lambda. `auto` is used in this specific
  example, but there are other possibilities.
- **name**: variable name, how you will refer to this lambda. it is `sample` in
  this example.
- **context capture**: this is where lambda shines. set the shared context
  between the current function and the lambda being declared. it is the `[&x]`.
  You can define the capture in many ways, by value, by reference, pass nothing
  at all, you call it.
- **parameter list**: like a regular function, the parameter list the lambda
  will receive when it gets called. it' the `(int &n)` part.
- **lambda's body**: function body to be executed.

It might look ugly or too similar to a regular function, but in fact it has more
similarities with classes than with functions.

Thanks to the capture group, lambdas can carry state.

### std::function

A side effect of this is that lambda signatures, when have a non-empty capture
group, doesn't fit well in regular function pointers, leading to unexpected
behavior and compile errors.

To solve that, functions consuming lambdas must adapt:

<<< std-function-printer.cc{cpp}

You can check the usage of each approach in the `main.cc`:

<<< main.cc{cpp}

## How to run

Simply compile and run the entrypoint:

```bash
g++ -Wall main.cc -o main
./main
```

## Noteworthy

- Technically speaking, class methods and lambdas are equivalent, except that
  lambdas are a lightweight syntax to get the same result: custom context for a
  function.
- The example above includes source files instead of headers and also compiles
  one single entrypoint. It's called [jubmo build][jumbo].

[jumbo]: https://austinmorlan.com/posts/unity_jumbo_build/
