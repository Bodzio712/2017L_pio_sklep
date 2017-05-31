//
// Created by Damian on 2017-05-31.
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "paragon.h"
#include "wyplata.h"
#include "obsluga.h"
#include "menu.h"


void menu(){
    char znak;
    while (1<2) {
        printf("Menu glowne:\n\n"
                       "Wybierz:\n"
                       "1 - wystawienie paragonu\n"
                       "2 - Obsluga pracownikow\n"
                       "ESC - wyjscie z programu\n");
        znak = getch();
        if (znak == 49) {
            printf("Wchodzisz w menu paragonu\n");
            Paragon();
        }else if(znak == 50){
            menuprac();
        }
        else if (znak == 27)
            return;
        else printf("Bledna komenda\n");
    }
    Sleep(5000);
}


void menuprac(){
    char znaczek;
    while(1<2) {
        printf("Wybierz\n"
                       "1 - dodaj pracownika\n"
                       "2 - oblicz wyplate\n"
                       "ESC = powrot\n");
        znaczek = getch();
        if (znaczek == 49) {
            printf("Dodaj pracownika\n");
            dodajprac();
        } else if (znaczek == 50) {
            wyplata();
        } else if (znaczek == 27) {
            return;
        }
    }
}