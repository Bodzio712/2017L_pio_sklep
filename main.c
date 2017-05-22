#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


int main (int argc, char ** argv) {
	char znak;
    printf("Menu glowne:\n\n"
                   "Wybierz:\n"
                   "1 - wystawienie paragonu\n");
    znak = getch();
    if (znak == 49){
        printf("Wchodzisz w menu paragonu\n");
    else printf("Bledna komenda\n");
    Sleep(5000);
	return 0;
}
