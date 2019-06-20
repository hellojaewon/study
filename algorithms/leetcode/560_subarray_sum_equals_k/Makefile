.DEFAULT:
all: subarray_sum_equals_k.o
	g++ -o subarray_sum_equals_k subarray_sum_equals_k.o

subarray_sum_equals_k.o: subarray_sum_equals_k.cpp
	g++ -c subarray_sum_equals_k.cpp -std=c++11

clean:
	rm subarray_sum_equals_k
	rm *.o
