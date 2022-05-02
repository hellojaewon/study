.DEFAULT:
all: maximum_product_subarray.o
	g++ -o maximum_product_subarray maximum_product_subarray.o

maximum_product_subarray.o: maximum_product_subarray.cpp
	g++ -c maximum_product_subarray.cpp -std=c++11

clean:
	rm maximum_product_subarray
	rm *.o
