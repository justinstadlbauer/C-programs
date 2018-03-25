CC = gcc
CFLAGS = -g -Wall
EXE = main

all:	$(EXE)

main: main.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o main
