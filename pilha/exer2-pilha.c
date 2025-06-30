/*
 * Ordenação decrescente e sem repetição
 * */

#include <stdio.h>
#include "pilhaTeste.h"

int main(int argc, char **argv)
{
	int x, y, num;
	printf("Informe a quantidade de números: ");
	scanf("%d", &x);
	
	Pilha A = pilha(x);
	Pilha B = pilha(x);
	
	printf("Informe os %d números a seguir:\n", x);
	
	for(int i = 0; i < x; i++) {
		scanf("%d", &y);
		empilha(B, y);
	}
	
	while(!vaziaP(B)) {
		num = desempilha(B);
		while(!vaziaP(A) && topoP(A) > num) empilha(B, desempilha(A));
		if(vaziaP(A) || topoP(A) != num) empilha(A, num);
	}	
	
	while(!vaziaP(A)) printf("%d\n", desempilha(A));
	
	return 0;
}
