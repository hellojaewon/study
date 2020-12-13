.DEFAULT:
all: all_paths_from_source_to_target.o
	g++ -o all_paths_from_source_to_target all_paths_from_source_to_target.o

all_paths_from_source_to_target.o: all_paths_from_source_to_target.cpp
	g++ -c all_paths_from_source_to_target.cpp -std=c++11

clean:
	rm all_paths_from_source_to_target
	rm *.o
