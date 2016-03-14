# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include "head.h"

/*
*	Chiffremenet de texte en majuscule
*	Dechiffremenet de texte en miniscule
*/
char* cesar (char *txt,int k){
	int l = strlen(txt);
	char * c = malloc(sizeof(char)*l);
	int i=0;

	for(i=0;i<l;i++){
		//if(txt[i] == ' ') continue;
		if( *(txt+i) < 'a' )
		 *(c+i) = (*(txt+i)+k - 'A' ) % TAILLE + 'A';
		 else
		 	*(c+i) = (*(txt+i)+k - 'a' ) % TAILLE + 'A';
		}
	return c;
	}

char* dechiffre_cesar (char *c,int k){
	int l = strlen(c);
	char * txt = malloc(sizeof(char)*l);
	int i=0;
	for(i=0;i<l;i++)
		if( *(txt+i) > 'Z' )
		 *(txt+i) = (*(c+i) - k - 'a' ) % TAILLE + 'a';
		else
		 *(txt+i) = (*(c+i) - k - 'A' ) % TAILLE + 'a';
	return txt;
}


/*
int main(int arg,char **args){

char txt[] ="aujourd huit on est mercredi";

char *c = cesar(txt,3);
printf("texte chiffré :\n%s\n",c);
char *txt1 = dechiffre_cesar(c,3);
printf("texte dechiffré :\n%s\n",txt1);
}
*/
