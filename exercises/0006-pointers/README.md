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
// pointer-01.cpp
#include <cstdio>

int main(int argc, char **argv) {

  int a = 10;
  int b = 20;
  int *p = &a;

  return 0;  
}
```

[primitive-types]: ../0003-primitive-types/README.md
[functions]: ../0005-functions/README.md
