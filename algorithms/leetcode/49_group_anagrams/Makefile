.DEFAULT:
all: group_anagrams.o
	g++ -o group_anagrams group_anagrams.o

group_anagrams.o: group_anagrams.cpp
	g++ -c group_anagrams.cpp -std=c++11

clean:
	rm group_anagrams
	rm *.o
