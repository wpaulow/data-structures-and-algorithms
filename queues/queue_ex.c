// This program simulates the sharing of a CPU among multiple processes.
#include <stdio.h>
#include "queue.h"

#define timeslice 3 // Maximum uninterrupted CPU usage time

int main(void) {
    Queue Q = queue(5);
    enqueue(17, Q); // The first process requires 7 seconds to complete.
    enqueue(25, Q);
    enqueue(39, Q);
    enqueue(46, Q);

    while(!queueIsEmpty(Q)) {
        QItem x;
        dequeue(&x, Q);
        int p = x / 10;
        int t = x % 10;
        if(t > 3) enqueue(p*10 + (t-timeslice), Q);
        else printf("Process %d completed\n", p);
    }
    destroyQueue(&Q);

    return 0;
}
