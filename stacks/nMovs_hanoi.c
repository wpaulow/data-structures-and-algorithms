#include <stdio.h>

int hanoi(int n, char origem, char auxiliar, char destino) {
  if (n == 1) {
    printf("Mover disco 1 da torre %c para a torre %c.\n", origem, destino);
  return 1;
  } else {
    int movimentos = 0;
    movimentos += hanoi(n-1, origem, destino, auxiliar);
    printf("Mover disco %d da torre %c para a torre %c.\n", n, origem, destino);
    movimentos++;
    movimentos += hanoi(n-1, auxiliar, origem, destino);
    return movimentos;
  }
}

int main() {
  int n = 4;
  char origem = 'A', auxiliar = 'B', destino = 'C';

  int movs = hanoi(n, origem, auxiliar, destino);

  printf("%d movimentos necessários.\n", movs);

  return 0;
}
