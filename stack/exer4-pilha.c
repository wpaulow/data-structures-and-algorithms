/*
 * exer4-pilha.c
 * balanceamento de parênteses, chaves, colchetes
 * balanceada     = "[{()()}{}]"
 * não balanceada = "{[(}])"
 */

#include <stdio.h>
#include "pilha.h"

int main(int argc, char **argv)
{
	char s[256];
	Pilha P = pilha(256);
	
	printf("frase? ");
	gets(s);
	
	for(int i = 0; s[i]; i++) {
		char ch_atual = s[i], ch_topo;
		
		if(ch_atual == '{' || ch_atual == '[' || ch_atual == '(') empilha(ch_atual, P);
		else {
			ch_topo = topo(P);
			if(ch_atual == '}' && ch_topo == '{' || 
				ch_atual == ']' && ch_topo == '['|| 
				ch_atual == ')' && ch_topo == '(') ch_topo = desempilha(P);
		}
	}
	
	if(vaziap(P)) puts("balanceadas");
	else puts("não balanceadas");
	
	destroip(&P);
	
		
	return 0;
}

