#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::cout << "Please provide your name: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << std::endl;
  return 0;
}