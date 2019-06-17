.DEFAULT:
all: smallest_string_starting_from_leaf.o
	g++ -o smallest_string_starting_from_leaf smallest_string_starting_from_leaf.o

smallest_string_starting_from_leaf.o: smallest_string_starting_from_leaf.cpp
	g++ -c smallest_string_starting_from_leaf.cpp -std=c++11

clean:
	rm smallest_string_starting_from_leaf
	rm *.o
