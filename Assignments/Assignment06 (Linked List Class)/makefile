FLAGS = -W -Wall -Werror -ansi -pedantic

main: main.cpp IntList.o
	g++ main.cpp IntList.o
	
IntList.o: IntList.cpp IntList.h
	g++ -c $(FLAGS) IntList.cpp
	
clean:
	rm a.out *.o