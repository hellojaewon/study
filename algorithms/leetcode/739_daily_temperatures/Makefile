.DEFAULT:
all: daily_temperatures.o
	g++ -o daily_temperatures daily_temperatures.o

daily_temperatures.o: daily_temperatures.cpp
	g++ -c daily_temperatures.cpp -std=c++11

clean:
	rm daily_temperatures
	rm *.o
