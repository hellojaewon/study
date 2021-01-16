.DEFAULT:
all: house_robber.o
	g++ -o house_robber house_robber.o

house_robber.o: house_robber.cpp
	g++ -c house_robber.cpp -std=c++11

clean:
	rm house_robber
	rm *.o
