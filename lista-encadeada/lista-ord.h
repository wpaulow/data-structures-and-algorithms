#include "lista.h"

// exibição recursiva em ordem inversa
void exiba_ri(Lista L) {
   if(L != NULL) {
      exiba_ri(L->prox);
      printf("%d\n", L->item);
   }
}

void ins(Item x, Lista *L) {
   while(*L && x > (*L)->item) 
      L = &(*L)->prox;
   *L = no(x, *L);
}

// inserir iterativo sem repetição
void ins_isr(Item x, Lista *L) {
   while(*L && x > (*L)->item) 
      L = &(*L)->prox;
   if(*L && x == (*L)->item) return;
   *L = no(x, *L);
}

void ins_rec(Item x, Lista *L) {
   if(*L == NULL || x < (*L)->item) *L = no(x, *L); // se mudar a comparação do x com o item, muda a inserção crescente ou decrescente
   else ins_rec(x, &(*L)->prox);
}

// inserir recursivo rem repetição
void ins_rsr(Item x, Lista *L) {
   if(*L == NULL || x < (*L)->item) *L = no(x, *L);
   if(*L && x == (*L)->item) return;
   else ins_rsr(x, &(*L)->prox);
}

Item pert(Item x, Lista L) {
   while(L && x > L->item) L = L->prox;
   return (L && x == L->item);
}

Item pert_rec(Item x, Lista L) {
   if(!L) return 0;
   if(x == L->item) return 1;
   return pert_rec(x, L->prox);
}

void rem(Item x, Lista *L) {
   while(*L && x > (*L)->item) 
      L = &(*L)->prox;
   if(*L == NULL || x < (*L)->item) return;
   Lista temp = *L;
   *L = temp->prox;
   free(temp);
}

void rem_rec(Item x, Lista *L) {
   if(!*L || x < (*L)->item) return;
   if(x == (*L)->item) {
      Lista tmp = *L;
      *L = tmp->prox;
      free(tmp);  
   } 
   else rem_rec(x, &(*L)->prox);
}

void rem_todo(Item x, Lista *L) {
   while(*L && x > (*L)->item) 
      L = &(*L)->prox;
   if(*L == NULL || x < (*L)->item) return;
   while(x == (*L)->item) {
      Lista temp = *L;
      *L = temp->prox;
      free(temp);
   }
}

void rem_todo_rec(Item x, Lista *L) {
   if(!*L || x < (*L)->item) return;
   else rem_todo_rec(x, &(*L)->prox);
   if(x == (*L)->item) {
      Lista tmp = *L;
      *L = tmp->prox;
      free(tmp);  
   } 
}

// ordenada simples crescente
int osc(Lista L) {
   if(!L->prox) return 1;
   if(L->item > L->prox->item) return 0;
   return osc(L->prox);
}

// ordenada estritamente crescente
int oec(Lista L) {
   if(!L->prox) return 1;
   if(L->item >= L->prox->item) return 0;
   return oec(L->prox);
}

// ordenada simples decrescente
int osd(Lista L) {
   if(!L->prox) return 1;
   if(L->item < L->prox->item) return 0;
   return osd(L->prox);
}

// ordenada estritamente decrescente
int oed(Lista L) {
   if(!L->prox) return 1;
   if(L->item <= L->prox->item) return 0;
   return oed(L->prox);
}

// gemini
void ins_inv(Item x, Lista *L) {
   if(*L == NULL) {
    *L = no(x, NULL);
    return;
  }
  if((*L)->item < x) {
    *L = no(x, *L);
    return;
  }
  ins_inv(x, &(*L)->prox);
}


// remove todos usando a função descarta(), como o profs pediu na tarefa

Item descarta(Lista *L) {
   if(!*L) abort();
   Lista n = *L;
   Item x = n->item;
   *L = n->prox;
   free(n);
   return x;
}

void remove_toda(Item x, Lista *L) {
   while(*L && x > (*L)->item) 
      L = &(*L)->prox;
   if(!*L || x < (*L)->item) return;
   while(x == (*L)->item) {
      descarta(&(*L));
   }
}

void remove_toda_rec(Item x, Lista *L) {
   if(!*L || x < (*L)->item) return;
   else remove_toda_rec(x, &(*L)->prox);
   if(x == (*L)->item) {
      descarta(&(*L));
   } 
}

Item remove_maximo(Lista *L) {
   while((*L)->prox) 
      L = &(*L)->prox;
   return descarta(&(*L));
}

Item remove_maximo_rec(Lista *L) {
   if(!(*L)->prox) return descarta(&(*L));   
   remove_maximo_rec(&(*L)->prox);
}



















