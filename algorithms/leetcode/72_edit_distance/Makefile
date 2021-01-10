.DEFAULT:
all: edit_distance.o
	g++ -o edit_distance edit_distance.o

edit_distance.o: edit_distance.cpp
	g++ -c edit_distance.cpp -std=c++11

clean:
	rm edit_distance
	rm *.o
