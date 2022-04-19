.DEFAULT:
all: matchsticks_to_square.o
	g++ -o matchsticks_to_square matchsticks_to_square.o

matchsticks_to_square.o: matchsticks_to_square.cpp
	g++ -c matchsticks_to_square.cpp -std=c++11

clean:
	rm matchsticks_to_square
	rm *.o
