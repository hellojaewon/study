.DEFAULT:
all: k_closest_points_to_origin.o
	g++ -o k_closest_points_to_origin k_closest_points_to_origin.o

k_closest_points_to_origin.o: k_closest_points_to_origin.cpp
	g++ -c k_closest_points_to_origin.cpp -std=c++11

clean:
	rm k_closest_points_to_origin
	rm *.o
