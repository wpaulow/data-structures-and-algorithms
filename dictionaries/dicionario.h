#include "mapa.h"
/*
 a implementação desse dicionário só vai funcionar se for
 arrumada a imp do mapa.h.
 o correto é criar dois mapas, um para chaves numéricas e,
 outro para chaves alfanuméricas
*/

typedef struct dic {
   int tam;
   Map *vet;
} *Dic;

int hash(int c, int m) {
   return (c % m);
}

unsigned hash_alf(char *c, int m) {
   unsigned s = 0;
   for(int i = 0; c[i]; i++)
      s += (i+1) * c[i];
   return (s % m);
}

Dic dic(int m) {
   Dic d = malloc(sizeof(struct dic));
   d->tam = m;
   d->vet = malloc(m*sizeof(Map));
   for(int i = 0; i < m; i++) d->vet[i] = NULL;
   return d;
}

void insd(Chave c, Valor v, Dic d) {
   insm(c, v, &d->vet[hash(c, d->tam)]);
}

void remd(Chave c, Dic d) {
   remm(c, &d->vet[hash(c, d->tam)]);
}

int pertd(Chave c, Valor v, Dic d) {
   return pertm(c, v, d->vet[hash(c, d->tam)]);   
}

void exibed(Dic d) {
   for(int i = 0; i < d->tam; i++){
      printf("%d: ", i);
      exibem(d->vet[i]);   
   }
}

void destroid(Dic *d) {
   for(int i = 0; i < (*d)->tam; i++) 
      destroim(&(*d)->vet[i]);
   free(*d);
   *d = NULL;
}












