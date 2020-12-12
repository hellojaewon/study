.DEFAULT:
all: swap_nodes_in_pairs.o
	g++ -o swap_nodes_in_pairs swap_nodes_in_pairs.o

swap_nodes_in_pairs.o: swap_nodes_in_pairs.cpp
	g++ -c swap_nodes_in_pairs.cpp -std=c++11

clean:
	rm swap_nodes_in_pairs
	rm *.o
