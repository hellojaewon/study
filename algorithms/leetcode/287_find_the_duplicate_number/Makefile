.DEFAULT:
all: find_the_duplicate_number.o
	g++ -o find_the_duplicate_number find_the_duplicate_number.o

find_the_duplicate_number.o: find_the_duplicate_number.cpp
	g++ -c find_the_duplicate_number.cpp -std=c++11

clean:
	rm find_the_duplicate_number
	rm *.o
