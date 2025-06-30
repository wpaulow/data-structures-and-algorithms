#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int valor;
  struct pilha *proximo;
} Pilha;

void empilhar(Pilha **topo, int valor) {
  Pilha *novo = malloc(sizeof(Pilha));
  novo->valor = valor;
  novo->proximo = *topo;
  *topo = novo;
}

int desempilhar(Pilha **topo) {
  if (*topo == NULL) {
    return -1;
  }

  int valor = (*topo)->valor;
  Pilha *aux = *topo;
  *topo = (*topo)->proximo;
  free(aux);

  return valor;
}

int isEmpty(Pilha *topo) {
  return topo == NULL;
}


void mover_itens(Pilha **origem, Pilha **destino, Pilha **auxiliar) {
  int valor = desempilhar(origem);
  if (valor == -1) {
    return;
  }

  if (isEmpty(*destino)) {
    empilhar(destino, valor);
  } else {
    int topoDestino = desempilhar(destino);
    if (valor > topoDestino) {
      return;
    }

    empilhar(auxiliar, valor);
    mover_itens(origem, auxiliar, destino);

    valor = desempilhar(auxiliar);
    empilhar(destino, valor);

    mover_itens(auxiliar, destino, origem);
  }
}

int main() {
  Pilha *origem = NULL, *destino = NULL, *auxiliar = NULL;

  // Empilhar alguns itens na pilha de origem
  empilhar(&origem, 5);
  empilhar(&origem, 3);
  empilhar(&origem, 1);

  // Mover os itens da pilha de origem para a pilha de destino
  mover_itens(&origem, &destino, &auxiliar);

  // Imprimir os itens da pilha de destino
  while (!isEmpty(destino)) {
    printf("%d ", desempilhar(&destino));
  }

  printf("\n");

  return 0;
}
