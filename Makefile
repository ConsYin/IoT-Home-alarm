CC=gcc
CFLAGS=-lWarn -pedantic

tester: pintester.o libmyifttt.a
	cc pintester.o -L. -lwiringPi  -lmyifttt -lcurl -o pintester

pintester: pintester.o 
	cc pintester.o -lwiringPi -o pintester

blink: blink.o 
	cc blink.o -lwiringPi -o blink

button: button.o 
	cc button.o -lwiringPi -o button

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

all:	tester pintester blink button

clean:
	rm tester pintester *.o
