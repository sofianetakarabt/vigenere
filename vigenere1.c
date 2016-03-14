# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include "head.h"



int main(int arg,char **argv){
//vigenere1(argv[1],"cesar");
if (arg != 4){
	printf("Usage : ./vigenere fichier cle c/d pour chiffrer et dechiffrer\n");
	return 1;
}

char *cle = argv[2];
char *d = argv[3];

if (*d == 'c') vigenere1(argv[1],cle);
else dechiffre_vig1(argv[1],cle);

return 0;
}

//XSMSRXIRDVLEIUVNUMEJRSANKU

