#include <stdio.h>

int maximo(int *v, int n, int maior){
  if(n == 0) return maior;
  if(v[n] >= v[n-1]) maior = v[n];
  else maximo(v, n-1, v[n-1]);
}

void print_vetor(int vet[], int n) {
   printf("{");
   for(int i = 0; i <= n; i++){
      printf("%d", vet[i]);
      if(i < n) printf(", ");
   }
   printf("}\n");
}

int main(){
   int v1[5] = {10, 20, 30, 40, 50};
   int v2[5] = {5, 4, 3, 2, 1};

   printf("\nO maior item do vetor:\n");
   print_vetor(v1, 4);
   printf("É o item %d.\n", maximo(v1, 4, v1[4]));

   printf("\nO maior item do vetor:\n");
   print_vetor(v2, 4);
   printf("É o item %d.\n", maximo(v2, 4, v2[4]));

   return 0;
}

//v[n] >= v[n-1] ? v[n] : v[n-1]
