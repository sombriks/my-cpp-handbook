// pointer-01.cc
#include <cstdio>

int main(int argc, char **argv)
{

  int a = 10;
  int b = 20;
  int *p = &a;

  printf("address of a: %p\n", &a);
  printf("address of b: %p\n", &b);
  printf("address p points to: %p\n", p);

  return 0;
}