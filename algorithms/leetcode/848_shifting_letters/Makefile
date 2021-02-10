.DEFAULT:
all: shifting_letters.o
	g++ -o shifting_letters shifting_letters.o

shifting_letters.o: shifting_letters.cpp
	g++ -c shifting_letters.cpp -std=c++11

clean:
	rm shifting_letters
	rm *.o
