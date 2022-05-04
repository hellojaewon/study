.DEFAULT:
all: maximal_square.o
	g++ -o maximal_square maximal_square.o

maximal_square.o: maximal_square.cpp
	g++ -c maximal_square.cpp -std=c++11

clean:
	rm maximal_square
	rm *.o
