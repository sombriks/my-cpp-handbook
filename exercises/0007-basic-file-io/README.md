# File Input and Output

In addition to the compatibility with [C file API][cfile], C++ standard library
offers a proper file abstraction integrated with streams. They are defined in
the [fstream][fstream] library.

## Simple read

Read from a file is quite simple:

```cpp
// 01-file-read.cc
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  std::ifstream someNumber("some-numbers.txt");
  long number = 0;
  someNumber >> number;
  std::cout << "Number is " << number << std::endl;
  someNumber.close();
  return 0;
}
```

Mind that the file must exists and must have a number inside it.

Read naked, c-style strings is also easy. Just mind up how to proper read an
entire [line][getline]:

```cpp
// 02-file-read.cc
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
  // file has two lines of words, rthree per line
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
```

## Simple write

Writing to a file using streams is simple as well:

```cpp
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
```

Again the stream api operator overloads are quite handy.

Expected file is like this:

```txt
this message
these numbers 123
this pointer? 0x7ffd2d40c4b8
```

By running the program again, the file  content will be overwritten. If we want
to append we need to pass flags:

```cpp
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
```

## Custom data

Like with plain C, it's possible to read and write custom types:

```cpp
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
```

## Build examples

The samples can be built with [cmake][cmake], a build tool which helps to create
portable projects more easily:

```bash
cd 0007-basic-file-io
cmake .
make
```

Cmake projects are configured in a file called CMakeLists.txt and has numerous
configuration options:

```cmake
cmake_minimum_required(VERSION 3.20)

project(sample-file-io VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

add_executable(01-file-read 01-file-read.cc)
add_executable(02-file-read 02-file-read.cc)
add_executable(03-file-write 03-file-write.cc)
add_executable(04-file-write 04-file-write.cc)
add_executable(05-custom-read-write 05-custom-read-write.cc)
```

## Run

Simply execute the binaries as usual.

## Noteworthy

- Never trust that a file exists, is accessible or has valid content. Always
  check it.
- Write strings are always easy, but read them sometimes demands proper
  knowledge about its size.
- The way that `fstream::peek()` and `fstream::eof()` work together might look a
  bit hacky but makes total sense. Streams have no idea that they're done so we
  must check.
- CMake projects ease the work needed to solve problems related to portable
  projects. Such problems are not present in those examples, but it's a tool
  that worths to be studied.
- Read [This nice tutorial][tuto] for more file access details.

[cfile]: https://en.cppreference.com/w/c/io/FILE
[fstream]: https://cplusplus.com/reference/iolibrary
[tuto]: https://cplusplus.com/doc/tutorial/files
[getline]: https://cplusplus.com/reference/istream/istream/getline
[cmake]: https://cmake.org/getting-started
