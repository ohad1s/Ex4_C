CC=gcc
FLAGS= -Wall -g

all:graph

graph: main.o libmy_graph.a
	$(CC) $(FLAGS) -o graph main.o libmy_graph.a

libmy_graph.a: graph_algo.o
	ar -rcs libmy_graph.a graph_algo.o

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

graph_algo.o: graph_algo.c graph.h
	$(CC) $(FLAGS) -c graph_algo.c

.PHONY: clean all

clean:
	rm -f *.o *.a graph