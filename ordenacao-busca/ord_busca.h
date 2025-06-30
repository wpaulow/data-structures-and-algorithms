//algoritmos de ordenação 

#include <stdlib.h>


void troca(int v[], int i, int j) {
   int x = v[i];
   v[i] = v[j];
   v[j] = x;
}

void bsort(int v[], int n) {
   for(int i=1; i<=n; i++)
      for(int j=0; j<n-i; j++)
         if( v[j]>v[j+1] )
            troca(v,j,j+1);
}

