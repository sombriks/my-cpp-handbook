
// pointer-04.cc
#include <cstdio>
#include <cstdlib>

void cleaner(int *dynamicArray)
{
  free(dynamicArray);
}

int main(int argc, char **argv)
{

  int *someInts = (int *)malloc(10 * sizeof(int));

  for (int i = 0; i < 10; i++)
    someInts[i] = i;

  int *p;
  p = someInts;
  for (int i = 0; i < 10; i++)
    printf("%d ", p[i]);
  printf("\n");

  cleaner(someInts);

  for (int i = 0; i < 10; i++)
    printf("%d ", p[i]); // prints illegal memory
  printf("\n");

  for (int i = 0; i < 10; i++)
    p[i] = i; // changes illegal memory

  for (int i = 0; i < 10; i++)
    printf("%d ", p[i]); // prints illegal memory
  printf("\n");

  return 0;
}
