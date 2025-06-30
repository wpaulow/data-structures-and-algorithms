#include "mapa.h"

int main(void) {
   Map I = NULL;
   insmr_char("gota","Leo", &I); 
   insmr_char("papel","Ivo", &I); 
   insmr_char("aluminio","Eva", &I); 
   insmr_char("banana","Ana", &I);
   exibem_char(I);
   remmr_char("banana", &I);
   exibem_char(I); 
   remmr_char("aluminio", &I);
   exibem_char(I);

   Valor w;
   if(pertmr_char("aluminio",w,I)) printf("Valor da chave aluminio: %s\n",w);
   else puts("Chave 'aluminio' inexistente!");
   if(pertmr_char("gota",w,I)) printf("Valor da chave 'gota': %s\n",w);
   else puts("Chave 'gota' inexistente!");

   printf("ohofh\n");   
   destroimr(&I);
   exibem_char(I);   
   return 0;
}
