//
// Created by Damian on 2017-05-31.
//
#include <stdio.h>
#include <time.h>

#include "obsluga.h"

void dodajprac(){
    time_t czas;
    struct tm *data;
    char godzina[80];

    time(&czas);
    data = localtime(&czas);

    strftime(godzina, 80, "%c", data);

    char nazwa[10];
    printf("Podaj numer nowego pracownika(max 10 cyfr)\n");
    scanf("%s", &nazwa);
    FILE * pracownik = fopen(nazwa,"w");
    fprintf(pracownik, "Dodano %s.\n", godzina);
    fclose(pracownik);
}