/**
 * Receives a completely parenthesized arithmetic expression, but whose operands
 * are single-digit numbers.
 * And returns the arithmetic expression in its prefixed form, along with the
 * result of the expression.
 **/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

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

char *prefix(char *e){
   static char s[256];
   int j = 0, len_e, i;
   Stack S = stack(256);
   len_e = strlen(e);
   i = len_e-1;

   for(i; i >= 0; i--){
      if(isdigit(e[i])) s[j++] = e[i];
      else if(strchr("+*-/", e[i])) push(e[i], S);
      else if(e[i] == '(') s[j++] = pop(S);
   }
   s[j] = '\0';
   destroy(&S);
   strrev(s);
   return s;
}

int result(char *e) {
   Stack S = stack(256);
   int i = strlen(e)-1;   
   
   for(i; i >= 0; i--){
      if(isdigit(e[i])) push(e[i] - '0', S);
      else if(strchr("+*-/", e[i])) {
         int x = pop(S);
         int y = pop(S);
         switch(e[i]){
            case '+': push(x+y, S); break;
            case '-': push(x-y, S); break;
            case '*': push(x*y, S); break;
            case '/': push(x/y, S); break;
         }   
      }  
   }
   int r = top(S);
   destroy(&S);
   return r;
}


int main(void){
   char e[256];
   while(1){
      printf("Fully Parenthesized Expression: ");
      fgets(e, sizeof(e), stdin);
      char *s = prefix(e);
      printf("Postfix Arithmetic Expression: %s\n", s);
      printf("Result: %d\n", result(s));
   }
   return 0;
}
























