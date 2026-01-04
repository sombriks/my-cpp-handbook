// 03-file-write.cc
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  std::ofstream myFile("some-information.txt", std::ofstream::out | std::ofstream::app);

  myFile << "this message again" << std::endl
         << "more numbers " << 4 << 5 << 6 << std::endl;

  myFile.close();

  return 0;
}