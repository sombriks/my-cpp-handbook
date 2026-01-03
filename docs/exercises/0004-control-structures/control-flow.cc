#include <cstdio>
#include <iostream>

int main(int argc, char **argv)
{
  // but i can't define x here
  // int x = 1;
  {
    int x{2};
    printf("inside anonymous block x is %d\n", x);
  }
  int x{3};
  printf("outside anonymous block x is %d\n", x);

  bool condition{true}; // to be clear, same as `bool condition = true;`

  if (condition)
  {
    printf("this block runs because condition is true\n");
  }
  else
  {
    printf("this block does not run because condition isn't false\n");
  }

  int y = 10;
  while (y--) // it works because zero is false
  {
    printf("it will print %d more time(s)\n", y + 1);
  }

  // for loops has initialization, stop condition and step phase.
  for (int i = 1; i <= 10; i++)
  {
    printf("loop %d ", i);
  }
  printf("\n");

  int j = 9;

  printf("pick a number\n");
  std::cin >> j;

  switch (j)
  {
  case 1:
    printf("you got the one\n");
    break;
  // switches has fallthrough over values.
  case 2:
  case 4:
  case 6:
  case 8:
    printf("you got even\n");
    break;
  // default works like an else
  default:
    printf("math is hard\n");
    break;
  }

  return 0;
}