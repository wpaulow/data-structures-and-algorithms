#include <stdio.h>

int maior_indice(int *v, int p, int u, int maior){
   if(p == u) return maior;
   if(v[p] >= v[maior]) maior = p;
   maior_indice(v, p+1, u, maior);
}

//void empurra(int v[], int u){
//   if(u == 0) return;
//   if(v[u-1] >= v[u]) {
//      int aux = v[u];
//      v[u] = v[u-1];
//      v[u-1] = aux; 
//   }
//   empurra(v, u-1);
//} // essa função é um "puxa", e não um "empurra" recursivo
//   // pois ela puxa o menor item pro início da lista

void empurrante(int *v, int u) {
   if(u == 0) return;
   empurrante(v, u-1);
   if(v[u] < v[u-1]) {
      int temp = v[u-1];
      v[u-1] = v[u];
      v[u] = temp; 
   }
}

void exibe(int v[], int p, int u) {
   if(p == 0) printf("{");
   if(p == u) {
      printf("%d}\n", v[p]);
      return;
   }
   if(p < u) printf("%d, ", v[p]);
   exibe(v, p+1, u);
}

void empurra(int v[], int u) {
   if(u == 0) return;

   int maior_i = maior_indice(v, 0, u, 0);
   int temp = v[u];
   v[u] = v[maior_i];
   v[maior_i] = temp;
//   printf("Chamada %d.\n", u);
//   exibe(v, 0, u);
   // Chama recursivamente para empurrar o maior elemento do subvetor restante.
   empurra(v, u-1);
}

void bsr(int v[], int n) {
   if(n == 0) return;
   empurrante(v, n);
   bsr(v, n-1);
   empurrante(v, n-1);
}

int main(int argc, char **argv) {
   int v[9] = {51,82,38,99,75,19,69,46,27};
   printf("\n");
   printf("Original: \n");
   exibe(v, 0, 8);
//   int x = maior_indice(v, 0, 8, 0);
//   int x = maior_indice(v, 8, 8);
//   printf("O maior índice é: %d e o seu valor é %d.\n", x, v[x]);
//   empurra(v, 8);
//   printf("Pós-Empurra: \n");
//   exibe(v, 0, 8);

   empurrante(v, 8);
   printf("Pós-Empurrante: \n");
   exibe(v, 0, 8);

   printf("\n\n\n");
   
   int v2[9] = {51,82,38,99,75,19,69,46,27};
   printf("Original: \n");
   exibe(v2, 0, 8);
   printf("Pós-BSR: \n");
   bsr(v2, 8);
   exibe(v2, 0, 8);   

   return 0;
}
