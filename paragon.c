//
// Created by Damian on 2017-05-10.
//

#include <stdio.h>
#include <conio.h>
#include <windows.h>

float WypiszProdukt(int kod);

float WypiszProdukt(int kod){
    FILE * dane = fopen("BazaDanych.txt","r");

    int kodzik;
    char nazwa[100];
    float cena;
    while (fscanf(dane, "%s %d %f", &nazwa, &kodzik, &cena) != EOF){
        if (kod==kodzik) {
            printf("%d ", kodzik);
            printf("%s ", nazwa);
            printf("%.2f\n", cena);
            return cena;
        }
    }
    printf("Tego produktu nie ma w bazie!\n");
    return 0;
}

void Paragon(){

    //FILE * baza = fopen("BazaDanych.txt","r");
    //char * nazwaParagonu = "0012.txt";
    //FILE * paragon = fopen("0012.txt","w");
    int kod, ilosc;
    float cena;
    float suma = 0;
    float zaplata;

    while(getch() != 122) {
        printf("Wpisz kod produktui jego ilosc:\n");
        scanf("%d %d", &kod, &ilosc);
        cena = WypiszProdukt(kod) * ilosc;
        printf("%.2f\n",cena);
        suma += cena;
    }
    printf("Do zaplaty: %.2f zlotych\n", suma);
    printf("Zaplacono:");
    while(1<2) {
        scanf("%f", &zaplata);
        if (zaplata >= suma) {
            printf("\nReszta: %.2f zlotych\n", zaplata - suma);
            getch();
            return;
        } else {
            printf("Zaplacono zbyt malo\nBrakuje %.2f zlotych\n", -1 * (zaplata - suma));
            suma = suma - zaplata;
        }
    }
}
