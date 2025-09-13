#include <stdio.h>

void troca(int v[], int i, int j) {
   int x = v[i];
   v[i] = v[j];
   v[j] = x;
}

void bsort(int v[], int n) {
   for(int i = 1; i < n; i++)
      for(int j = 0; j < n-1; j++)
         if(v[j] > v[j+1])
            troca(v, j, j+1);
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

int main(int argc, char **argv) {
   int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
   exibe(v, 0, 9);
   bsort(v, 10);
   exibe(v, 0, 9);

   return 0;
}
