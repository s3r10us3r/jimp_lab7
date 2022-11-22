#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr

#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
    int i;
    char buf[BUFSIZE];
	slowo_t *skorowidz[argc-2];
	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

   	int tmp;
    for( i= 2; i < argc; i++ ) {
		tmp=i;
		skorowidz[tmp-2]=nowe_slowo(argv[i]);
	}
	if( argc-2==0 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}
	int nr_linii = 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		nr_linii++;
		for( i= 0; i < argc-2; i++ )
			if( strstr( buf, skorowidz[i]->slowo ) != NULL ) {
				if(dodaj_linie(skorowidz[i], nr_linii)==0){
					fprintf(stderr, "Nie można reallocować pamięci");
				}
			}
	}

	wypisz_skorowidz(skorowidz, argc-2);
	
	return EXIT_SUCCESS;
}
