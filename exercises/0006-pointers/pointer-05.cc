// pointer-05.cc
#include <cstdio>
#include <cstdlib>
#include <memory>

struct Contact
{
  unsigned long id;
  char name[100];
  char address[300];
};

void nakedLeak()
{ // this leaks memory
  struct Contact *contact = (struct Contact *)malloc(sizeof(struct Contact));
}

void smartPointer()
{ // this does not
  std::unique_ptr<struct Contact> contact((struct Contact *)malloc(sizeof(struct Contact)));
}

int main(int argc, char **argv)
{
  unsigned long int i = 100000000, j = 100000000;

  while (i-- > 0)
    smartPointer();
  printf("loop allocating 100000000 times using smart pointer finished\n");

  while (j-- > 0)
    nakedLeak();
  printf("loop allocating 100000000 times using naked pointer finished\n");

  return 0;
}