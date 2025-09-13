#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Chave;
//typedef char Chave[22];
typedef char Valor[22];

typedef struct map {
   Chave chave;
   Valor valor;
   struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
   Map n = malloc(sizeof(struct map));
   n->chave = c;
   strcpy(n->valor, v);
   n->prox = p;
   return n;
}

Map no_map_char(Chave c, Valor v, Map p) {
   Map n = malloc(sizeof(struct map));
   strcpy(n->chave, c);
   strcpy(n->valor, v);
   n->prox = p;
   return n;
}

void exibem(Map M) {
   printf("[");
   while(M) {
      printf("(%d,%s)",M->chave,M->valor);
      if(M->prox) printf(",");
      M = M->prox;
   }
   printf("]\n");
}

void exibem_char(Map M) {
   printf("[");
   while(M) {
      printf("(%s,%s)",M->chave,M->valor);
      if(M->prox) printf(",");
      M = M->prox;
   }
   printf("]\n");
}

void insm(Chave c, Valor v, Map *M) {
   while(*M && c > (*M)->chave) 
      M = &(*M)->prox;
   if(*M && c == (*M)->chave)
      strcpy((*M)->valor,v);
   else *M = no_map(c,v,*M);
}

void insm_char(Chave c, Valor v, Map *M) {
   while(*M && strcmp(c, (*M)->chave) > 0) 
      M = &(*M)->prox;
   if(*M && strcmp(c, (*M)->chave) == 0)
      strcpy((*M)->valor, v);
   else *M = no_map_char(c,v,*M);
}

void insmr(Chave c, Valor v, Map *M) {
   if(!*M || c < (*M)->chave)
      *M = no_map(c, v, *M);
   else if(c == (*M)->chave)
      strcpy((*M)->valor, v);
   else insmr(c, v, &(*M)->prox);
}

void insmr_char(Chave c, Valor v, Map *M) {
   if(!*M || strcmp(c, (*M)->chave) < 0)
      *M = no_map_char(c, v, *M);
   else if(strcmp(c, (*M)->chave) == 0)
      strcpy((*M)->valor, v);
   else insmr_char(c, v, &(*M)->prox);
}

void remm(Chave c, Map *M) {
   while(*M && c > (*M)->chave) 
      M = &(*M)->prox;
   if(*M == NULL || c != (*M)->chave) return;
   Map n = *M;
   *M = n->prox;
   free(n);
}

void remm_char(Chave c, Map *M) {
   while(*M && strcmp(c, (*M)->chave) > 0) 
      M = &(*M)->prox;
   if(*M == NULL || strcmp(c, (*M)->chave) != 0) return;
   Map n = *M;
   *M = n->prox;
   free(n);
}

void remmr(Chave c, Map *M) {  
   if(!*M || c < (*M)->chave) return;
   if(c == (*M)->chave) {
      Map n = *M;
      *M = n->prox;
      free(n);   
   } 
   else remmr(c, &(*M)->prox);
}

void remmr_char(Chave c, Map *M) {  
   if(!*M || strcmp(c, (*M)->chave) < 0) return;
   if(strcmp(c, (*M)->chave) == 0) {
      Map n = *M;
      *M = n->prox;
      free(n);   
   } 
   else remmr_char(c, &(*M)->prox);
}

int pertm(Chave c, Valor v, Map M) {
   while(M && c > M->chave) 
      M = M->prox;
   if(M && c == M->chave) 
      strcpy(v, M->valor);
   return (M && c == M->chave);
}

int pertm_char(Chave c, Valor v, Map M) {
   while(M && strcmp(c, M->chave) > 0) 
      M = M->prox;
   if(M && strcmp(c, M->chave) == 0) 
      strcpy(v, M->valor);
   return (M && strcmp(c, M->chave) == 0);
}

int pertmr(Chave c, Valor v, Map I) {
   if(!I || c < I->chave) return 0;
   if(c == I->chave) {
      strcpy(v, I->valor);
      return 1; 
   }
   return pertmr(c, v, I->prox);
}

int pertmr_char(Chave c, Valor v, Map I) {
   if(!I || strcmp(c, I->chave) < 0) return 0;
   if(strcmp(c, I->chave) == 0) {
      strcpy(v, I->valor);
      return 1; 
   }
   return pertmr_char(c, v, I->prox);
}

void destroim(Map *I) {
   while(*I) {
      Map n = *I;
      *I = n->prox;
      free(n);
   }
}

void destroimr(Map *I) {
   if(!*I) return;
   destroimr(&(*I)->prox);
   Map n = *I;
   *I = n->prox;
   free(n);
}




