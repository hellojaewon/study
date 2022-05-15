.DEFAULT:
all: longest_substring_without_repeating_characters.o
	g++ -o longest_substring_without_repeating_characters longest_substring_without_repeating_characters.o

longest_substring_without_repeating_characters.o: longest_substring_without_repeating_characters.cpp
	g++ -c longest_substring_without_repeating_characters.cpp -std=c++11

clean:
	rm longest_substring_without_repeating_characters
	rm *.o
