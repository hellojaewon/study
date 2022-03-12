.DEFAULT:
all: arranging_coins.o
	g++ -o arranging_coins arranging_coins.o

arranging_coins.o: arranging_coins.cpp
	g++ -c arranging_coins.cpp -std=c++11

clean:
	rm arranging_coins
	rm *.o
