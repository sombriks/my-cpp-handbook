// 03-file-write.cc
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  std::ofstream myFile("some-information.txt");

  myFile << "this message" << std::endl
         << "these numbers " << 1 << 2 << 3 << std::endl
         << "this pointer? " << argv << std::endl;

  myFile.close();

  return 0;
}