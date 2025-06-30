#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

//int palindroma(const char *s, int p, int u) {
//   if(p >= u) return 1;
//   char x, y;
//   s[p] != ' ' ? x = s[p] : palindroma(s, p+1, u);
//   s[u] != ' ' ? y = s[u] : palindroma(s, p, u-1);
//   x == y ? palindroma(s, p+1, u-1) : palindroma(s, u, p);
//} // não funciona, não sei por que diabos

int palindroma(const char *s, int p, int u) {
   if(p >= u) return 1;
   if(s[p] == ' ') s[++p];
   if(s[u] == ' ') s[--u];
   if(s[p] != s[u]) return 0;
   return palindroma(s, p+1, u-1);
} // menos é mais, aqui funciona



int main(void) {   
   char teste[] = "subi no onibus";
   int palind = palindroma(teste, 0, strlen(teste) - 1);
   printf("%s.\n", teste);
   printf("%s palíndroma.\n", palind ? "é" : "não é"); 

   printf("\n");

   char teste2[] = "desci do onibus";
   int palind2 = palindroma(teste2, 0, strlen(teste2) - 1);
   printf("%s.\n", teste2);
   printf("%s palíndroma.\n", palind2 ? "é" : "não é"); 

   return 0;
}
