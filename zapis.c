#include <stdio.h>

void zapis (FILE *plik, float zmienna) {
	fopen(plik, "a");
	fprintf(plik, "%f", zmienna);
	fclose(plik);
}
