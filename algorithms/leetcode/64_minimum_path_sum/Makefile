.DEFAULT:
all: minimum_path_sum.o
	g++ -o minimum_path_sum minimum_path_sum.o

minimum_path_sum.o: minimum_path_sum.cpp
	g++ -c minimum_path_sum.cpp -std=c++11

clean:
	rm minimum_path_sum
	rm *.o
