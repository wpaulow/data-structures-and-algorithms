/**
 * Create the function largest(S), which receives as input a stack S and returns
 * as output the largest item in S.
 * After the function is executed, the stack S should have the same shape as it
 * had before the function was executed.
 **/

#include <stdio.h>
#include "stack.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

SItem largest(Stack S) {
    SItem big = 0, b = 0;
    Stack auxStack = stack(S->max);
    while(!isEmpty(S)){
        b = pop(S);
        push(b, auxStack);
        big = MAX(big, b);
    }
    while(!isEmpty(auxStack)) push(pop(auxStack), S);
    destroyStack(&auxStack);
    return big;
}

int main(void){
    Stack S = stack(10);
    push(71, S);
    push(72, S);
    push(73, S);
    push(74, S);
    push(75, S);
    push(76, S);
    push(77, S);
    push(7, S);
    push(6, S);
    push(5, S);

    printf("The largest item in this stack is %d.\n\n", largest(S));

    while(!isEmpty(S)) {
        printf("Printing the stack for checking: %d.\n", pop(S));
    }

    return 0;
}
