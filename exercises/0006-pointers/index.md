# Pointers

Thanks to pointers, it is possible to have two identifiers to the same region in
the memory.

But it has consequences.

## It's all about memory addresses

As seen quickly in [primitive types][primitive-types], pointers are meant to
hold addresses. One side-effect of it is all pointers has the same size.

As seen in [functions][functions], it's possible to get the address of a
variable by using the `&` operator.

The following code samples how to use a pointer to bind its address to a second
identifier:

<<< pointer-01.cc{cpp}

It should output something like this:

```
sombriks@barbatos 0006-pointers $ ./pointer-01 
address of a: 0x7ffe01dcdbbc
address of b: 0x7ffe01dcdbb8
address p points to: 0x7ffe01dcdbbc
```

But what does it mean? Changes in a will reflect on p and vice versa:

<<< pointer-02.cc{cpp}

## Watch out uninitialized and dangling pointers

It is unknown behavior to try use pointers which points to no variable. Also, if
the variable isn't available anymore, the pointer is invalid as well.

<<< pointer-03.cc{cpp}

Dangling pointers are similar, but for some time they are still valid.
Manipulate freed memory is considered unknown behavior and **might** result in
runtime errors.

<<< pointer-04.cc{cpp}

## Modern, safe approach

Modern C++ offers a way to defend the code from such nasty source of bugs. There
is [smart pointers][smart-pointers].

The regular pointer for now on will be called [naked-pointer][naked-pointer].

Caution when execute the example bellow. It leaks memory on purpose and might freeze your computer!

<<< pointer-05.cc{cpp}

[primitive-types]: ../0003-primitive-types/README.md
[functions]: ../0005-functions/README.md
[smart-pointers]: https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
[naked-pointer]: https://cplusplus.com/forum/beginner/276127/#google_vignette
