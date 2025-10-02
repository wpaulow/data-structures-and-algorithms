#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

// move n items from source -> destination using helper (classic Hanoi)
void move_n(Stack src, Stack dest, Stack aux, int n) {
    if (n <= 0) return;
    if (n == 1) {
        push(pop(src), dest);
        return;
    }
    move_n(src, aux, dest, n-1);
    move_n(src, dest, aux, 1);
    move_n(aux, dest, src, n-1);
}

int main() {
    Stack source = stack(3);
    Stack destination = stack(3);
    Stack auxiliar = stack(3);

    // Stack some items on the source stack (5 is the largest)
    push(5, source);
    push(3, source);
    push(1, source);

    int n = size(source);        // count how many elements to move
    move_n(source, destination, auxiliar, n);

    // Print the items in the target stack (from top to bottom)
    int v;
    while (!isEmpty(destination)) {
        printf("%d ", pop(destination));
    }
    printf("\n");

    destroy(&source);
    destroy(&destination);
    destroy(&auxiliar);

    return 0;
}