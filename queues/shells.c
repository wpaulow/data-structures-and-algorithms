/**
 * The core concept of the exercise is to define what constitutes a "shell"
 * (a structural property often related to well-formed or nested sequences in
 * computer science).
 * **/

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

int shell(char *c){
    Stack S = stack(strlen(c));
    push(c[0], S);
    for(int i = 1; c[i]; i++){
        if(!stackIsEmpty(S) && top(S) == c[i]) pop(S);
        else push(c[i], S);
    }
    if(stackIsEmpty(S)) {
        destroyStack(&S);
        return 1;
    } else {
        destroyStack(&S);
        return 0;
    }
}

void filter(Queue Q) {
    while(!queueIsEmpty(Q)) {
        char *dequeued_value;
        dequeue(&dequeued_value, Q);
        if(shell(dequeued_value)) printf("%s\n", dequeued_value);
    }
}

int main(int argc, char **argv) {
//   char *teste = "AAABAAABBABAAA";
//   char *teste = "BBBAAAAABA";
//   char *x = concha(teste) ? "é" : "não é";
//   printf("%s concha.\n", x); 

    Queue Q = queue(20);
    enqueue("AAAAAAAABAAABA", Q);
    enqueue("BBBBBBBBBBBBBB", Q);
    enqueue("ABBABBABBABB", Q);
    enqueue("AAABAAABBABAAA", Q);
    enqueue("ABAABAAAAAAAAA", Q);
    enqueue("AABAAAAAABAAAA", Q);
    enqueue("AAAABB", Q);
    enqueue("AABBBBAABAAB", Q);
    enqueue("ABAAAAAAAAAB", Q);
    enqueue("ABABBBABAB", Q);
    enqueue("BBBBBBBBBBBBBB", Q);
    enqueue("AABAABAAAA", Q);
    enqueue("AABAAABBBBBABB", Q);
    enqueue("BBBAAAAABA", Q);
    enqueue("BBBBBBBBBBBBBB", Q);
    enqueue("AAAAAAAAAAAABB", Q);
    enqueue("BAAAAABAAAAAAA", Q);
    enqueue("BBBBABBBBBBA", Q);
    enqueue("BBABABAAAAAABB", Q);
    enqueue("ABAABAABAB", Q);
    filter(Q); // It should display 12 shells.
    destroyQueue(&Q);

    return 0;
}
