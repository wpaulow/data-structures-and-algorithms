#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int x, int y) {
   return x > y ? x : y;
}

typedef int Item;

typedef struct arv {
   struct arv *esq;
   Item item;
   struct arv *dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
   Arv n = malloc(sizeof(struct arv));
   n->esq = e;
   n->item = x;
   n->dir = d;
   return n;
}

// essa é uma exibição da árvore com percurso em-ordem inversa
void exibe(Arv A, int n) {
   if(!A) return;
   exibe(A->dir, n+1);
   printf("%*s%d\n", 3*n, "", A->item);
   exibe(A->esq, n+1);
}

int pertence(Item x, Arv A) {
   if(!A) return 0;
   if(x == A->item) return 1;
   return pertence(x, A->esq) || pertence(x, A->dir);
}

void substitui(Item x, Item y, Arv A) {
   if(!A) return;
   if(x == A->item) A->item = y;
   substitui(x, y, A->esq);
   substitui(x, y, A->dir);
}

Arv completa(int h) {
   if(h == 0) return NULL;
   return arv(completa(h-1), rand() % 100, completa(h-1));
}

// onde n é a quantidade de itens
Arv balanceada(int n) {
   if(n == 0) return NULL;
   return arv(balanceada((n-1)/2), rand() % 100, balanceada(n/2));
}

// intervalo de itens de m a n dispostos balanceadamente
Arv bal_range(int m, int n) {
   if(n < m) return NULL;
   return arv(bal_range(m, ((n+m)/2)-1), (n+m)/2, bal_range(((n+m)/2)+1, n));
}

Arv bal_vet(Item v[], int p, int u) { 
   if(p > u) return NULL;
   return arv(bal_vet(v, p++, ((p+u)/2)-1), v[(p+u)/2], bal_vet(v, ((p+u)/2)+1, u));
}

//Arv bal_vet(int v[], int p, int u) {   /// Gemini
//    if (p > u) return NULL;  // Condição de parada corrigida
//
//    int meio = (p + u) / 2;  // Cálculo do índice central
//
//    // Criação da árvore balanceada
//    Arv esquerda = bal_vet(v, p, meio - 1);
//    Arv direita = bal_vet(v, meio + 1, u);
//
//    return arv(esquerda, v[meio], direita);
//}

Arv aleatoria(int n, int m) {
//   srand(time(NULL)); // com essa linha cria uma lista de formato aleatório, mas com todos os números iguais
   if(n == 0) return NULL;
   m = rand() % n;
   return arv(aleatoria(n-1, m), rand() % n, aleatoria(n-1-m, m));
   // se trocar o módulo da divisão no campo item por rand() % n ele gera números pequenos, num range curto, 
   // e com muitos zeros entre eles, inclusive todas folhas serão zeros. o correto é deixar módulo por 100 ou 10.
}

Arv aleatorie(int n){
   if(n <= 0) return NULL;
   return arv(aleatorie(n-1-(rand() % 10)), rand() % 100, aleatorie(n-1-(rand() % 10)));
}

Arv merda(int n) {
   if(n == 0) return NULL;
   return arv(merda(n/2), rand() % 100, merda((n-1)/2));
}

int altura(Arv A) {
   if(!A) return 0;
   return 1 + max(altura(A->esq), altura(A->dir));
}

int nos(Arv A) {
   if(!A) return 0;
   return 1 + nos(A->esq) + nos(A->dir);
}

int soma(Arv A) {
   if(!A) return 0;
   return A->item + soma(A->esq) + soma(A->dir);
}

int folhas(Arv A) {
   if(!A) return 0;
   if(A->esq == A->dir) return 1;
   return folhas(A->esq) + folhas(A->dir);
}

int conta_itens(int x, Arv A) {
   if(!A) return 0;
   return ((A->item == x) + conta_itens(x, A->esq) + conta_itens(x, A->dir));
}

Arv clone(Arv A) {
   if(A == NULL) return NULL;
   return arv(clone(A->esq), A->item, clone(A->dir));
}

Arv espelho(Arv A) {
   if(A == NULL) return NULL;
   return arv(espelho(A->dir), A->item, espelho(A->esq));
}

int eh_espelho(Arv A, Arv B) {
   if(!A && !B) return 1;
   if(!A || !B || (A->item != B->item)) return 0;
   return (eh_espelho(A->esq, B->dir) + eh_espelho(A->dir, B->esq) == 2);
}

int iguais(Arv A, Arv B) {
   if(!A && !B) return 1;
   if(!A || !B || (A->item != B->item)) return 0;
   return (iguais(A->esq, B->esq) + iguais(A->dir, B->dir) == 2);
}

void inverte_sinal(Arv A) {
   if(!A) return;
   
   A->item *= -1;   

   inverte_sinal(A->esq);
   inverte_sinal(A->dir);
}

// em ordem
void erd(Arv r ) {
   if(r != NULL) {
      erd(r->esq);
      printf("%d, ", r->item);
      erd(r->dir); 
   }
}

// em ordem inversa
void dre(Arv r) {
   if(!r) {
      dre(r->dir);
      printf("%d, ", r->item);
      dre(r->esq);  
   }
}

// preordem
void red(Arv r) {
   if(r) {
      printf("%d, ", r->item);
      red(r->esq);  
      red(r->dir);
   }
}

// preordem inversa 
void rde(Arv r) {
   if(r) {
      printf("%d, ", r->item);  
      rde(r->dir);
      rde(r->esq);
   }
}

// posordem
void edr(Arv r) {
   if(r) {
      edr(r->esq);
      edr(r->dir);
      printf("%d, ", r->item);   
   }
}

// posordem inversa
void der(Arv r) {
   if(r) {
      der(r->dir);
      der(r->esq);
      printf("%d, ", r->item);   
   }
}

void poda(Arv *A) {
   if(!*A) return;

   if((*A)->esq == (*A)->dir) {
      free(*A);
      *A = NULL;
   } else {
      poda(&(*A)->esq);
      poda(&(*A)->dir);
   }
}

void destroi(Arv *A) {
   if(!*A) return;

   destroi(&(*A)->esq);
   destroi(&(*A)->dir);

   free(*A);
   *A = NULL;
}


//void infixa(Arv A) {
//   if(!A) return;
//   if(!A->esq && !A->dir)
//      printf("%c", A->item);
//   else {
//      printf("(");
//      infixa(A->esq);
//      printf(" %c ");
//      infixa(A->dir);
//      printf(")");  
//   }
//}


int pos(Arv A) {
   if(!A) return 0;
   return ((A->item >= 0) + pos(A->esq) + pos(A->dir));
}








