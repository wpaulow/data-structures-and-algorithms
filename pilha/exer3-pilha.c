/*
 * inverte todos os caracteres de uma frase, exceto a ordem das palavras
 */

#include <stdio.h>
#include <ctype.h>
#include "pilha.h"


int main(int argc, char **argv) {
	char frase[100];
	printf("Digite uma frase: ");
	fgets(frase, 100, stdin);
	Pilha P = pilha(100);

	for(int i = 0; frase[i]; i++) {
		char charlinho = frase[i];
		if(charlinho != ' ') empilha(charlinho, P);
		else {
			while(!vaziap(P)) printf("%c", desempilha(P));
			printf("%c", charlinho);
		}
	}
	
	while(!vaziap(P)) printf("%c", desempilha(P));

   destroip(&P);
    
	return 0;
}
