#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char op) {
   switch(op) {
      case '(': return 0;
      case '+':
      case '-': return 1;
      case '*':
      case '/': return 2;   
   }
   return -1;
}

char *posfixa(char *e) {
   static char s[256];
   int j = 0;
   Pilha P = pilha(256);
   
   for(int i=0; e[i]; i++){
      if(e[i] == '(') empilha('(', P);
      else if(isdigit(e[i])) s[j++] = e[i];
      else if(strchr("+/-*", e[i])){
         while(!vaziap(P) && prio(topo(P)) >= prio(e[i]))
            s[j++] = desempilha(P);
         empilha(e[i], P);      
      }
      else if(e[i] == ')'){
         while(topo(P) != '(') s[j++] = desempilha(P);
         desempilha(P);      
      }
   }
   while(!vaziap(P)) s[j++] = desempilha(P);
   s[j] = '\0';
   destroip(&P);
   return s;
}

int valor(char *e) {
   Pilha P = pilha(256);
   for(int i = 0; e[i]; i++){
      if(isdigit(e[i])) empilha(e[i] - '0', P);
      else if(strchr("+*-/", e[i])) {
         int y = desempilha(P);
         int x = desempilha(P);
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
   char e[256];
   while(1){
      printf("Expressão Não Necessariamente Completamente Parentesiada: ");
      gets(e);
      char *s = posfixa(e);
      printf("Posfixa: %s\n", s);
      printf("Valor: %d\n", valor(s));
   }
   return 0;
}





























