.DEFAULT:
all: jump_game.o
	g++ -o jump_game jump_game.o

jump_game.o: jump_game.cpp
	g++ -c jump_game.cpp -std=c++11

clean:
	rm jump_game
	rm *.o
