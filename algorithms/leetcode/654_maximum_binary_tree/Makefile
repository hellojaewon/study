.DEFAULT:
all: maximum_binary_tree.o
	g++ -o maximum_binary_tree maximum_binary_tree.o

maximum_binary_tree.o: maximum_binary_tree.cpp
	g++ -c -Werror -Wall maximum_binary_tree.cpp -std=c++11

clean:
	rm maximum_binary_tree
	rm *.o
