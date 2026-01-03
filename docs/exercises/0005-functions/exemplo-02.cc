// exemplo-02.cc
#include <cstdio>

bool isTriangle(int a, int b, int c)
{
  return a + b > c && a + c > b && b + c > a;
}

int main(int argc, char **argv)
{
  bool t1 = isTriangle(3, 3, 3);
  bool t2 = isTriangle(3, 3, 2);
  bool t3 = isTriangle(3, 4, 5);
  bool t4 = isTriangle(3, 3, 8);

  printf("3,3,3 %s a triangle\n", t1 ? "is" : "is not");
  printf("3,3,2 %s a triangle\n", t2 ? "is" : "is not");
  printf("3,4,5 %s a triangle\n", t3 ? "is" : "is not");
  printf("3,3,8 %s a triangle\n", t4 ? "is" : "is not");

  return 0;
}
