# A Makefile helps by defining a set of rules on how to produce the final
# artifacts from the source code and also delivering a certain degree of
# automation of this process.

CC := clang++ -Wall

all: exemplo-01.cc exemplo-02.cc exemplo-03.cc
	$(CC) exemplo-01.cc -o exemplo-01  
	$(CC) exemplo-02.cc -o exemplo-02
	$(CC) exemplo-03.cc -o exemplo-03

clean:
	rm -rf exemplo-01 exemplo-02 exemplo-03
	