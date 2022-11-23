#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

typedef struct{
	char * slowo;
	int liczba_linii;
	int * linie;
} slowo_t;

void nowe_slowo(char *slow, slowo_t * res);

int dodaj_linie(slowo_t *slowo, int numer);

void wypisz_skorowidz(slowo_t sk[], int rozmiar);

#endif
