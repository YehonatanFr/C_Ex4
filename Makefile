CC = gcc
Ar = ar
Flags = -Wall -g -ggdb3

all: graph

main.o: main.c graph.h
	$(CC) $(Flags) -fPIC -c main.c

edges.o: edges.c graph.h
	$(CC) $(Flags) -fPIC -c edges.c

nodes.o: nodes.c graph.h
	$(CC) $(Flags) -fPIC -c nodes.c

algo.o: algo.c graph.h
	$(CC) $(Flags) -fPIC -c algo.c

graph: edges.o nodes.o main.o algo.o
	$(CC) $(FLAGS) -o graph edges.o nodes.o main.o algo.o -lm

.PHONY: clean all

new: clean all

clean:
	rm  -f *.o graph

leakTest: clean graph
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./graph