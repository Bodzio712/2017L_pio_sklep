projekt: main.o
	gcc main.o paragon.o -o projekt

main.o: main.c
	gcc -c main.c

paragon.o: paragon.c
	gcc -c paragon.c paragon.h
