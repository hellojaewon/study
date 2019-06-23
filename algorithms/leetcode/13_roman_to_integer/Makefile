.DEFAULT:
all: roman_to_integer.o
	g++ -o roman_to_integer roman_to_integer.o

roman_to_integer.o: roman_to_integer.cpp
	g++ -c roman_to_integer.cpp -std=c++11

clean:
	rm roman_to_integer
	rm *.o
