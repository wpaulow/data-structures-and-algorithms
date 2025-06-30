#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

void strrev(char *str){
   int i = 0;
   int j = strlen(str) - 1;

   while (i < j) {
      char c = str[i];
      str[i] = str[j];
      str[j] = c;
      i++;
      j--;
   }
}

char *prefixa(char *e){
   static char s[256];
   int j = 0, len_e, i;
   Pilha P = pilha(256);
   len_e = strlen(e);
   i = len_e-1;

   for(i; i >= 0; i--){
      if(isdigit(e[i])) s[j++] = e[i];
      else if(strchr("+*-/", e[i])) empilha(e[i], P);
      else if(e[i] == '(') s[j++] = desempilha(P);   
   }
   s[j] = '\0';
   destroip(&P);
   strrev(s);
   return s;
}

int valor(char *e) {
   Pilha P = pilha(256);
   int i = strlen(e)-1;   
   
   for(i; i >= 0; i--){
      if(isdigit(e[i])) empilha(e[i] - '0', P);
      else if(strchr("+*-/", e[i])) {
         int x = desempilha(P);
         int y = desempilha(P);
         switch(e[i]){
            case '+': empilha(x+y, P); break;
            case '-': empilha(x-y, P); break;
            case '*': empilha(x*y, P); break;
            case '/': empilha(x/y, P); break; 
         }   
      }  
   }
   int r = topo(P);
   destroip(&P);
   return r;
}


int main(void){
//   char exp[] = "((2*3)+(8/4))\0";
   char e[256];
   while(1){
      printf("Expressão Completamente Parentesiada: ");
      gets(e);
      char *s = prefixa(e);
      printf("Prefixa: %s\n", s);
      printf("Valor: %d\n", valor(s));
   }
   return 0;
}
























