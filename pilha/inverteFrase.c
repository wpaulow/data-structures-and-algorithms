/*
 * inverte todos os caracteres de uma frase, inclusive a ordem das palavras
 */

#include <stdio.h>
#include "pilha.h"

int main(void) {
   char  c[513];
   Pilha P = pilha(513);
   printf("Cadeia? ");
   gets(c);
   
   for(int i=0; c[i]; i++)
      empilha(c[i],P);
   
   printf("Inverso: ");
   while( !vaziap(P) )
      printf("%c", desempilha(P));
   puts("\n");
   
   destroip(&P);
   return 0;
}
