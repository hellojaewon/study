.DEFAULT:
all: interleaving_string.o
	g++ -o interleaving_string interleaving_string.o

interleaving_string.o: interleaving_string.cpp
	g++ -c interleaving_string.cpp -std=c++11

clean:
	rm interleaving_string
	rm *.o
