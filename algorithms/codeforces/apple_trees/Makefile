.DEFAULT:
all: apple.o
	g++ -o apple apple.o

apple.o: apple.cpp
	g++ -c apple.cpp -std=c++11

clean:
	rm apple
	rm *.o
