CC = gcc
Ar = ar
Flags = -Wall -g

all: graph

main.o: main.c graph.h
	$(CC) $(Flags) -fPIC -c main.c

edges.o: edges.c graph.h
	$(CC) $(Flags) -fPIC -c edges.c

nodes.o: nodes.c graph.h
	$(CC) $(Flags) -fPIC -c nodes.c

graph: main.o edges.o nodes.o
	$(CC) $(FLAGS) -o graph main.o edges.o nodes.o -lm

.PHONY: clean all

new: clean all

clean:
	rm  -f *.o graph

leakTest: clean graph
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./graph