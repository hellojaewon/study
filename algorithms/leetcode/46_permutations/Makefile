.DEFAULT:
all: permutations.o
	g++ -o permutations permutations.o

permutations.o: permutations.cpp
	g++ -c permutations.cpp -std=c++11

clean:
	rm permutations
	rm *.o
