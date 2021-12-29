CC = gcc
AR = ar
FLAGS = -Wall -g

make all: libgraph.so graph

libgraph.so: algo.o priorityQueue.o
	$(CC) -shared -o libgraph.so algo.o priorityQueue.o
	
main.o: algo.h main.c
	$(CC) $(FLAGS) -c main.c

priorityQueue.o: priorityQueue.h graph.h priorityQueue.c
	$(CC) $(FLAGS) -c priorityQueue.c

algo.o: algo.h graph.h priorityQueue.h priorityQueue.h algo.c
	$(CC) $(FLAGS) -c algo.c

graph: main.o libgraph.so
	$(CC) $(FLAGS) -o graph main.o ./libgraph.so

.PHONY: clean all
clean: 
	rm -f *.o *.so libgraph.so graph