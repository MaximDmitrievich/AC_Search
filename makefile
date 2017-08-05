FLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -O2
CC=g++

all: nodelink nodeend bor main clean

main:
	$(CC) $(FLAGS) -c main.cpp
	$(CC) $(FLAGS) -o AC_Search nodelink.o nodeend.o AhoCorasick.o main.o
nodelink: nodelink.cpp
		$(CC) $(FLAGS) -c nodelink.cpp
nodeend: nodeend.cpp
		$(CC) $(FLAGS) -c nodeend.cpp
bor: AhoCorasick.cpp
	$(CC) $(FLAGS) -c AhoCorasick.cpp
clean:
	rm -f *.o
	rm -f *.stackdump
