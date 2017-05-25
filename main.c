#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "paragon.h"

void menu();

int main (int argc, char ** argv) {
    menu();
    return 0;
}

void menu(){
    char znak;
    printf("Menu glowne:\n\n"
                   "Wybierz:\n"
                   "1 - wystawienie paragonu\n"
                   "ESC - wyjscie z programu\n");
    znak = getch();
    if (znak == 49) {
        printf("Wchodzisz w menu paragonu\n");
        Paragon();
    }
    else if(znak == 27)
        return;
    else printf("Bledna komenda\n");
    Sleep(5000);
}