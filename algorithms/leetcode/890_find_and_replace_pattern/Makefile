.DEFAULT:
all: find_and_replace_pattern.o
	g++ -o find_and_replace_pattern find_and_replace_pattern.o

find_and_replace_pattern.o: find_and_replace_pattern.cpp
	g++ -c -Werror -Wall find_and_replace_pattern.cpp -std=c++11

clean:
	rm find_and_replace_pattern
	rm *.o
