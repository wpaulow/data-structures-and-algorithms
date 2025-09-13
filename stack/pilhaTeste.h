#include <stdio.h>
#include <stdlib.h>

typedef int Itemp;

typedef struct pilha {
    int max;      // tamanho máximo da pilha
    int topo;     // posição do topo da pilha
    Itemp *item;  // array que armazena os elementos da pilha
} *Pilha;


Pilha pilha(int max) {
    Pilha p = (Pilha)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    p->max = max;
    p->topo = -1;
    p->item = (Itemp*)malloc(max * sizeof(Itemp));
    if (p->item == NULL) {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    return p;
}

void destroiP(Pilha p) {
    free(p->item);
    free(p);
    p = NULL;
}

int vaziaP(Pilha p) {
    return p->topo == -1;
}

int cheiaP(Pilha p) {
    return p->topo == p->max - 1;
}

void empilha(Pilha p, Itemp valor) {
    if (cheiaP(p)) {
        printf("Erro: pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->item[p->topo] = valor;
}

int desempilha(Pilha p) {
    if (vaziaP(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    int valor = p->item[p->topo];
    p->topo--;
    return valor;
}

int topoP(Pilha p) {
    if (vaziaP(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    return p->item[p->topo];
}
