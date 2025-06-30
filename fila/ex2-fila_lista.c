#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int concha(char *c){
   Pilha P = pilha(strlen(c));
   empilha(c[0], P);
   for(int i = 1; c[i]; i++){
      if(!vaziap(P) && topo(P) == c[i]) desempilha(P);
      else empilha(c[i], P);   
   }
   if(vaziap(P)) {
      destroip(&P);
      return 1;
   } else {
      destroip(&P);
      return 0;
   }
}

void filtra(Fila F) {
   while(!vaziaf(F)) {
      char *c = desenfileira(F);
      if(concha(c)) printf("%s\n", c);
   }
}

int main(int argc, char **argv) {
//   char *teste = "AAABAAABBABAAA";
//   char *teste = "BBBAAAAABA";
//   char *x = concha(teste) ? "é" : "não é";
//   printf("%s concha.\n", x); 

   Fila F = fila(20);
   enfileira("AAAAAAAABAAABA",F);
   enfileira("BBBBBBBBBBBBBB",F);
   enfileira("ABBABBABBABB",F);
   enfileira("AAABAAABBABAAA",F);
   enfileira("ABAABAAAAAAAAA",F);
   enfileira("AABAAAAAABAAAA",F);
   enfileira("AAAABB",F);
   enfileira("AABBBBAABAAB",F);
   enfileira("ABAAAAAAAAAB",F);
   enfileira("ABABBBABAB",F);
   enfileira("BBBBBBBBBBBBBB",F);
   enfileira("AABAABAAAA",F);
   enfileira("AABAAABBBBBABB",F);
   enfileira("BBBAAAAABA",F);
   enfileira("BBBBBBBBBBBBBB",F);
   enfileira("AAAAAAAAAAAABB",F);
   enfileira("BAAAAABAAAAAAA",F);
   enfileira("BBBBABBBBBBA",F);
   enfileira("BBABABAAAAAABB",F);
   enfileira("ABAABAABAB",F);
   filtra(F); // deve exibir 12 conchas
   destroif(&F);
   
   return 0;
}
