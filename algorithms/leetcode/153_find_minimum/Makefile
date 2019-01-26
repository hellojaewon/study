.DEFAULT:
all: find_minimum.o
	g++ -o find_minimum find_minimum.o

find_minimum.o: find_minimum.cpp
	g++ -c find_minimum.cpp -std=c++11

clean:
	rm find_minimum
	rm *.o
