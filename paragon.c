//
// Created by Damian on 2017-05-10.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>

void WypiszProdukt(char *kod);
int Paragon();

int main(){
    int i = Paragon();
}

void WypiszProdukt(char *kod){
    FILE * dane = fopen("BazaDanych.txt","r");

    char kodzik[3], *nazwa;
    double cena;
    while (fscanf(dane, "%s %s %d", &kodzik, &nazwa, &cena) != EOF){
        if ( strcmp(kodzik,kod)==0){
            printf("%s %s %f", *kodzik, *nazwa, cena);
            break;
        }
    }
}

int Paragon(){

    FILE * baza = fopen("BazaDanych.txt","r");
    //char * nazwaParagonu = "0012.txt";
    FILE * paragon = fopen("0012.txt","w");
    char fc;
    char kod[3];

    while(getch() != 27){
        //kod[0] = fc;
        kod[1] = (char)getch();
        kod[2] = (char)getch();
        printf("\n");
        WypiszProdukt(kod);
    }
    return 0;
}