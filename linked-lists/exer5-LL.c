#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(void) {
   //exercício 5
   Lista A = aleatoria(10, 100);
   exibidona(A);
   
   //exercício 6
   Lista B = intervalo(5);
   exibidona(B);

   //exercício 7
   printf("A = "); exibidona(A);
   printf("B = "); exibidona(B);
   printf("Pressione enter");
   getchar();
   anexa(&A, B);
   printf("A = "); exibidona(A);
   printf("B = "); exibidona(B);

   return 0;
}
