//
// Created by Damian on 2017-05-31.
//
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "wyplata.h"

void wyplata(){

    time_t czas;
    struct tm *data;
    char godzina[80];

    time(&czas);
    data = localtime(&czas);

    strftime(godzina, 80, "%c", data);

    char nazwa[10];
    float stawka, godziny, suma;
    printf("Podaj numer pracownika\n");
    scanf("%s", &nazwa);
    printf("Podaj ilosc przepracowanych godzin\n");
    scanf("%f", &godziny);
    printf("Podaj stawke za godzine\n");
    scanf("%f", &stawka);
    suma = stawka * godziny;
    printf("Pracownikowi nalezy sie %.2f wyplaty\n", suma);
    FILE * pracownik = fopen(nazwa,"a");
    fprintf(pracownik,"Dnia %s wyplacono %.2f zlotych.\n",godzina,suma);
    fclose(pracownik);
    Sleep(5000);
}
