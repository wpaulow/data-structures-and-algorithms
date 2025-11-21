/**
* The objective is to create a function, mtt(F, P), that calculates the
* minimum total time required to execute n processes in a specific ideal
* order.
**/

#include <stdio.h>
#include "stack.h" // gcc -I ../stacks
#include "queue.h"

int mtt(Stack S, Queue Q) {
    static int c_mtt = 0;

    while(!stackIsEmpty(S)) {
        QItem dequeued_value;
        dequeue(&dequeued_value, Q);
        if(top(S) != dequeued_value){
            enqueue(dequeued_value, Q);
            c_mtt++;
        } else {
            pop(S);
            c_mtt++;
        }
    }
    return c_mtt;
}

int main(int argc, char **argv) {
    Queue Q = queue(3);
    enqueue(2, Q);
    enqueue(3, Q);
    enqueue(1, Q);

    Stack S = stack(3);
    push(2, S);
    push(3, S);
    push(1, S);

    printf("\nMinimum total time: %d\n\n", mtt(S,Q));
    destroyStack(&S);
    destroyQueue(&Q);
    return 0;

}
