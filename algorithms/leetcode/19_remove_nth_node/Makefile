.DEFAULT:
all: remove_nth_node.o
	g++ -o remove_nth_node remove_nth_node.o

remove_nth_node.o: remove_nth_node.cpp
	g++ -c remove_nth_node.cpp -std=c++11

clean:
	rm remove_nth_node
	rm *.o
