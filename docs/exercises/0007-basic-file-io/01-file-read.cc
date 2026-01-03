// 01-file-read.cc
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  std::ifstream someNumber("some-numbers.txt");
  long number = 0;
  someNumber >> number;
  std::cout << "Number is " << number << std::endl;
  someNumber >> number;
  std::cout << "Second Number is " << number << std::endl;
  someNumber.close();
  return 0;
}