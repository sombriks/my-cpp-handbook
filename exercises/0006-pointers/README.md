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

```cpp
// pointer-01.cc
#include <cstdio>

int main(int argc, char **argv) {

  int a = 10;
  int b = 20;
  int *p = &a;

  printf("address of a: %p\n", &a);
  printf("address of b: %p\n", &b);
  printf("address p points to: %p\n", p);

  return 0;  
}
```

It should output something like this:

```terminal
sombriks@barbatos 0006-pointers $ ./pointer-01 
address of a: 0x7ffe01dcdbbc
address of b: 0x7ffe01dcdbb8
address p points to: 0x7ffe01dcdbbc
```

But what does it mean? Changes in a will reflect on p and vice versa:

```cpp
// pointer-02.cc
#include <iostream>

int main(int argc, char **argv) {

  int a = 10;
  int b = 20;
  int *p = &a;

  a = 30;
  b = a;
  *p = 11;

  std::cout << "Updated values are: " << std::endl
  << "a: " << a << std::endl
  << "b: " << b << std::endl
  << "*p: " << *p << std::endl;

  p = &b;
  a = 15;
  b = 21;

  std::cout << "Updated values are: " << std::endl
  << "a: " << a << std::endl
  << "b: " << b << std::endl
  << "*p: " << *p << std::endl;

  return 0;  
}
```

## Watch out uninitialized and dangling pointers

It is unknown behavior to try use pointers which points to no variable. Also, if
the variable isn't available anymore, the pointer is invalid as well.

```cpp
// pointer-03.cc
#include <cstdio>

int main(int argc, char **argv) {

  long *p;

  printf("this is illegal: %li\n", *p); // compile warnings, runtime error

  return 0;  
}
```

Dangling pointers are similar, but for some time they are still valid.
Manipulate freed memory is considered unknown behavior and **might** result in
runtime errors.

```cpp
// pointer-04.cc
#include <cstdio>
#include <cstdlib>

void cleaner(int *dynamicArray) {
  free(dynamicArray);
}

int main(int argc, char **argv) {

  int *someInts = (int *) malloc(10 * sizeof(int));

  for(int i = 0; i < 10; i++) someInts[0] = i;

  int *p;
  p = someInts;
  for(int i = 0; i < 10; i++) printf("%d ", p[i]);
  
  cleaner(someInts);

  for(int i = 0; i < 10; i++) printf("%d ", p[i]); // prints illegal memory
  
  return 0;
}
```

## Modern, safe approach

Modern C++ offers a way to defend the code from such nasty source of bugs.

[primitive-types]: ../0003-primitive-types/README.md
[functions]: ../0005-functions/README.md
