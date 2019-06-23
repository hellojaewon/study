.DEFAULT:
all: add_two_numbers.o
	g++ -o add_two_numbers add_two_numbers.o

add_two_numbers.o: add_two_numbers.cpp
	g++ -c add_two_numbers.cpp -std=c++11

clean:
	rm add_two_numbers
	rm *.o
