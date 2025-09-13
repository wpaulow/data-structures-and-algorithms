#include <stdio.h>

int bsearch(int x, int v[], int n) {
   int p = 0;
   int u = n-1;
   while(p <= u) {
      int m = (p + u) / 2;
      if(x == v[m]) return 1;
      if(x < v[m]) u = m-1;
      else p = m+1;
   }
   return 0;
} // essa versão da busca binária só diz se o elemento
   // está ou não no vetor. ela pode ser modificada para
   // retornar o índice, caso esteja, e -1 caso não esteja

int main(int argc, char **argv) {   
//   int v[8] = {66,80,31,48,27,75,19,52}; // aqui não funciona corretamente, pois o vetor não está ordenado
   int v[8] = {19,27,31,48,52,66,75,80};
   printf("27: %s\n", bsearch(27, v, 8) ? "está contido no vetor." : "não está contido no vetor.");
   printf("51: %s\n", bsearch(51, v, 8) ? "está contido no vetor." : "não está contido no vetor.");   
   
   return 0;
}
