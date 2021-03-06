CC = g++
DEBUG = -g
CFLAGS = -Wall -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: main.out

main.out: main.o Sorting.o
	$(CC) $(CFLAGS) -o main.out main.o Sorting.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Sorting.o: Sorting.cpp Sorting.h
	$(CC) $(CFLAGS) -c Sorting.cpp

run: main.out
	./main.out

clean:
	rm *.o
	rm *.out
