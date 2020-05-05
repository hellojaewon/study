.DEFAULT:
all: deepest_leaves_sum.o
	g++ -o deepest_leaves_sum deepest_leaves_sum.o

deepest_leaves_sum.o: deepest_leaves_sum.cpp
	g++ -c deepest_leaves_sum.cpp -std=c++11

clean:
	rm deepest_leaves_sum
	rm *.o
