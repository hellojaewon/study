.DEFAULT:
all: score_of_parentheses.o
	g++ -o score_of_parentheses score_of_parentheses.o

score_of_parentheses.o: score_of_parentheses.cpp
	g++ -c score_of_parentheses.cpp -std=c++11

clean:
	rm score_of_parentheses
	rm *.o
