// exemplo-03.cc

#include <cstdio>

void doubleAndPlus(int &toDouble, int &toPlus)
{
  toDouble *= 2;
  toPlus += 1;
}

int main(int argc, char **argv)
{
  int a = 10;
  int b = 20;
  doubleAndPlus(a, b);
  printf("results: %d, %d\n", a, b);
  return 0;
}