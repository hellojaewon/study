.DEFAULT:
all: path_sum.o
	g++ -o path_sum path_sum.o

path_sum.o: path_sum.cpp
	g++ -c path_sum.cpp -std=c++11

clean:
	rm path_sum
	rm *.o
