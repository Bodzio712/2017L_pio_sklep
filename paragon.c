//
// Created by Damian on 2017-05-10.
//

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

float WypiszProdukt(FILE * paragon, int kod){
    FILE * dane = fopen("C:\\Users\\Damian\\CLionProjects\\2017L_pio_sklep\\BazaDanych.txt","r");

    int kodzik;
    char nazwa[100];
    float cena;
    while (fscanf(dane, "%s %d %f", &nazwa, &kodzik, &cena) != EOF){
        if (kodzik==kod) {
            printf("%d ", kodzik);
            printf("%s ", nazwa);
            printf("%.2f\n", cena);
            fprintf(paragon, "%15s ", nazwa);
            fprintf(paragon, "%8.2f ", cena);
            return cena;
        }
    }
    printf("Tego produktu nie ma w bazie!\n");
    return 0;
}

void Paragon(){

    int kod, ilosc;
    float cena;
    float suma = 0;
    float zaplata;

    time_t czas;
    struct tm * data;
    char godzina[ 80 ];

    time( & czas );
    data = localtime( & czas );

    strftime( godzina, 80, "%c", data );

    FILE * paragon = fopen("paragony.txt","a");
    printf("%s\n", godzina);
    fprintf(paragon, "%s\n", godzina);
    fprintf(paragon, "%15s  Cena/jedn Ilosc    Cena\n", "Nazwa");
    while(getch() != 27) {
        printf("Wpisz kod produktu i jego ilosc:\n");
        scanf("%d %d", &kod, &ilosc);
        cena = WypiszProdukt(paragon, kod) * ilosc;
        printf("%.2f\n",cena);
        if (cena != 0)
            fprintf(paragon, "%6d\t%8.2f\n", ilosc, cena);
        suma += cena;
    }
    fprintf(paragon, "SUMA: %.2f\n\n\n\n", suma);
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
    fclose(paragon);
}
