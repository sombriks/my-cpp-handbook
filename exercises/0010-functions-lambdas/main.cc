
#include <iostream>

#include "pointer-to-function.cc"
#include "function-typedef.cc"
#include "std-function-printer.cc"

int main(int argc, char *argv[])
{
  // our sample data
  int v[] = {1, 2, 3, 4, 5};
  // pointer to function
  std::cout << "pointer to function:" << std::endl;
  ptf::applier(v, 5, ptf::duplicator);
  ptf::applier(v, 5, ptf::incrementor);
  ptf::printer(v, 5);
  std::cout << std::endl;

  // function typedefs
  std::cout << "function typedef:" << std::endl;
  ptf::func_t f[] = {ptf::duplicator, ptf::incrementor};
  for (int i = 0; i < 2; i++)
  {
    ptf::applier(v, 5, f[i]);
  }
  ptf::printer(v, 5);
  std::cout << std::endl;

  // lambdas
  std::cout << "lambda" << std::endl;
  int x = 0;
  auto sample = [&x](int &n)
  {
    n -= 1;
    x += n;
  };
  ptf::applier2(v, 5, sample);
  ptf::printer(v, 5);
  std::cout << "x = " << x << std::endl;
  return 0;
}