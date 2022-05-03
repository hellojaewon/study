.DEFAULT:
all: car_pooling.o
	g++ -o car_pooling car_pooling.o

car_pooling.o: car_pooling.cpp
	g++ -c car_pooling.cpp -std=c++11

clean:
	rm car_pooling
	rm *.o
