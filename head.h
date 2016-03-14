#ifndef CRYPTO_
#define CRYPTO_

#define TAILLE 26
#define TAB_FREQ_RF {0.092134,0.010354,0.030179,0.037537,0.171747,0.010939,0.010615,0.010718,0.075072,0.003833,0.000070,0.061368,0.026499,0.070308,0.049141,0.023698,0.010160,0.066093,0.078168,0.073743,0.063562,0.016451,0.000011,0.004072,0.002300,0.001226}

void frequence(char *file,float freq[TAILLE]);
char* cesar (char *txt,int k);
char* dechiffre_cesar (char *c,int k);
char * monoalph(char *txt,char perm[TAILLE]);
char * dechiffre_mono (char *c,char perm[TAILLE]);
char * vigenere (char * txt,char *key);
char * dechiffre (char * c,char *key);
void decry_mono(int permute [TAILLE],char *file,int tab_freq_lang[]);
float indice_ap(float freq[TAILLE]);
float indice(char *file);

#endif
