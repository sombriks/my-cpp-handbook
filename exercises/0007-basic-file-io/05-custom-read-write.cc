// 05-custom-read-write.cc
#include <iostream>
#include <fstream>

struct person
{
  char name[100];
  int age;
};

int main(int argc, char **argv)
{
  struct person p1;

  std::cout << "Provide a name: " << std::endl;
  std::cin >> p1.name;
  std::cout << "Provide an age: " << std::endl;
  std::cin >> p1.age;

  std::fstream myFile;
  myFile.open("some-custom-data.bin",                   //
              std::fstream::binary | std::fstream::in | //
                  std::fstream::out | std::fstream::app);

  // hacky but works
  myFile.write((char *)&p1, sizeof(struct person));

  myFile.seekp(0); // back to the start of the file

  while (!myFile.eof())
  {
    struct person p2;
    myFile.read((char *)&p2, sizeof(struct person));
    std::cout << "Person found: " << p2.name << ", " << p2.age << std::endl;
    myFile.peek(); // avoid to read the last line twice
  }

  myFile.close();

  return 0;
}