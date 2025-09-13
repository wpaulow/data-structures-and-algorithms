#include <stdio.h>

int vets_iguais(int v[], int w[], int n) {
   if(n == -1) return 1;
   if(v[n] != w[n]) return 0;
   else return vets_iguais(v, w, n-1);
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
   printf("\n%s.\n", val_vdd ? "São iguais" : "Não são iguais");
}

void print_tudao(int v[], int w[], int n){
   printf("\nOs vetores\n");
   print_vetor(v, n-1); 
   printf("e\n");
   print_vetor(w, n-1);
   print_resultado(vets_iguais(v, w, n-1)); 
}

int main(void) {
   int n = 5;
   int v1[5] = {10, 20, 30, 40, 50};
   int v2[5] = {1, 2, 3, 4, 5};
   int w1[5] = {10, 20, 30, 40, 50};
   int w2[5] = {1, 2, 3, 99, 5};
   int v3[5] = {100, 200, 300, 400, 500};
   int w3[5] = {100, 200, 300}; // por que quando eu inicializo com 5, os índices restantes são preenchidos com 0 e se eu inicializo com 3, os itens restantes são preenchidos com 10 e 20?????

//   printf("Os vetores\n");
//   print_vetor(v1, n-1); 
//   printf("e\n");
//   print_vetor(w1, n-1);
//   print_resultado(vets_iguais(v1, w1, n-1));  

   print_tudao(v1, w1, n); 
   print_tudao(v2, w2, n); 
   print_tudao(v3, w3, n); 

   return 0;
}
