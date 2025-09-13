/*
 * Ordenação crescente
 * */

#include <stdio.h>
#include "pilhaTeste.h" //implementação de pilha diferente da do Silvio

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
		while(!vaziaP(A) && topoP(A) < num) empilha(B, desempilha(A));
		empilha(A, num);
	}	
	
	while(!vaziaP(A)) printf("%d\n", desempilha(A));

   destroiP(A);
   destroiP(B);

	
	return 0;
}

