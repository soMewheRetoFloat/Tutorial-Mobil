main: main.o graph.o node.o operation.o mymap.o operx.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o operx.o mymap.o
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h operx.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h operx.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h operx.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
operx.o: operx.cpp operx.h operation.h node.h
	g++ -c g++ -c -std=c++11 -o operx.o operx.cpp
mymap.o: mymap.cpp mymap.h operx.h
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
clear:
	del *.exe *.o