//
// Created by Damian on 2017-05-10.
//

#include <stdio.h>
#include <conio.h>

float WypiszProdukt(int kod);

float WypiszProdukt(int kod){
    FILE * dane = fopen("BazaDanych.txt","r");

    int kodzik;
    char nazwa[100];
    float cena;
    while (fscanf(dane, "%s %d %f", &nazwa, &kodzik, &cena) != EOF){
        if (kod==kodzik) {
            printf("%d %s %.2f\n", kodzik, nazwa, cena);
            return cena;
        }
    }
}

void Paragon(){

    FILE * baza = fopen("BazaDanych.txt","r");
    //char * nazwaParagonu = "0012.txt";
    //FILE * paragon = fopen("0012.txt","w");
    int kod, ilosc;
    float cena;
    float suma = 0;
    float zaplata;

    while(getch() != 27) {
        printf("Wpisz kod produktui jego ilosc:\n");
        scanf("%d %d", &kod, &ilosc);
        printf("\n");
        cena = WypiszProdukt(kod) * ilosc;
        suma += cena;
    }
    printf("Do zaplaty: %f\n", suma);
    printf("Zaplacono:");
    scanf("%f", &zaplata);
    printf("\nReszta: %f\n",zaplata - suma);
    return;
}