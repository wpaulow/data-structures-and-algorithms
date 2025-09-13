#include <stdio.h>
#include "pilha.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

Itemp maior(Pilha P){
   Itemp a = topo(P);
   Itemp max = 0, b = 0;
   Pilha auxP = pilha(P->max);
   while(!vaziap(P)){
      b = desempilha(P);
      empilha(b, auxP);
      max = MAX(max, b);
   }
   while(!vaziap(auxP)) empilha(desempilha(auxP), P);
   destroip(&auxP);
   return max;
}

int main(void){
   Pilha P = pilha(10);
   empilha(71, P);
   empilha(72, P);
   empilha(73, P);
   empilha(74, P);
   empilha(75, P);
   empilha(76, P);
   empilha(77, P);
   empilha(7, P);
   empilha(6, P);
   empilha(5, P);

   printf("O maior item dessa pilha é %d.", maior(P));
   
   while(!vaziap(P)) printf("Printando a pilha pra mode conferir: %d.\n", desempilha(P));

   return 0;
}
