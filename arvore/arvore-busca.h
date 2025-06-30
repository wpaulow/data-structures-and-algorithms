#include "arvore.h"

void ins(Item x, Arv *A) {
   if(!*A) *A = arv(NULL, x, NULL);
   else if(x <= (*A)->item) ins(x, &(*A)->esq);
   else ins(x, &(*A)->dir);
}

void ins_sr(Item x, Arv *A) {
   if(!*A) *A = arv(NULL, x, NULL);
   else if(x == (*A)->item) return;
   else if(x < (*A)->item) ins_sr(x, &(*A)->esq);
   else ins_sr(x, &(*A)->dir);
}

int busca(Item x, Arv A) {
   if(!A) return 0;
   if(x == A->item) return 1;
   if(x < A->item) return busca(x, A->esq);
   else return busca(x, A->dir);
}

Item remmax(Arv *A) {
   if(*A == NULL) abort();
   if((*A)->dir == NULL) {
      Arv n = *A;
      Item x = n->item;
      *A = n->esq;
      free(n);
      return x;   
   }
   return remmax(&(*A)->dir);
}

void remraiz(Arv *A) {
   if(*A == NULL) abort();
   Arv n = *A;
   if(n->esq == NULL) *A = n->dir;
   else if(n->dir == NULL) *A = n->esq;
   else n->item = remmax(&n->esq);
   if(n != *A) free(n);
}

void rem(Item x, Arv *A) {
   if(*A == NULL) return;
   if(x == (*A)->item) remraiz(A);
   else if(x < (*A)->item) rem(x, &(*A)->esq);
   else rem(x, &(*A)->dir);
}

void rem_todos(Item x, Arv *A) {
   if(!*A) return;
   if(x <= (*A)->item) rem_todos(x, &(*A)->esq); 
   else rem_todos(x, &(*A)->dir);
   if(x == (*A)->item) remraiz(A);
}

void exibe_dec(Arv A, int n) {
   if(!A) return;
   exibe_dec(A->esq, n+1);
   printf("%*s%d\n", 3*n, "", A->item);
   exibe_dec(A->dir, n+1);
}

Item maximo(Arv A) {
   if(!A) abort();
   if(!A->dir) return A->item;
   return maximo(A->dir);
}

Item minimo(Arv A) {
   if(!A) abort();
   if(!A->esq) return A->item;
   return minimo(A->esq);
}















