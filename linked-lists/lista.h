// implementação de lista encadeada

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

typedef int Item;

typedef struct no {
   Item item;
   struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
   Lista n = malloc(sizeof(struct no));
   n->item = x;
   n->prox = p;
   return n;
}

int tamanho(Lista L) {
   int t = 0;
   while(L){
      t++;
      L = L->prox;
   }
   return t;
}

// em A, anexa B
void anexa(Lista *A, Lista B) {
   if(!B) return;
   while(*A) 
      A = &(*A)->prox;
   *A = B;
}

void destroi(Lista *L) {
   while(*L) {
      Lista n = *L;
      *L = n->prox;
      free(n);
   }
}

// Verifica se o item x pertence à lista L
int pertence(int x, Lista L) {
   int it = L->item;
   while(L) {
      if(it == x) return 1;
      it = L-> item;
      L = L->prox;
   }
   return 0;
}

// Criação de lista com n itens, escolhidos aleatoriamente em [0, m−1]
Lista aleatoria(int n, int m) {
   srand(time(NULL));
   Lista L = NULL;
   while(n > 0) {
      L = no(rand() % m, L);
      n--;
   }
   return L;
}

// Devolve uma lista com os inteiros consecutivos de 1 até n
Lista intervalo(int n) {
   Lista I = NULL;
   while(n) {
      I = no(n, I);
      n--;
   }
   return I;
}

// Cria e devolve uma lista contendo inteiros consecutivos de p até u (para p ≤ u)
Lista intervalao(int p, int u) {
   Lista I = NULL;
   if(p > u) return I;
   for(u; u >= p; u--) I = no(u, I);
   return I;
}

// Devolve o último item da lista L (se L estiver vazia, erro fatal)
Item ultimo(Lista L) {
   if(L == NULL) abort();
   int u = L->item;
   while(L) {
      u = L->item;
      L = L->prox;
   }   
   return u;
}

// Devolve o maior item da lista L (se L estiver vazia, erro fatal)
Item maximo(Lista L) {
   if(L == NULL) abort();
   int max = L->item;
   while(L) {
      if(L->item > max) max = L->item;
      L = L->prox;
   }
   return max;
}

// Cria e devolve uma cópia invertida da lista L
Lista inversa(Lista L) {
   Lista atsil = NULL;
   while(L) {
      atsil = no(L->item, atsil); // a lista vai receber um nó que vai apontar para ela mesma
      L = L->prox;
   }
   return atsil;
}

/* FUNÇÕES RECURSIVAS */

int len(Lista L) {
   if(!L) return 0;
   return len(L->prox)+1;
}

int sum(Lista L) {
   if(!L) return 0;
   return sum(L->prox) + L->item;
}

// Cria e devolve uma cópia da lista L
Lista clone(Lista L) {
   if(!L->prox) return no(L->item, NULL);
   return no(L->item, inversa(L->prox));
}

// Devolve uma lista com n itens aleatórios em [0, m-1]
Lista rnd(int n, int m) {
   if(n == 1) return no(rand() % m, NULL);
   srand(time(NULL));
   return no(rand() % m, rnd(n-1, m));
}

Item last(Lista L) {
   if(!L) abort();
   if(!L->prox) return L->item;
   return last(L->prox);
}

int in(int x, Lista L) {
   if(!L) return 0;
   if(x == L->item) return 1;
   return in(x, L->prox);
}

// Devolve o enésimo (n≥1) item da lista L.
Item nth(int n, Lista L) {
   if(n == 1) return L->item;
   return nth(n-1, L->prox);
}

// Devolve o menor item da lista L.
Item minimum(Lista L, Item menor) {
   if(!L) return menor;
   if(L->item < menor) menor = L->item;
   return minimum(L->prox, menor);
}

// Verifica se a lista L está ordenada
int sorted(Lista L) {
   if(!L->prox) return 1;
   if(L->prox->item < L->item) return 0;
   return sorted(L->prox);
}

// Verifica se as listas A e B são iguais
int equal(Lista A, Lista B) {
   if(!A && !B) return 1;
   if((A && !B) || (!A && B)) abort(); // tamanhos diferentes
   if(A->item != B->item) return 0;
   return equal(A->prox, B->prox);
}

// Informa quantas vezes o item x ocorre na lista L
int count(Item x, Lista L) {
   if(!L) return 0;
   return (x == L->item) + count(x, L->prox);
}

// Substitui ocorrências de x por y na lista L
void replace(Item x, Item y, Lista L) {
   if(!L) return;
   if(L->item == x) L->item = y;
   replace(x, y, L->prox);  
}


/* FUNÇÕES DE IMPRESSÃO */

void exibe(Lista L) {
   while(L != NULL) {
      printf("%d\n", L->item);
      L = L->prox;
   }
}

void exibidinha(Lista L) {
   printf("[");
   while(L != NULL) {
      if(L->prox == NULL) printf("%d", L->item);
      else printf("%d,", L->item);
      L = L->prox;   
   }
   printf("]\n");
}

void exibe_rec(Lista L) {
   if(L != NULL) {
      printf("%d\n", L->item);
      exibe_rec(L->prox);
   }
}

void exibidinha_rec(Lista L) {
   if(L == NULL) {
      printf("]");      
      return;
   } 
   //printf("["); // onde eu coloco esse printf para exibi-lo somente no início?
   if(L->prox) printf("%d,", L->item);
   else printf("%d", L->item);  
   exibidinha_rec(L->prox);
}

void exibidona(Lista L) { 
   printf("[");
   exibidinha_rec(L);
   printf("\n");
}




