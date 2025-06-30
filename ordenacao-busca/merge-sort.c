#include <stdio.h>
#include <stdlib.h>

void exibe(int v[], int p, int u) {
   if(p == 0) printf("{");
   if(p == u) {
      printf("%d}\n", v[p]);
      return;
   }
   if(p < u) printf("%d, ", v[p]);
   exibe(v, p+1, u);
}

void intercala(int *v, int p, int m, int u) {
   int *w = malloc((u-p+1)*sizeof(int));
   int i = p, j = m+1, k = 0;
   
   while(i <= m && j <= u)
      w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
   while(i <= m) w[k++] = v[i++];
   while(j <= u) w[k++] = v[j++];
   for(k = 0; k <= u-p; k++) v[p+k] = w[k];
   free(w);
}

void ms(int *v, int p, int u) {
   if(p == u) return;
   int m = (p+u)/2;
   ms(v, p, m);
   ms(v, m+1, u);
   intercala(v, p, m, u);
}

void msort(int *v, int n) {
   ms(v, 0, n-1);
}

int main(void) {
   int v[8] = {31,48,60,80,19,27,52,75};
   printf("Original:\n");
   exibe(v, 0, 7);
   printf("Intercala:\n");
   intercala(v, 0, 3, 7);
   exibe(v, 0, 7);
   
   printf("\n");

   int w[9] = {10,82,27,38,41,53,60,75,99};
   printf("Original:\n");
   exibe(w, 0, 8);  
   printf("Intercala:\n"); 
   intercala(w, 0, 1, 8);   
   exibe(w, 0, 8); 

   printf("\n\n");

   int y[10] = {83,31,91,46,27,20,96,25,96,80};
   printf("Original:\n");   
   exibe(y, 0, 9);
   msort(y, 10);
   printf("MSort:\n");
   exibe(y, 0, 9);  

   printf("\n");

   int y2[10] = {83,31,91,46,27,20,96,25,96,80};
   printf("Original:\n");   
   exibe(y2, 0, 9);
   intercala(y2, 0, 4, 9);
   printf("Intercala:\n");
   exibe(y2, 0, 9);


   return 0;
}
