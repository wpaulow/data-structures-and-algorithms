#include "mapa.h"

int main(void) {
   Map I = NULL;
   insmr(36,"Leo", &I); 
   insmr(15,"Ivo", &I); 
   insmr(42,"Eva", &I); 
   insmr(29,"Ana", &I);
   exibem(I);
   remmr(29, &I);
   exibem(I); 
   remmr(42, &I);
   exibem(I);
   printf("ohofh\n");   
   destroimr(&I);
   exibem(I);   
   return 0;
}
