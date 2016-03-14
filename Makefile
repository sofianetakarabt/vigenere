CC=gcc
SRC=cesar.c  decryp_mono.c  mono_alph.c  vigenere.c indice.c key_vig.c vigenere1.c cesar1.c decyp_rap.c
OBJ=$(SRC:.c=.o)

all : decryp_mono mono_alph key_vig cesar1 vigenere1 decryp_rap


%.o:%.c
	$(CC) -c $<

fonctions.o: fonctions.c
	$(CC) -c $<


decryp_mono: decryp_mono.c fonctions.o cesar.o indice.o head.h
	$(CC) -o $@ $^ #decryp_mono.c fonctions.o indice.c cesar.c 

decryp_rap: decryp_rap.c fonctions.o indice.o head.h
	$(CC) -o $@ $^ #decryp_mono.c fonctions.o indice.c cesar.c 


mono_alph: mono_alph.o head.h
	$(CC) -o $@ $^

vigenere: vigenere.o head.h
	$(CC) -o $@ $<

indice: indice.o fonctions.o head.h
	$(CC) -o $@ $^ 

cesar1: cesar1.o
	$(CC) -o $@ $<

key_vig: key_vig.o fonctions.o indice.o
	$(CC) -o $@ $^

vigenere1:vigenere1.o fonctions.o indice.o
	$(CC) -o $@ $^

clean:
	rm -f *.o decryp_mono mono_alph key_vig cesar1 vigenere1 decryp_rap

