COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
OBJS = BBoard.o Message.o User.o

main: main.cpp BBoard.o Message.o User.o
	$(COMPILE) $(FLAGS) main.cpp $(OBJS)
	
run: a.out test.txt BBoard.h Message.h User.h
	./a.out test.txt BBoard.h Message.h User.h

BBoard.o: BBoard.cpp BBoard.h
	$(COMPILE) -c $(FLAGS) BBoard.cpp

Message.o: Message.cpp Message.h
	$(COMPILE) -c $(FLAGS) Message.cpp
	
User.o: User.cpp User.h
	$(COMPILE) -c $(FLAGS) User.cpp
	
clean:
	rm a.out *.o