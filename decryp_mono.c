#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#define difference(x,y) (x<y) ? y-x :x-y
#define pourcentage(x,y) (x<y) ? y/x : x/y 

/*Compilation :gcc -o deryp_mono decryp_mono.c frequence.c
* execution ./decry_mono texte_chiffré
*/


// on mit la clés de chiffremlent dans key : pour déchiffrer on soustrait key

void decry_rap_cesar(int *key,float freq [TAILLE],float tab_freq_lang [TAILLE]){
	int i,ind1=0,ind2=0;
	float max1=0,max2=0;

for(i=0;i<TAILLE;i++){ // etirer dans freq
	if(max1 < freq[i] ){
		max1 = freq[i];
		ind1 = i;
		}
	if (max2 < tab_freq_lang[i]){
		max2 = tab_freq_lang[i];
		ind2=i;
		}
	}
	*key = (ind1 - ind2  + TAILLE )%TAILLE ;
}

int main(int arg,char ** argv){

if(arg != 2){ printf("Usage : ./decryp_mono fichier_chiffre\n");
	return 1;
	}	
float *TAB_FREQ_FR = malloc(sizeof(float)*TAILLE);

float TAB_FREQ_FR1 []= {0.092134,0.010354,0.030179,0.037537,0.171747,0.010939,0.010615,0.010718,0.075072,0.003833,0.000070,0.061368,0.026499,0.070308,0.049141,0.023698,0.010160,0.066093,0.078168,0.073743,0.063562,0.016451,0.000011,0.004072,0.002300,0.001226};
	//qsort(TAB_FREQ,FR,TAILLE,sizeof(float),comp);	

TAB_FREQ_FR=TAB_FREQ_FR1;
int i;
for(i=0;i<TAILLE;i++) TAB_FREQ_FR[i]*=100.0;

	FILE *f = fopen(argv[1],"r");
	float *freq = malloc(sizeof(float)*TAILLE);
	int key;
	frequence(argv[1],freq);
	char *chiff = malloc(sizeof(char)*255);
	fgets(chiff,255,f);	
	decry_rap_cesar(&key,freq,TAB_FREQ_FR);
	printf("le texte chiffre:\n%s\n",chiff);
	char * dech = dechiffre_cesar(chiff,key);
	printf("le texte dechiffre:\n%s\n",dech);
return 0;
}

