.DEFAULT:
all: delete_and_earn.o
	g++ -o delete_and_earn delete_and_earn.o

delete_and_earn.o: delete_and_earn.cpp
	g++ -c delete_and_earn.cpp -std=c++11

clean:
	rm delete_and_earn
	rm *.o
