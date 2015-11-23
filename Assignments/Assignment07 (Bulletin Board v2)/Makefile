COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
OBJS = BBoard.o Message.o User.o Reply.o Topic.o

main: main.cpp BBoard.o Message.o User.o Reply.o Topic.o
	$(COMPILE) $(FLAGS) main.cpp $(OBJS)
	
run: a.out test.txt BBoard.h Message.h User.h Reply.h Topic.h
	./a.out test.txt test2.txt

BBoard.o: BBoard.cpp BBoard.h
	$(COMPILE) -c $(FLAGS) BBoard.cpp

Message.o: Message.cpp Message.h
	$(COMPILE) -c $(FLAGS) Message.cpp
	
User.o: User.cpp User.h
	$(COMPILE) -c $(FLAGS) User.cpp
	
Topic.o: Topic.cpp Topic.h
	$(COMPILE) -c $(FLAGS) Topic.cpp

Reply.o: Reply.cpp Reply.h
	$(COMPILE) -c $(FLAGS) Reply.cpp

clean:
	rm a.out *.o