# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include "head.h"

/*
*	Chiffremenet de texte en majuscule
*	Dechiffremenet de texte en miniscule
*/
void cesar1 (char *file,int k){


FILE *f = fopen(file,"r");
char c = fgetc(f),tc;
	while(c!= EOF){
		if( c >='A' && c <='Z' ){
		 tc = (c + k - 'A' + TAILLE ) % TAILLE + 'A';
		 printf("%c",tc);
		}
		 else if( c >='a' && c <='z' ){
		 	tc = (c + k - 'a' + TAILLE ) % TAILLE + 'A';
			printf("%c",tc);
		}
	c= fgetc(f);
	}
}

void dechifre_cesar1 (char *file,int k){


FILE *f = fopen(file,"r");
char c = fgetc(f),td;
	while(c != EOF){
		if( c >='A' && c <='Z' ){
		 td = (c - k - 'A' + TAILLE ) % TAILLE + 'A';
		 printf("%c",td);
		}
		 else if( c >='a' && c <='z' ){
		 	td = (c - k - 'a' + TAILLE ) % TAILLE + 'A';
			printf("%c",td);
		}
		c= fgetc(f);
	}
}



int main(int argc,char **argv){

	if(argc != 4){
	fprintf(stdout,"usage: ./cesar1 fichier_in nombre_decalage c/d\n");
	return 1;
	}
	char *type=argv[3];
	if( *type == 'c')	cesar1(argv[1],atoi(argv[2]));
	else dechifre_cesar1(argv[1],atoi(argv[2]));
	printf("\n");
	
	return 0;
}

