all: main.o sorts.o tmp.o
	gcc main.o sorts.o tmp.o -o main -std=c99 -Wall

main.o:
	gcc -c main.c -o main.o -std=c99 -Wall

sorts.o:
	gcc -c sorts.c -o sorts.o -std=c99 -Wall

tmp.o:
	gcc -c tmp.c -o tmp.o -std=c99 -Wall

run:
	./main

clean:
	rm -f *.o main