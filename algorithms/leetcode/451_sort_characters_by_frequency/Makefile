.DEFAULT:
all: sort_characters_by_frequency.o
	g++ -o sort_characters_by_frequency sort_characters_by_frequency.o

sort_characters_by_frequency.o: sort_characters_by_frequency.cpp
	g++ -c sort_characters_by_frequency.cpp -std=c++11

clean:
	rm sort_characters_by_frequency
	rm *.o
