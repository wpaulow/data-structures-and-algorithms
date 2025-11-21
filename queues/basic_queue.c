#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue Q = queue(5);
    for(int i = 0; i <= 3; i++)
        enqueue('A'+i, Q);
    while(!vaziaf(F))
        printf("%c\n", dequeue(Q));
    destroyQueue(&Q);

    return 0;
}
