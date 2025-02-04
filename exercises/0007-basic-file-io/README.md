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

## Build examples

## Run

## Noteworthy

- [this nice tutorial][tuto]

[cfile]: https://en.cppreference.com/w/c/io/FILE
[fstream]: https://cplusplus.com/reference/iolibrary
[tuto]: https://cplusplus.com/doc/tutorial/files
[getline]: https://cplusplus.com/reference/istream/istream/getline
