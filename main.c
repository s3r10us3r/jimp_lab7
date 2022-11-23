#include "skorowidz.h"

#include <stdio.h>
#include <stdlib.h>

void nowe_slowo(char *slow, slowo_t * res){
	res->slowo = slow;
	res->liczba_linii=0;
	res->linie = NULL;
}

int dodaj_linie(slowo_t *slowo, int numer){
	slowo->liczba_linii++;
	int *temp = realloc(slowo->linie, slowo->liczba_linii * sizeof(int*));
	if( temp != NULL){
		slowo->linie = temp;
		slowo->linie[slowo->liczba_linii-1]=numer;
		return 1;
	}
	else return 0;
}

void wypisz_skorowidz(slowo_t sk[], int rozmiar){
	int i = 0;
	int j = 0;
	for(i = 0; i<rozmiar; i++){
		if ( sk[i].liczba_linii > 0){
			printf( "słowo \"%s\" wystąpiło w liniach:", sk[i].slowo );
			for(j = 0; j < sk[i].liczba_linii; j++)
				printf( " %d", sk[i].linie[j]);
			printf( "\n");
		}
		else{
			printf("nie napotkano słowa \"%s\"\n", sk[i].slowo);
		}
	}
}
