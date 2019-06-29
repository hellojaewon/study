.DEFAULT:
all: subtree_of_another_tree.o
	g++ -o subtree_of_another_tree subtree_of_another_tree.o

subtree_of_another_tree.o: subtree_of_another_tree.cpp
	g++ -c subtree_of_another_tree.cpp -std=c++11

clean:
	rm subtree_of_another_tree
	rm *.o
