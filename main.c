#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr

#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
    int i;
    char buf[BUFSIZE];
	slowo_t skorowidz[argc-2];
	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

   	int tmp;
    for( i= 2; i < argc; i++ ) {
		tmp=i;
		nowe_slowo(argv[i], &skorowidz[tmp-2]);
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
	char * slowo_z_bufa;
	char * delim =" ";
	char buf2[BUFSIZE] = "";
	int jest = 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		nr_linii++;
		jest = 0;
		buf[strlen(buf)-1]='\0';
		for( i= 0; i < argc-2; i++ ){
			strcpy(buf2, buf);
			slowo_z_bufa=strtok(buf2, delim);
			
			if( strcmp(slowo_z_bufa, skorowidz[i].slowo) == 0) {
					jest =1;	
				}
			while (slowo_z_bufa != NULL)
			{	
				if( strcmp(slowo_z_bufa, skorowidz[i].slowo) == 0) {
					jest =1;
				}
				slowo_z_bufa = strtok(NULL, delim) ;

			}
			if(slowo_z_bufa!=NULL) printf("%s ", slowo_z_bufa);
			if (jest == 1){
				if(dodaj_linie(&skorowidz[i], nr_linii)==0){
						fprintf(stderr, "Nie można reallocować pamięci \n");
					}
			}
			jest=0;
		}
		memset(buf2,0,sizeof(buf2));
	}

	wypisz_skorowidz(skorowidz, argc-2);
	
	return EXIT_SUCCESS;
}
