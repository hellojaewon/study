.DEFAULT:
all: rotate_string.o
	g++ -o rotate_string rotate_string.o

rotate_string.o: rotate_string.cpp
	g++ -c rotate_string.cpp -std=c++11

clean:
	rm rotate_string
	rm *.o
