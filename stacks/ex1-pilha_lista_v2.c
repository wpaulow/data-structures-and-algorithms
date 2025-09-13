#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

char baseAZ(int n){
   if (n >= 10 && n <= 35)
      return 'A' + (n - 10);
   return -1;
}

char *converteBase(int n, int base){
   static char convertido[256];
   Pilha P = pilha(256);
   int resto, i = 0;
   
   while(n > 0){
      resto = n % base;
      n /= base;
      if(resto > 10) empilha(baseAZ(resto), P);
      else empilha(resto + '0', P); 
   }
   while(!vaziap(P)) convertido[i++] = desempilha(P);
   convertido[i] = '\0';
   destroip(&P);
   return convertido; 
}

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
      char *baseado = converteBase(n, base);
      printf("O número %d convertido para base %d é %s.\n\n", n, base, baseado);
   }
   return 0;
}
