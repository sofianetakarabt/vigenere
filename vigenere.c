# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include "head.h"

char * vigenere (char * txt,char *key){
	int l = strlen(txt);
	int lk = strlen(key);
	char * c = malloc(sizeof(char)*l);
	char *cc=c;
	int k=0;
	
while (*txt){
	if(k >= lk) k = 0;
	if( *txt < 'a' )
		*c = (*txt+key[k]-'a' - 'A' ) % TAILLE + 'A';
	else
		*c = (*txt+key[k] - 'a'-'a' ) % TAILLE + 'A';
	c++;txt++;k++;
	}
return cc;
} 

char * dechiffre_veg (char * c,char *key){
	int l = strlen(c);
	int lk = strlen(key);
	char * txt = malloc(sizeof(char)*l);
	char *t=txt;
	int k=0,i=0;
	
while (c[i]){
		if(k >= lk) k=0;
		if( *(txt+i) > 'Z' )
		 *txt = (*(c+i) - k - 'a' + 'A') % TAILLE + 'a';
		 else
		*txt = (*c-key[k] +TAILLE ) % TAILLE + 'a';
		i++;txt++;k++;
	}
return t;
}
/*
int main(int arg,char **args){
char txt[] ="vousavezdejaquelquespoints";
char key[] ="cesar";
char key1[] ="CESAR";
char *c = vigenere(txt,key);
printf("texte chiffré :\n%s\n",c);
char *txt1 =dechiffre_veg(c,key1);
printf("texte dechiffré :\n%s\n",txt1);
}
*/
//XSMSRXIRDVLEIUVNUMEJRSANKU
