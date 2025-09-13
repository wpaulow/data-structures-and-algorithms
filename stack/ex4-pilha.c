#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *posfixa(char *e){
   static char s[256];
   int j = 0;
   Pilha P = pilha(256);
   for(int i = 0; e[i]; i++){
      if(isalpha(e[i])) s[j++] = e[i];
      else if(ispunct(e[i]) && e[i] != '(' && e[i] != ')') empilha(e[i], P);
      else if(e[i] == ')') s[j++] = desempilha(P);   
   }
   s[j] = '\0';
   destroip(&P);
   
   return s;
}

int valor(char *e) {
   Pilha P = pilha(256);
   for(int i = 0; e[i]; i++){
      if(isalpha(e[i])) empilha(e[i], P);
      else if(e[i] == '!') {
         char x = desempilha(P);
         if(x == 'F') empilha('V', P);
         else if(x == 'V') empilha('F', P);      
      } else if(e[i] == '&'){
         char x = desempilha(P);
         char y = desempilha(P);
         if(x == y) empilha('V', P);
         else empilha('F', P);     
      } else if(e[i] == '|'){
         char x = desempilha(P);
         char y = desempilha(P);
         if(x == 'V' || y == 'V') empilha('V', P);
         else empilha('F', P);
      }
   }
   char valorVdd = topo(P);
   destroip(&P);
   if(valorVdd == 'V') return 1;
   if(valorVdd == 'F') return 0;
}


int main(void){
   char e[256];
   while(1){
      printf("Expressão Booleana Completamente Parentesiada:");
      gets(e);
      char *s = posfixa(e);
      printf("Posfixa: %s\n", s);
      printf("Valor Verdade: %d\n", valor(s));
   }  
   return 0;
}
