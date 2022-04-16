.DEFAULT:
all: find_eventual_safe_states.o
	g++ -o find_eventual_safe_states find_eventual_safe_states.o

find_eventual_safe_states.o: find_eventual_safe_states.cpp
	g++ -c find_eventual_safe_states.cpp -std=c++11

clean:
	rm find_eventual_safe_states
	rm *.o
