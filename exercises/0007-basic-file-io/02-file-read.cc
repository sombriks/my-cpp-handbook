// 02-file-read.cc
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
  std::ifstream someWords("some-words.txt");
  std::string str;
  someWords >> str;
  std::cout << str << std::endl;
  someWords >> str;
  std::cout << str << std::endl;
  someWords >> str;
  std::cout << str << std::endl;
  // someWords >> str;
  // std::cout << str << std::endl;
  someWords.get(); // skip the endline
  char line[20];
  someWords.getline(line, 20);
  std::cout << line << std::endl;
  return 0;
}