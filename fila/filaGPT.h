#include <stdlib.h>

typedef struct {
    int *data;      
    int start;      
    int end;        
    int size;       
    int capacity;   
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->data = (int*) malloc(sizeof(int) * capacity);
    q->start = 0;
    q->end = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue *q, int element) {
    if (q->size == q->capacity) {
        printf("Queue is full\n");
        return;
    }
    q->end++;
    q->end %= q->capacity;
    q->data[q->end] = element;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = q->data[q->start];
    q->start++;
    q->start %= q->capacity;
    q->size--;
    return element;
}

void destroyQueue(Queue *q) {
    free(q->data);
    free(q);
}

