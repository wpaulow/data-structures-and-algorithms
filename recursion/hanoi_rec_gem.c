#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino) {
  if (n == 1) {
    printf("Mover disco 1 da torre %c para a torre %c.\n", origem, destino);
  } else {
    hanoi(n-1, origem, destino, auxiliar);
    printf("Mover disco %d da torre %c para a torre %c.\n", n, origem, destino);
    hanoi(n-1, auxiliar, origem, destino);
  }
}

int main() {
  int n = 3;
  char origem = 'A', auxiliar = 'B', destino = 'C';

  hanoi(n, origem, auxiliar, destino);

  return 0;
}
