#include <stdio.h>

void odczyt (FILE * plik, float ** tab) {
	fopen (plik, "r");
	while (fscanf (plik, "%f", &tab[i]) != EOF)
		i++;
	fclose(plik);
}
