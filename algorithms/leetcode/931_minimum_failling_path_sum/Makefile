.DEFAULT:
all: minimum_falling_path_sum.o
	g++ -o minimum_falling_path_sum minimum_falling_path_sum.o

minimum_falling_path_sum.o: minimum_falling_path_sum.cpp
	g++ -c minimum_falling_path_sum.cpp -std=c++11

clean:
	rm minimum_falling_path_sum
	rm *.o
