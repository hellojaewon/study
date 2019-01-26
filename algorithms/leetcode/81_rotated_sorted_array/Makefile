.DEFAULT:
all: rotated_sorted_array.o
	g++ -o rotated_sorted_array rotated_sorted_array.o

rotated_sorted_array.o: rotated_sorted_array.cpp
	g++ -c rotated_sorted_array.cpp -std=c++11

clean:
	rm rotated_sorted_array
	rm *.o
