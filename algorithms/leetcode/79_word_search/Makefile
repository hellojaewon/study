.DEFAULT:
all: word_search.o
	g++ -o word_search word_search.o

word_search.o: word_search.cpp
	g++ -c word_search.cpp -std=c++11

clean:
	rm word_search
	rm *.o
