.DEFAULT:
all: largest_number.o
	g++ -o largest_number largest_number.o

largest_number.o: largest_number.cpp
	g++ -c largest_number.cpp -std=c++11

clean:
	rm largest_number
	rm *.o
