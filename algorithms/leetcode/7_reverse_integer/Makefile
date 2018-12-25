.DEFAULT:
all: reverse_integer.o
	g++ -o reverse_integer reverse_integer.o

reverse_integer.o: reverse_integer.cpp
	g++ -c reverse_integer.cpp -std=c++11

clean:
	rm reverse_integer
	rm *.o
