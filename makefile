CC=gcc
CFLAG=-Wall
MYBANK=myBank.h

all:main.o myBank.o
	$(CC) $(CFLAG) *.o  -lmyBank -L. -o Ex2

main.o:main.c libmyBank.a
	$(CC) $(CFLAG) -c -o main.o main.c -I. 

libmyBank.a:myBank.o
	ar rcs $@ myBank.o -o

myBank.o:myBank.c $(MYBANK)
	$(CC) $(CFLAG) -c myBank.c

clean:
	rm -f *.o *.a Ex2

.PHONY:clean all