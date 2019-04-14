.DEFAULT:
all: range_sum_of_bst.o
	g++ -o range_sum_of_bst range_sum_of_bst.o

range_sum_of_bst.o: range_sum_of_bst.cpp
	g++ -c -Werror -Wall range_sum_of_bst.cpp -std=c++11

clean:
	rm range_sum_of_bst
	rm *.o
