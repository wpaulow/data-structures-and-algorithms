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

int isEmpty(Stack S) {
    if(S->top == -1) return 1;
    else return 0;
}

int isFull(Stack S) {
    if(S->top == S->max-1) return 1;
    else return 0;
}

void push(SItem x, Stack S) {
    if(isFull(S)) {
        puts("Error: Full Stack.");
        abort();
    }
    S->top++;
    S->item[S->top] = x;
}

SItem pop(Stack S) {
    if(isEmpty(S)) {
        puts("Error: Empty Stack.");
        abort();
    }
    SItem x = S->item[S->top];
    S->top--;
    return x;
}

SItem top(Stack S) {
    if(isEmpty(S)) {
        puts("Error: Empty Stack.");
        abort();
    }
    return S->item[S->top];
}

int size(Stack S) {
    return (S->top)+1;
}

void destroy(Stack *S) {
    free((*S)->item);
    free(*S);
    *S = NULL;
}

