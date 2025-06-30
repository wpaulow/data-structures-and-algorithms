#include <stdio.h>

int vet_crescente(int v[], int ult_i) {
   if(ult_i == 0) return 1;
   if(v[ult_i] >= v[ult_i-1]) vet_crescente(v, ult_i-1);
   else return 0;
}

void print_vetor(int vet[], int n) {
   printf("{");
   for(int i = 0; i <= n; i++){
      printf("%d", vet[i]);
      if(i < n) printf(", ");
   }
   printf("}\n");
}

void print_resultado(int val_vdd) {
   printf("\n%s.\n", val_vdd ? "É crescente" : "Não é crescente");
}

int main() {
   int v1[5] = {10, 20, 30, 40, 50};
   int v2[5] = {5, 4, 3, 2, 1};

   print_vetor(v1, 4);
   print_resultado(vet_crescente(v1, 4));

   print_vetor(v2, 4);
   print_resultado(vet_crescente(v2, 4));
   
   return 0;
}
