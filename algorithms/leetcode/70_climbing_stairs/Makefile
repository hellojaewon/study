.DEFAULT:
all: climbing_stairs.o
	g++ -o climbing_stairs climbing_stairs.o

climbing_stairs.o: climbing_stairs.cpp
	g++ -c climbing_stairs.cpp -std=c++11

clean:
	rm climbing_stairs
	rm *.o
