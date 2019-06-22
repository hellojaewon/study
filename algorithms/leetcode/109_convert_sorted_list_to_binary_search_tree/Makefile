.DEFAULT:
all: convert_sorted_list_to_binary_search_tree.o
	g++ -o convert_sorted_list_to_binary_search_tree convert_sorted_list_to_binary_search_tree.o

convert_sorted_list_to_binary_search_tree.o: convert_sorted_list_to_binary_search_tree.cpp
	g++ -c convert_sorted_list_to_binary_search_tree.cpp -std=c++11

clean:
	rm convert_sorted_list_to_binary_search_tree
	rm *.o
