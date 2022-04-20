.DEFAULT:
all: partition_equal_subset_sum.o
	g++ -o partition_equal_subset_sum partition_equal_subset_sum.o

partition_equal_subset_sum.o: partition_equal_subset_sum.cpp
	g++ -c partition_equal_subset_sum.cpp -std=c++11

clean:
	rm partition_equal_subset_sum
	rm *.o
