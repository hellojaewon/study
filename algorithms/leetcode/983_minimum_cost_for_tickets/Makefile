.DEFAULT:
all: minimum_cost_for_tickets.o
	g++ -o minimum_cost_for_tickets minimum_cost_for_tickets.o

minimum_cost_for_tickets.o: minimum_cost_for_tickets.cpp
	g++ -c -Werror -Wall minimum_cost_for_tickets.cpp -std=c++11

clean:
	rm minimum_cost_for_tickets
	rm *.o
