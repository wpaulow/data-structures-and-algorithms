#include <stdio.h>

int encontra_maior_indice(int v[], int u) {
   int maior_indice = u;
   for (int i = 0; i < u; i++) 
      if (v[i] > v[maior_indice]) maior_indice = i;
   return maior_indice;
}

void empurra(int v[], int u) {
   if (u == 0) return;

   int maior_indice = encontra_maior_indice(v, u-1);

   int temp = v[u];
   v[u] = v[maior_indice];
   v[maior_indice] = temp;

   empurra(v, u-1);
}

void exibe(int v[], int n) {
   for (int i = 0; i < n; i++) printf("%d ", v[i]);
   printf("\n");
}

int main() {
   int v[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};

   exibe(v, 9);
   empurra(v, 8);
   exibe(v, 9);

   return 0;
}

