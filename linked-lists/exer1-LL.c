#include "lista.h"

int main(void) {
   Lista I = no(3, no(1, no(5, NULL)));
   exibe(I);
   exibidinha(I);

   printf("\n");
   Lista J = NULL;
   exibidinha(J);

   printf("\n");
   exibe_rec(I);
   exibe_rec(J);

   printf("\n");
   exibidona(I);
   exibidona(J);

   destroi(&I);
   destroi(&J);

   return 0;
}
