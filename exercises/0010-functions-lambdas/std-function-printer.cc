
#include <iostream>
#include <functional>

namespace ptf
{
  void applier2(int *v, int vSize, std::function<void(int &)> f)
  {
    for (int i = 0; i < vSize; i++)
    {
      f(v[i]);
    }
  }
};