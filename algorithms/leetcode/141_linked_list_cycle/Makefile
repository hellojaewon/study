.DEFAULT:
all: linked_list_cycle.o
	g++ -o linked_list_cycle linked_list_cycle.o

linked_list_cycle.o: linked_list_cycle.cpp
	g++ -c linked_list_cycle.cpp -std=c++11

clean:
	rm linked_list_cycle
	rm *.o
