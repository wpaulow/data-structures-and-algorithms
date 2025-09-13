/*
   Operacoes envolvendo numeros Naturais,
   por meio de recursao

*/

#include <stdio.h>
#include "exer3-lista_rec.h"

int main(void) {
   printf("%d\n", soma(5,3));
   printf("%d\n", subtracao(3,5));

   printf("%d\n", soma(5,0));
   printf("%d\n", subtracao(0,5));

   printf("%d\n", soma(15, 2));

   printf("%d\n", dobro(3));

   printf("%d\n", metade(0)); // 0
   printf("%d\n", metade(1)); // 0
   printf("%d\n", metade(2)); // 1
   printf("%d\n", metade(3)); // 1
   printf("%d\n", metade(4)); // 2
   printf("%d\n", metade(5)); // 2


   printf("o mínimo entre %d e %d é %d.\n", 5, 3, minimo(5, 3));

   printf("o máximo entre %d e %d é %d.\n", 8, 3, maximo(8, 3));

   printf("%d é %s.\n", 5, par(5) ? "par" : "ímpar");

   printf("%d é %s.\n", 6, impar(6) ? "par" : "ímpar");

   return 0;
}
