// pointer-02.cc
#include <iostream>

int main(int argc, char **argv)
{

  int a = 10;
  int b = 20;
  int *p = &a; // declaration and initialization in a single line

  a = 30;
  b = a;
  *p = 11;

  std::cout << "Updated values are: " << std::endl
            << "a: " << a << std::endl
            << "b: " << b << std::endl
            << "*p: " << *p << std::endl;

  p = &b; // now p points to the address of b
  a = 15;
  b = 21;

  std::cout << "Updated values are: " << std::endl
            << "a: " << a << std::endl
            << "b: " << b << std::endl
            << "*p: " << *p << std::endl;

  return 0;
}