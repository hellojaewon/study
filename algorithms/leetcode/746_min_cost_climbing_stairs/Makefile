.DEFAULT:
all: min_cost_climbing_stairs.o
	g++ -o min_cost_climbing_stairs min_cost_climbing_stairs.o

min_cost_climbing_stairs.o: min_cost_climbing_stairs.cpp
	g++ -c min_cost_climbing_stairs.cpp -std=c++11

clean:
	rm min_cost_climbing_stairs
	rm *.o
