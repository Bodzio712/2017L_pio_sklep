//
// Created by Damian on 2017-05-10.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>

void WypiszProdukt(int kod);

void WypiszProdukt(int kod){
    FILE * dane = fopen("BazaDanych.txt","r");

    int kodzik;
    char nazwa[100];
    float cena;
    printf("checkpoint1\n");
    while (fscanf(dane, "%d %s %f", &kodzik, &nazwa[0], &cena) != EOF){
        printf("checkpoint1,5\n");
        if (kodzik==kod){
            printf("checkpoint2\n");
            printf("%d %s %f", kodzik, nazwa, cena);
        }
        else printf("cos nie pyklo");
    }
}

void Paragon(){

    FILE * baza = fopen("BazaDanych.txt","r");
    //char * nazwaParagonu = "0012.txt";
    //FILE * paragon = fopen("0012.txt","w");
    int kod;

    while(getch() != 27) {
        printf("Wpisz kod produktu:\n");
        scanf("%d", &kod);
        printf("\n");
        WypiszProdukt(kod);
    }
}