#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int ttm(Fila F, Pilha P) {
   static int c_ttm = 0;
   
   while(!vaziap(P)) {
      int aux = desenfileira(F);
      if(topo(P) != aux){
         enfileira(aux, F);
         c_ttm++;          
      } else {
         desempilha(P);
         c_ttm++;        
      }
   }
   return c_ttm;
}

int main(int argc, char **argv) {
   Fila F = fila(3);
   enfileira(2, F);
   enfileira(3, F);
   enfileira(1, F);  
   
   Pilha P = pilha(3);
   empilha(2,P);
   empilha(3,P);
   empilha(1,P); 

   printf("\nTempo total mínimo: %d\n\n", ttm(F,P) );
   destroif(&F);
   destroip(&P);
   return 0;

   return 0;
}
