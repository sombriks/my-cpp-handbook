// main.cc
#include <iostream>

int complex_op(int, int); // parameter names are optional

int main(int argc, char **argv)
{
  std::cout << complex_op(2, 2) << std::endl;
  return 0;
}