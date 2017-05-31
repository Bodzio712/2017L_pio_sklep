//
// Created by Damian on 2017-05-31.
//
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "test.h"

float zaokraglij(float x){
    int y = x * 1000; // przesuwamy przecinek o 4 miejsca i pozbywamy sie reszty za przecinkiem - y jest calkowite
    if (y % 10 >= 5) y += 10; // jezeli cyfra jednosci >= 5
    return (y / 10) * 0.01; // usuwamy ostatnia cyfre i zamieniamy na liczbe zmiennoprzecinkowa
}

void test(){
    //w konsoli testujemy kupno 2 produktów z kodem 1, 4 z kodem 5
    // oraz 1 z kodem 15 - nie ma takiego kodu
    char test[50];
    char test2[50];
    char test3[50];
    char test4[50];
    int ilosc;
    int wskaznik = 0;
    float cena, suma;
    float cena1 = 2.19, cena2 = 14.99;
    float suma1 = 4.38, suma2 = 59.96, suma3 = 64.34;
    FILE * paragon = fopen("C:\\Users\\Damian\\CLionProjects\\2017L_pio_sklep\\cmake-build-debug\\0012.txt","r");
    fscanf(paragon,"%s %s", &test, &test2);
    printf("%s \n",test);
    fscanf(paragon,"%s %s %s %s",&test, &test2, &test3, &test4);
    printf("%s %s %s %s\n", test, test2, test3, test4);
    if(strcmp(test,"Nazwa")==0 && strcmp(test2,"Cena/jedn")==0 && strcmp(test3,"Ilosc")==0 && strcmp(test4,"Cena")==0)
        wskaznik += 1;
    fscanf(paragon, "%s %f %d %f", &test, &cena, &ilosc, &suma);
    printf("%s %f %d %f\n", test, cena, ilosc, zaokraglij(suma));
    if (strcmp(test, "mleko")==0) {
        if (cena == cena1) {
            if (ilosc == 2) {
                if (zaokraglij(suma) == suma1) {
                    wskaznik += 1;
                }
            }
        }
    }
    fscanf(paragon, "%s %f %d %f", &test, &cena, &ilosc, &suma);
    printf("%s %f %d %f\n", test, cena, ilosc, zaokraglij(suma));
    if (strcmp(test, "papierosy")==0) {
        if (cena == cena2) {
            if (ilosc == 4) {
                if (zaokraglij(suma) == suma2) {
                    wskaznik += 1;
                }
            }
        }
    }
    fscanf(paragon,"%s %f", &test, &suma);
    printf("%s %f\n", test, zaokraglij(suma));
    if (strcmp(test,"SUMA:")==0 && zaokraglij(suma) == suma3)
        wskaznik+=1;
    if (wskaznik==4)
        printf("Zgadza sie\n");
    Sleep(5000);
    return;
};