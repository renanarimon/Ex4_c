CC = gcc
AR = ar
FLAGS = -Wall -g

make all: libgraph.so graph

libgraph.so: algo.o
	$(CC) -shared -o libgraph.so algo.o
	
main.o: algo.h main.c
	$(CC) $(FLAGS) -c main.c

nodes.o: nodes.h nodes.c
	$(CC) $(FLAGS) -c nodes.c
edges.o: edges.h edges.c
	$(CC) $(FLAGS) -c edges.c

algo.o: algo.h graph.h algo.c nodes.o edges.o 
	$(CC) $(FLAGS) -c algo.c

graph: main.o libgraph.so
	$(CC) $(FLAGS) -o graph main.o ./libgraph.so

.PHONY: clean all
clean: 
	rm -f *.o *.so libgraph.so graph