.DEFAULT:
all: fruit_into_baskets.o
	g++ -o fruit_into_baskets fruit_into_baskets.o

fruit_into_baskets.o: fruit_into_baskets.cpp
	g++ -c fruit_into_baskets.cpp -std=c++11

clean:
	rm fruit_into_baskets
	rm *.o
