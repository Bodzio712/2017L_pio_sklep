projekt: main.o
	gcc main.o -o projekt

main.o: main.c
	gcc -c main.c
