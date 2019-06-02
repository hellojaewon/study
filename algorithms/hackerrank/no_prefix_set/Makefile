.DEFAULT:
all: no_prefix_set.o
	g++ -o no_prefix_set no_prefix_set.o

no_prefix_set.o: no_prefix_set.cpp
	g++ -c -Werror -Wall no_prefix_set.cpp -std=c++11

clean:
	rm no_prefix_set
	rm *.o
