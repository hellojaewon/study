.DEFAULT:
all: shortest_bridge.o
	g++ -o shortest_bridge shortest_bridge.o

shortest_bridge.o: shortest_bridge.cpp
	g++ -c shortest_bridge.cpp -std=c++11

clean:
	rm shortest_bridge
	rm *.o
