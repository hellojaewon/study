.DEFAULT:
all: delete_node_in_a_bst.o
	g++ -o delete_node_in_a_bst delete_node_in_a_bst.o

delete_node_in_a_bst.o: delete_node_in_a_bst.cpp
	g++ -c delete_node_in_a_bst.cpp -std=c++11

clean:
	rm delete_node_in_a_bst
	rm *.o
