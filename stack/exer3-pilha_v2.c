/*
 * inverte todos os caracteres de uma frase, exceto a ordem das palavras
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"


int main() {
	char frase[512];
	printf("Digite uma frase: ");
	fgets(frase, 512, stdin);
	int size = strlen(frase);
	Pilha P = pilha(size);

		for(int i = 0; i <= size; i++) {
			char chub = frase[i];
			if(chub != ' ') empilha(chub, P);
			else {
				while(!vaziap(P)) printf("%c", desempilha(P));
				printf(" ");
			}
//			if(i == size-1) {
//				while(!vaziap(P)) printf("%c", desempilha(P));
//				printf("%c", chub);
//			}
			
		}

   destroip(&P);
    
	return 0;
	
	}
