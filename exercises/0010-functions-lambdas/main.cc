#include <iostream>

#include "pointer-to-function.cc"

int main(int argc, char *argv[])
{
  std::cout << "pointer to function:" << std::endl;
  int v[] = {1, 2, 3, 4, 5};
  ptf::applier(v, 5, ptf::duplicator);
  ptf::applier(v, 5, ptf::incrementor);
  for (int i = 0; i < 5; i++)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}