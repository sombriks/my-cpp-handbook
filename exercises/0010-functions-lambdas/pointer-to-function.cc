
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

};