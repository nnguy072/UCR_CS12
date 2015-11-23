FLAGS = -W -Wall -Werror -ansi -pedantic

main: main.cpp IntVector.o
	g++ main.cpp IntVector.o
	
IntVector.o: IntVector.cpp IntVector.h
	g++ -c $(FLAGS) IntVector.cpp
	
clean:
	rm a.out *.o