#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define difference(x,y) (x<y) ? y-x :x-y
#define pourcentage(x,y) (x<y) ? y/x : x/y 

int comp(const void *a,const void *b){
return *(int*)a - *(int*)b;
}

void substitution(char *chiff,char a,char n){
char *t=chiff;
int i;
for(i=0;chiff[i];i++){
	if(chiff[i] == a || chiff[i] == a -'a' +'A') chiff[i]=n;
} 

}

void decry_man(float freq [TAILLE],char *chiff,float tab_freq_lang [TAILLE]){
	int i;
	char a,n;	
for(i=0;i<TAILLE;i++){
	printf("%c : %f\n",i+'a',freq[i]);
}

while(1){
 	printf("remplacer a par n:");
	scanf("%c %c",&a,&n);	
	substitution(chiff,a,n);
	printf("le texte dechiffré :\n%s\n",chiff);
	}
}

void decry_rap(char permute[TAILLE],float freq [TAILLE],char *chiff,float tab_freq_lang [TAILLE]){
	int i=7,j,ind1,ind2,ind3;
	char a,n;
//	char permute[TAILLE];
	float min1,min2;

for(i=0;i<TAILLE;i++){ // etirer dans freq
		ind1=-1;
		ind2=-1;
		ind3=-1;
		min1=difference(tab_freq_lang[0],freq[i]);
		min2=min1;
for(j=0;j<TAILLE;j++){ // chercher la frequence correspondante dans tab_freq_lang		

			min2 = difference(tab_freq_lang[j],freq[i]);
			if(min2 < min1) {
					min1 = min2;
					ind3 = ind2;
					ind2 = ind1;
					ind1 = j;
					}	
		}
		printf("min= %f la frequence de ( %c ) est proche de celle de (%c :) ",min1,i+'a',ind1+'a');
		if(ind2 > -1) printf("et (%c : %f %) ",ind2+'a',pourcentage(tab_freq_lang[ind2],freq[i]));
		if(ind3 > -1) printf("et (%c : %f %)",ind3+'a',pourcentage(tab_freq_lang[ind3],freq[i]));
		printf("\n");
		permute[i]=ind1+'a';
	}
	/*
	for(i=0;i<TAILLE;i++){
		printf("substituer a par n ");
		scanf("%c %c",&a,&n);
		permute[a-'a'] = n;
	}
	*/
}

char * dechiffre_mono (char *c,char perm[TAILLE]){
int l = strlen(c);
char * txt = malloc(sizeof(char)*l);
char *t=txt;

/*on construit la permutation inverse*/
char perm_inv [TAILLE];
int i ;
for(i=0;i<TAILLE;i++) perm_inv[perm[i] - 'a'] = i + 'a' ;

i=0;
while(*c){
	*txt = perm_inv[*c-'A'];
	c++;txt++;
	}
return t;
}

int main(int arg,char ** argv){

if(arg != 2){ printf("Usage : ./decryp_mono fichier_chiffre\n");
	return 1;
	}	


char permute[TAILLE];

char *chiffre = argv[1];
float TAB_FREQ_FR1 []= {0.092134,0.010354,0.030179,0.037537,0.171747,0.010939,0.010615,0.010718,0.075072,0.003833,0.000070,0.061368,0.026499,0.070308,0.049141,0.023698,0.010160,0.066093,0.078168,0.073743,0.063562,0.016451,0.000011,0.004072,0.002300,0.001226};

float freq[TAILLE];


	int key;
	frequence(chiffre,freq);
	
	decry_rap(permute,freq,chiffre,TAB_FREQ_FR1);
	
	char * text=dechiffre_mono(chiffre,permute);
	printf("texte dechiffré :\n%s\n",text);
	

return 0;
}

