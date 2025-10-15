// stack.h - sequential dynamic stack implementation
#include <stdio.h>
#include <stdlib.h>

//typedef float Itemp;
typedef int SItem;

typedef struct stack {
    int    max;
    int    top;
    SItem *item;
}*Stack;

Stack stack(int max) {
    Stack S = malloc(sizeof(struct stack));
    S->max  = max;
    S->top = -1;
    S->item = malloc(max*sizeof(SItem));
    return S;
}

int stackIsEmpty(Stack S) {
    if(S->top == -1) return 1;
    else return 0;
}

int stackIsFull(Stack S) {
    if(S->top == S->max-1) return 1;
    else return 0;
}

void push(SItem x, Stack S) {
    if(stackIsFull(S)) {
        puts("Error: Full Stack.");
        abort();
    }
    S->top++;
    S->item[S->top] = x;
}

SItem pop(Stack S) {
    if(stackIsEmpty(S)) {
        puts("Error: Empty Stack.");
        abort();
    }
    SItem x = S->item[S->top];
    S->top--;
    return x;
}

SItem top(Stack S) {
    if(stackIsEmpty(S)) {
        puts("Error: Empty Stack.");
        abort();
    }
    return S->item[S->top];
}

int stackSize(Stack S) {
    return (S->top)+1;
}

void destroyStack(Stack *S) {
    free((*S)->item);
    free(*S);
    *S = NULL;
}

