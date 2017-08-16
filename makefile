FLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -O2
CC=g++

all: node bor main clean

main:
	$(CC) $(FLAGS) -c main.cpp
	$(CC) $(FLAGS) -o AC_Search node.o AhoCorasick.o main.o
node: node.cpp
		$(CC) $(FLAGS) -c node.cpp
bor: AhoCorasick.cpp
	$(CC) $(FLAGS) -c AhoCorasick.cpp
clean:
	rm -f *.o
	rm -f *.stackdump
