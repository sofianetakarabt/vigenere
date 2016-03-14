#include <stdio.h>
#include <stdlib.h>
#include "head.h"

/*⁼
*quand la clés est superieure a 2
*/



int main(int arg,char **argv){
if(arg != 2) {printf("Usage:./key_len fichier_chiffre\n");return -1;}
int n ;

printf("Entrer la longueur maximale de la clé: ");
scanf("%d",&n);
len_proba(argv[1],n);
printf("Entrer la longuer: ");
scanf("%d",&n);
char *s = malloc (sizeof(char)*n);
s = key (argv[1],n);
printf("la trouvé est : (%s)\n",s);
printf("entrer la clés : ");
scanf("%s",s);
printf("la clés choisie est: %s d \n",s);
char cle[] = "sofiane";
dechiffre_vig1(argv[1],cle);
return 0;
}


