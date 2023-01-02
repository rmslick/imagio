CC=gcc
CFLAGS=-I.

main: main.o pgmlib.o
	$(CC) -o main main.o pgmlib.o