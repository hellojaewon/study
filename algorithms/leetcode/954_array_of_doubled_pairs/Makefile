.DEFAULT:
all: array_of_doubled_pairs.o
	g++ -o array_of_doubled_pairs array_of_doubled_pairs.o

array_of_doubled_pairs.o: array_of_doubled_pairs.cpp
	g++ -c array_of_doubled_pairs.cpp -std=c++11

clean:
	rm array_of_doubled_pairs
	rm *.o
