.DEFAULT:
all: find_pivot_index.o
	g++ -o find_pivot_index find_pivot_index.o

find_pivot_index.o: find_pivot_index.cpp
	g++ -c find_pivot_index.cpp -std=c++11

clean:
	rm find_pivot_index
	rm *.o
