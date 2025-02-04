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
  std::ifstream someNumber("some-numbers.bin");
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

int main(int argc, char **argv)
{
  std::ifstream someWords("some-words.txt");
  
  return 0;
}
```

## Simple write

## Custom data

## Build examples

## Run

## Noteworthy

- [this nice tutorial][tuto]

[cfile]: https://en.cppreference.com/w/c/io/FILE
[fstream]: https://cplusplus.com/reference/iolibrary
[tuto]: https://cplusplus.com/doc/tutorial/files
[getline]: https://cplusplus.com/reference/istream/istream/getline
