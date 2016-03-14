# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include "head.h"

// pour afficher les courbes: gnuplot --persist -e 'plot [-1:7] [-3:3] "plot" using 1:2 with lines title "Frequence";' !!

void frequence(char *file,float freq[TAILLE]){
FILE * f = fopen(file,"r");
char c = fgetc(f);
int taille=0,i;
while(c != EOF){
	taille++;
	if(c <= 'z' && c >= 'a')
	 freq[c-'a'] ++;
	if(c <= 'Z' && c>= 'A')
	freq[c-'A'] ++;
	c = fgetc(f);
	}
fclose(f);
for(i=0;i<TAILLE;i++)freq[i]=freq[i]*100.0/taille;
}

void vigenere1 (char *file,char *key){
	int lk = strlen(key);
	char c,tc;
	int k=0;
	FILE * f = fopen(file,"r");
	c = fgetc(f);
	while (c != EOF){
	if(k >= lk) k = 0;
	if( c>= 'A' && c <= 'Z' ){
		tc = (c + key[k]-'a' - 'A' +2*TAILLE ) % TAILLE + 'A';
		printf("%c",tc);
		}
	else if( c>= 'a' && c <= 'z' ){
		tc = (c+key[k] - 'a'-'a' + 2*TAILLE) % TAILLE + 'A';
		printf("%c",tc);
		}
	c=fgetc(f);k++;
	}
printf("\n");
} 

void dechiffre_vig1 (char * file,char *key){
	int lk = strlen(key);
	char c,td;
	int k=0;
	FILE * f = fopen(file,"r");
	c = fgetc(f);
	while (c != EOF){
	if(k >= lk) k = 0;
	if( c>= 'A' && c <= 'Z' ){
		td = (c - key[k]+'a'-'A'+TAILLE ) % TAILLE + 'a';
		printf("%c",td);
		}
	else if( c>= 'a' && c <= 'z' ){
		td = (c-key[k] + TAILLE ) % TAILLE + 'a';
		printf("%c",td);
		}
	c=fgetc(f);k++;
	}
printf("\n");
} 



float *len_proba(char *file,int max){
	int i,j=1,k,taille;
	FILE *f = fopen(file,"r");
	char *s = malloc(sizeof(char)*(max+1));
	float *freq = malloc(sizeof(float)*TAILLE);
	float *indice = malloc(sizeof(float)*TAILLE);
	indice[0]=0;indice[1]=0;
	for(i=3;i<=max;i++){ // la taille de clés est i-1 ( fgets ajout \0 a la fin)
		for(k=0;k<TAILLE;k++) freq[k]=0;
		taille=0;
		while(fgets(s,i,f)){
			if(s[j]<='z' && s[j]>='a')freq[s[j]-'a']++;
			else if(s[j]<='Z' && s[j]>='A')freq[s[j]-'A']++;
			taille++;
		}
		rewind(f);
		for(k=0;k<TAILLE;k++)freq[k]=freq[k]*100/taille;
		printf("longuer  = %d : %f\n",i-1,indice_ap(freq));
		indice[i-1]=indice_ap(freq);
	}
free(freq);free(s);
fclose(f);
return indice;
}

char *key (char *file,int k){
FILE *f =fopen(file,"r");
char *ky = malloc(sizeof(char)*k);
char *s = malloc(sizeof(char)*(k+1));
int *freq = calloc(sizeof(int),TAILLE),max,max1;
int i,j,l,ind;
for(i=0;i<k;i++){ 
	max=0;max1=0;
	while(fgets(s,k+1,f)){
//	printf("test\n",ind+'a');
		if(s[i]<='z' && s[i]>='a')freq[s[i]-'a']++;
		else if(s[i]<='Z' && s[i]>='A')freq[s[i]-'A']++;
		}
	rewind(f);
	for(l=0;l<TAILLE;l++){
		 if(max<freq[l]){ 
			max1 = max;
			max=freq[l];			
			ind = l;
		}
		freq[l]=0;
	}
	ky[i]= (ind - 4 + TAILLE) %TAILLE+'a';// 4 corresp a 'e'
	printf("max = %d,max1=%d , %c\n",max,max1,ky[i]);
	}
free(s);free(freq);
fclose(f);
return ky;
}


