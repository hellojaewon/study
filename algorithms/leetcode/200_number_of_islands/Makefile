.DEFAULT:
all: number_of_islands.o
	g++ -o number_of_islands number_of_islands.o

number_of_islands.o: number_of_islands.cpp
	g++ -c number_of_islands.cpp -std=c++11

clean:
	rm number_of_islands
	rm *.o
