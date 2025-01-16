// pointer-03.cc
#include <cstdio>

int main(int argc, char **argv)
{

  long *p;

  printf("this is illegal: %li\n", *p); // compile warnings, runtime error

  return 0;
}