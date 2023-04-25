all: test.exe

test.exe: exp.o Move.o Move.h
	g++ exp.o Move.o -o test.exe

%.o: %.cpp Move.h
	g++ -c $< -o $@ 

clear:
	del *.o
	del test.exe