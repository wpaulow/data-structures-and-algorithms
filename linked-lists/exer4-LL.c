#include <stdio.h>
#include "lista.h"

int soma(Lista L) {
   int r = 0;
   
   while(L) {
      r += L->item;
      L = L->prox;   
   }
   return r;
}

int main(void) {
   Lista I = no(3, no(1, no(5, NULL)));
   exibidona(I);
   printf("Tamanho = %d\n", tamanho(I));
   printf("Soma dos Itens = %d\n", soma(I));   
   
   return 0;
}
