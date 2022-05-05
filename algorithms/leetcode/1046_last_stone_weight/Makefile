.DEFAULT:
all: last_stone_weight.o
	g++ -o last_stone_weight last_stone_weight.o

last_stone_weight.o: last_stone_weight.cpp
	g++ -c last_stone_weight.cpp -std=c++11

clean:
	rm last_stone_weight
	rm *.o
