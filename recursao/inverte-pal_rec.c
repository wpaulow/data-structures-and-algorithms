#include <stdio.h>
#include <string.h>

void inverte(char *s, int p, int u) {
   if(p >= u) return;
   
   char x = s[p];
   s[p] = s[u];
   s[u] = x;
   inverte(s, p+1, u-1);
}

int main(void) {
   char teste[] = "roma";
   inverte(teste, 0, strlen(teste) - 1);
   printf("%s\n", teste); 
   
   char teste2[] = "apenas um teste";
   inverte(teste2, 0, strlen(teste2) - 1);
   printf("%s\n", teste2); 

   return 0;
}
