all: userInput

CFLAGS=-g -Wall -std=c11

all: userInput

userInput: userInput.o Node.o T9DT.o
	gcc $(CFLAGS) -o userInput userInput.o Node.o T9DT.o

userInput.o: userInput.c T9DT.h Node.h
	gcc $(CFLAGS) -c userInput.c

Node.o: Node.c Node.h
	gcc $(CFLAGS) -c Node.c

T9DT.o: T9DT.c T9DT.h Node.h
	gcc $(CFLAGS) -c T9DT.c
clean:
	rm *.o
cleanall:
	rm *.o userInput
