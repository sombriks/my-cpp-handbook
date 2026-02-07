
#ifndef POINTER_TO_FUNCTION_CC
#define POINTER_TO_FUNCTION_CC

#include <iostream>

namespace ptf
{

  void duplicator(int &n)
  {
    n *= 2;
  }

  void incrementor(int &n)
  {
    n += 1;
  }

  void applier(int *v, int vSize, void (*f)(int &))
  {
    for (int i = 0; i < vSize; i++)
    {
      f(v[i]);
    }
  }

  void printer(int *v, int vSize)
  {
    for (int i = 0; i < vSize; i++)
    {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }

};

#endif // POINTER_TO_FUNCTION_CC