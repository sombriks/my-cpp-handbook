// main.cc
#include <iostream>
#include "complex-op.hh"

int main(int argc, char **argv)
{
  std::cout
      << complex_op(2, 2) << std::endl
      << v2::complex_op(2, 2) << std::endl;
  return 0;
}