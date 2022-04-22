.DEFAULT:
all: merge_sorted_array.o
	g++ -o merge_sorted_array merge_sorted_array.o

merge_sorted_array.o: merge_sorted_array.cpp
	g++ -c merge_sorted_array.cpp -std=c++11

clean:
	rm merge_sorted_array
	rm *.o
