.DEFAULT:
all: longest_repeating_character_replacement.o
	g++ -o longest_repeating_character_replacement longest_repeating_character_replacement.o

longest_repeating_character_replacement.o: longest_repeating_character_replacement.cpp
	g++ -c longest_repeating_character_replacement.cpp -std=c++11

clean:
	rm longest_repeating_character_replacement
	rm *.o
