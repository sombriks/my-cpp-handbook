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

```cpp
// exemplo-01.cc
void noop(){}

int main(int argc, char **argv) {
  noop();
  return 0;
}
```

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

```cpp
// exemplo-02.cc
#include <cstdio>

bool isTriangle(int a, int b, int c) {
  return a  + b > c && a + c > b && b + c > a; 
}

int main(int argc, char **argv) {
  bool t1 = isTriangle(3, 3, 3);
  bool t2 = isTriangle(3, 3, 2);
  bool t3 = isTriangle(3, 4, 5);
  bool t4 = isTriangle(3, 3, 8);

  printf("3,3,3 %s a triangle\n", t1 ? "is" : "is not");
  printf("3,3,2 %s a triangle\n", t2 ? "is" : "is not");
  printf("3,4,5 %s a triangle\n", t3 ? "is" : "is not");
  printf("3,3,8 %s a triangle\n", t4 ? "is" : "is not");

  return 0;
}
```

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

```cpp
// exemplo-03.cc

#include <cstdio>

// addresses instead of values will be copied to the function argument list.
void doubleAndPlus(int &toDouble,int &toPlus) {
  toDouble *= 2;
  toPlus += 1;
}

int main(int argc, char **argv) {
  int a = 10;
  int b = 20;
  doubleAndPlus(a, b); // caution, no great difference in the function call.
  printf("results: %d, %d\n",a,b);
  return 0;
}
```

That way we can use argument list as return values.

This is also a way to optimize memory usage: no copy of big arrays to the
argument list. Possibilites are infinite!

[make]: https://www.gnu.org/software/make/
[ref-operator]: https://en.cppreference.com/w/cpp/language/operator_member_access#Built-in_address-of_operator
