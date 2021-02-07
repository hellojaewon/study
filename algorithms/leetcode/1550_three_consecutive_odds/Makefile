.DEFAULT:
all: three_consecutive_odds.o
	g++ -o three_consecutive_odds three_consecutive_odds.o

three_consecutive_odds.o: three_consecutive_odds.cpp
	g++ -c three_consecutive_odds.cpp -std=c++11

clean:
	rm three_consecutive_odds
	rm *.o
