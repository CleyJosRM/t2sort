dev: clean all run

all: main.o sorts.o
	gcc main.o sorts.o -o main -std=c99 -Wall

main.o:
	gcc -c main.c -o main.o -std=c99 -Wall

sorts.o:
	gcc -c sorts.c -o sorts.o -std=c99 -Wall

run:
	./main

clean:
	rm -f *.o main