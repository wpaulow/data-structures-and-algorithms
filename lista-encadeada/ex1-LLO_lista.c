#include "lista-ord.h"

int ordenada(Lista L) {
   while(L && L->prox) {
      if(L->item >= L->prox->item) return 0;
      L = L->prox;
   }
   return 1;
}

int main(void) {
   Lista I = NULL;
   
   ins_rec(4,&I);
   ins_rec(1,&I);
   ins_rec(3,&I);
   ins_rec(5,&I);
//   ins_rec(3,&I);
//   ins_rec(3,&I);
   ins_rec(2,&I);

   exibidona(I);

   printf("A lista %s ordenada.\n", ordenada(I) ? "está" : "não está");

   return 0;
}
