// Check if the sentence is palindrome.
#include <stdio.h>
#include <ctype.h>
#include "stack.h" // gcc -I ../stacks
#include "queue.h"

int main(void) {
    char s[256];
    Queue Q = queue(256);
    Stack S = stack(256);
    printf("\nSentence? ");
    fgets(s, sizeof(s), stdin);
    for (int i=0; s[i]; i++)
        if (isalpha(s[i])) {
            enqueue(toupper(s[i]), Q);
            push(toupper(s[i]), S);
        }
        QItem dequeued_value;
        do {
            dequeue(&dequeued_value, Q);
        } while (!queueIsEmpty(Q) && dequeued_value == pop(S));
        if (queueIsEmpty(Q)) puts("The phrase is palindrome");
        else puts("The sentence is not a palindrome");
        destroyQueue(&Q);
        destroyStack(&S);
        return 0;
    }
