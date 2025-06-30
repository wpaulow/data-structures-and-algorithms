#include "mapa.h"

int main(void) {
   Valor w;
   Map I = NULL;
   insm(36,"Leo",&I); insm(15,"Ivo",&I); insm(42,"Eva",&I);    
   exibem(I);
   if(pertmr(42,w,I)) printf("Valor da chave 42: %s\n",w);
   else puts("Chave 42 inexistente!");
   if(pertmr(10,w,I)) printf("Valor da chave 10: %s\n",w);
   else puts("Chave 10 inexistente!");
   return 0;
}
