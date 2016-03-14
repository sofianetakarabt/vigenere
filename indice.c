#include <stdio.h>
#include <stdlib.h>
#include "head.h"

float indice(char *file){

FILE *f = fopen(file,"r");
if(!f) {printf("Erreur de lecture de fichier %s\n",file);return -1;}
char c = fgetc(f);
float *rep=calloc(sizeof(float),TAILLE),l=0;int i;
while(c != EOF ){
	if(c<='z' && c >= 'a')
	rep[c-'a']++;
	else if(c<='Z' && c >= 'A')
	rep[c-'A']++;
	l++;
	c = fgetc(f);	
	}
	float r=0;
	for(i=0;i<TAILLE;i++){
		r = r + rep[i]*(rep[i]-1.0)/(l*(l-1.0));
	}
free(rep);
fclose(f);
return r;
}

float indice_ap(float freq[TAILLE]){
float f;
int i;
	for(i=0;i<TAILLE;i++) f+=freq[i]*freq[i];
return f/10000;
}
/*
int main(int arg,char **argv){

if(arg != 2){ printf("Usage : ./decryp_mono fichier_chiffre\n");
	return 1;
	}	
float freq[TAILLE];
frequence(argv[1],freq);
float f = indice(argv[1]),fa = indice_ap(freq);
	
printf("%f : %f \n",f,fa);
return 0;
}
*/
