#include "pilha.h"

void mover(Pilha o, Pilha d) {
   empilha(desempilha(o), d);
}

void hanoi(int n, Pilha orig, Pilha aux, Pilha dest) {
   if(topo(orig) == n) mover(orig, dest);
   else
}

int main(void) {
   int n = 3;
   Pilha origem = pilha(n);
   Pilha auxiliar = pilha(n);
   Pilha destino = pilha(n);
   
   empilha(3, origem);
   empilha(2, origem);
   empilha(1, origem);

   hanoi(n, origem, auxiliar, destino);

   while(!vaziaP(destino)) printf("%d\n", desempilha(destino));
   
   return 0;
}
