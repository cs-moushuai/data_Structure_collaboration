CC=g++
CFLAGS=-Wall

main: main.o functions.o
	$(CC)  main.o functions.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
functions.o:functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o
clean:
	rm -rf *.o
