.DEFAULT:
all: two_keys_keyboard.o
	g++ -o two_keys_keyboard two_keys_keyboard.o

two_keys_keyboard.o: two_keys_keyboard.cpp
	g++ -c two_keys_keyboard.cpp -std=c++11

clean:
	rm two_keys_keyboard
	rm *.o
