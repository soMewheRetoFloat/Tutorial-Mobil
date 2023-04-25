CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

main: main.o try_graph.o node.o operation.o  mymap.o try_addition.o try_subtraction.o
	$(CC) $(CFLAGS) main.o try_graph.o node.o operation.o try_addition.o try_subtraction.o -o main

main.o: main.cpp graph.h
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) -c graph.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp

operation.o: operation.cpp operation.h
	$(CC) $(CFLAGS) -c operation.cpp

constant.o: constant.cpp constant.h
	$(CC) $(CFLAGS) -c constant.cpp

placeholder.o: placeholder.cpp placeholder.h
	$(CC) $(CFLAGS) -c placeholder.cpp

mymap.o: mymap.cpp mymap.h
	$(CC) $(CFLAGS) -c mymap.cpp

try_addition.o: try_addition.cpp try_addition.h
	$(CC) $(CFLAGS) -c addition.cpp

try_subtraction.o: try_subtraction.cpp try_subtraction.h
	$(CC) $(CFLAGS) -c subtraction.cpp

clean:
	rm -f *.o main
