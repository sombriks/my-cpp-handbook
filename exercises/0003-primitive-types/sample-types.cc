#include <cstdio>

int main(int argc, char **argv)
{
  // the so-called fundamental types
  printf("bool has %lu byte in size\n", sizeof(bool));
  printf("char has %lu byte in size\n", sizeof(char));
  printf("short has %lu bytes in size\n", sizeof(short));
  printf("int has %lu bytes in size\n", sizeof(int));
  printf("long has %lu bytes in size\n", sizeof(long));
  printf("float has %lu bytes in size\n", sizeof(float));
  printf("double has %lu bytes in size\n", sizeof(double));

  // then the composite types
  int vals[]{1, 2, 3};
  printf("array size depebds on values held. for int vals[] {1,2,3};, size is %lu bytes\n", sizeof(vals));

  struct composite
  {
    int id{0};
    char keys[3]{'0', '0', '0'};
    long stamp{0};
  };

  printf("size of a struct containing int, char[3] and long is %lu bytes\n", sizeof(composite));

  printf("All pointer types has the same size since they hold addresses:\n");
  printf("bool* is %lu bytes\n", sizeof(bool *));
  printf("char* is %lu bytes\n", sizeof(char *));
  printf("short* is %lu bytes\n", sizeof(short *));
  printf("int* is %lu bytes\n", sizeof(int *));
  printf("long* is %lu bytes\n", sizeof(long *));
  printf("float* is %lu bytes\n", sizeof(float *));
  printf("double* is %lu bytes\n", sizeof(double *));
  printf("void* is %lu bytes\n", sizeof(void *));
  printf("struct composite* is %lu bytes\n", sizeof(struct composite *));

  return 0;
}