#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

char baseAZ(int n){
   switch(n){
      case 10: return 'A';
      case 11: return 'B';
      case 12: return 'C';
      case 13: return 'D';
      case 14: return 'E';
      case 15: return 'F';
      case 16: return 'G';
      case 17: return 'H';
      case 18: return 'I';
      case 19: return 'J';
      case 20: return 'K';
      case 21: return 'L';
      case 22: return 'M';
      case 23: return 'N';
      case 24: return 'O';
      case 25: return 'P';
      case 26: return 'Q';
      case 27: return 'R';
      case 28: return 'S';
      case 29: return 'T';
      case 30: return 'U';
      case 31: return 'V';
      case 32: return 'W';
      case 33: return 'X';
      case 34: return 'Y';
      case 35: return 'Z';  
   }
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
