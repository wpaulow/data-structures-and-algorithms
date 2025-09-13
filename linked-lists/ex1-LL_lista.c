#include "lista.h"

/* 
dada lista L e uma lista I (inicialmente vazia), constrói e devolve a
lista inversa de L
*/

Lista inversao(Lista L, Lista I) {
   if(!L) return I;
   I = no(L->item, I);
   return inversao(L->prox, I);
}

int main(int argc, char **argv) {
   Lista vazia = NULL;
   Lista cresc = intervalo(4);

   exibidinha(cresc);
   vazia = inversao(cresc, vazia);
   printf("\n\n");
//   exibidinha(cresc);
   exibidinha(vazia); 

   return 0;
}

