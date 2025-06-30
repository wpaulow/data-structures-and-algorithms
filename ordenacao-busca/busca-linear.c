#include <stdio.h>
#include <stdlib.h>

/*
   posteriormente reunir funções úteis em um só arquivo de cabeçalho, 
   para eliminar as diversas redundâncias nos arquivos
*/

/*
   posteriormente também, tornar o uso dos programas de ordenação e busca
   como passíveis de serem usados via terminal. não exclusivos de terminal, 
   mas facultativos ao seu uso
*/

void preenche(int *v, int n, int s) {
   srand(s);
   for(int i = 0; i < n; i++) v[i] = rand()%1000;
}

int lsearch(int x, int v[], int n) {
   for(int i = 0; i < n; i++)
      if(x == v[i])  return 1;
   return 0;
}

int main(int argc, char **argv) {
   int v[8] = {66,80,31,48,27,75,19,52};
   printf("27: %s\n", lsearch(27, v, 8) ? "está contido no vetor." : "não está contido no vetor.");
   printf("51: %s\n", lsearch(51, v, 8) ? "está contido no vetor." : "não está contido no vetor.");
   
   return 0;
}
