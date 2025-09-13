#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
   char n_in[100], base_in[100];
   int n, base;
   while(1){
      printf("Informe um número, na base 10, evidentemente, por favor: ");
      fgets(n_in, sizeof(n_in), stdin);
      printf("Informe uma base, entre 2 e 36, por favor: ");
      fgets(base_in, sizeof(base_in), stdin);
      n = atoi(n_in);
      base = atoi(base_in);
      char *baseado = strtol(n_in, NULL, base);
      printf("O número %d convertido para base %d é %s.\n\n", n, base, baseado);
   }
   return 0;
}
