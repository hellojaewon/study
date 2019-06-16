.DEFAULT:
all: rotate_list.o
	g++ -o rotate_list rotate_list.o

rotate_list.o: rotate_list.cpp
	g++ -c rotate_list.cpp -std=c++11

clean:
	rm rotate_list
	rm *.o
