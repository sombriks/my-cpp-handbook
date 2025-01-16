# A Makefile helps by defining a set of rules on how to produce the final
# artifacts from the source code and also delivering a certain degree of
# automation of this process.

CC := clang++ -Wall

all: pointer-01.cc pointer-02.cc pointer-03.cc pointer-04.cc
	$(CC) pointer-01.cc -o pointer-01
	$(CC) pointer-02.cc -o pointer-02
	$(CC) pointer-03.cc -o pointer-03
	$(CC) pointer-04.cc -o pointer-04

clean:
	rm -rf pointer-01 pointer-02 pointer-03 pointer-04
	