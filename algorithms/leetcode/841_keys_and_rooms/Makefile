.DEFAULT:
all: keys_and_rooms.o
	g++ -o keys_and_rooms keys_and_rooms.o

keys_and_rooms.o: keys_and_rooms.cpp
	g++ -c keys_and_rooms.cpp -std=c++11

clean:
	rm keys_and_rooms
	rm *.o
