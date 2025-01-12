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
void noop(){}

int main(int argc, char **argv) {
  noop();
  return 0;
}
```
