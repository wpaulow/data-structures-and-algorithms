// queue.h - dynamic sequential queue implementation
#include <stdlib.h>
#include <stdbool.h>

typedef int QItem;
// typedef char *QItem; // for shells.c

typedef struct queue {
    int start;       // Index of the beginning of the queue
    int end;         // Index of the end of the queue
    int size;        // Current number of elements in the queue
    int capacity;    // Maximum queue capacity
    QItem *data;
} *Queue;

Queue queue(int capacity) {
    if (capacity <= 0) return NULL;

    Queue Q = malloc(sizeof(struct queue));
    if (Q == NULL) return NULL;

    Q->data = malloc(sizeof(QItem) * capacity);
    if (Q->data == NULL) {
        free(Q);
        return NULL;
    }

    Q->start = 0;
    Q->end = 0;
    Q->size = 0;
    Q->capacity = capacity;
    return Q;
}

void destroyQueue(Queue *Q) {
    if (Q == NULL || *Q == NULL) return;
    free((*Q)->data);
    free(*Q);
    *Q = NULL;
}

bool queueIsEmpty(Queue Q) {
    return Q->size == 0;
}

bool queueIsFull(Queue Q) {
    return Q->size == Q->capacity;
}

bool enqueue(QItem element, Queue Q) {
    if (queueIsFull(Q)) {
        return false;
    }
    Q->data[Q->end] = element;
    Q->end = (Q->end + 1) % Q->capacity; // Circular feed
    Q->size++;
    return true;
}

bool dequeue(QItem *out_element, Queue Q) {
    if (queueIsEmpty(Q)) {
        return false;
    }
    *out_element = Q->data[Q->start];
    Q->start = (Q->start + 1) % Q->capacity; // Circular feed
    Q->size--;
    return true;
}