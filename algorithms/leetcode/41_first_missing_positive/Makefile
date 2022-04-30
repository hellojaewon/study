.DEFAULT:
all: first_missing_positive.o
	g++ -o first_missing_positive first_missing_positive.o

first_missing_positive.o: first_missing_positive.cpp
	g++ -c first_missing_positive.cpp -std=c++11

clean:
	rm first_missing_positive
	rm *.o
