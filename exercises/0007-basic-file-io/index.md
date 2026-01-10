# File Input and Output

In addition to the compatibility with [C file API][cfile], C++ standard library
offers a proper file abstraction integrated with streams. They are defined in
the [fstream][fstream] library.

## Simple read

Read from a file is quite simple:

<<< 01-file-read.cc{cpp}

Mind that the file must exists and must have a number inside it.

Read naked, c-style strings is also easy. Just mind up how to proper read an
entire [line][getline]:

<<< 02-file-read.cc{cpp}

## Simple write

Writing to a file using streams is simple as well:

<<< 03-file-write.cc{cpp}

Again the stream api operator overloads are quite handy.

Expected file is like this:

```txt
this message
these numbers 123
this pointer? 0x7ffd2d40c4b8
```

By running the program again, the file  content will be overwritten. If we want
to append we need to pass flags:

<<< 04-file-write.cc{cpp}

## Custom data

Like with plain C, it's possible to read and write custom types:

<<< 05-custom-read-write.cc{cpp}

## Build examples

The samples can be built with [cmake][cmake], a build tool which helps to create
portable projects more easily.

Cmake needs a file called `CMakeLists.txt`:

<<< CMakeLists.txt{cmake}

And the project can be built like this:

```bash
cd 0007-basic-file-io
cmake .
make
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
