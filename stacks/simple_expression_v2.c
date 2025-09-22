/**
 * Receives a not necessarily completely parenthesized arithmetic expression,
 * but whose operands are single-digit numbers.
 * And returns the arithmetic expression in its postfix form, along with the
 * result of the expression.
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int priority(char op) {
    switch(op) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}

char *postfix(char *e) {
    static char s[256];
    int j = 0;
    Stack S = stack(256);

    for(int i=0; e[i]; i++){
        if(e[i] == '(') push('(', S);
        else if(isdigit(e[i])) s[j++] = e[i];
        else if(strchr("+/-*", e[i])){
            while(!isEmpty(S) && priority(top(S)) >= priority(e[i]))
                s[j++] = pop(S);
            push(e[i], S);
        }
        else if(e[i] == ')'){
            while(top(S) != '(') s[j++] = pop(S);
            pop(S);
        }
    }
    while(!isEmpty(S)) s[j++] = pop(S);
    s[j] = '\0';
    destroy(&S);
    return s;
}

int result(char *e) {
    Stack S = stack(256);
    for(int i = 0; e[i]; i++){
        if(isdigit(e[i])) push(e[i] - '0', S);
        else if(strchr("+*-/", e[i])) {
            int y = pop(S);
            int x = pop(S);
            switch(e[i]){
                case '+': push(x+y, S); break;
                case '-': push(x-y, S); break;
                case '*': push(x*y, S); break;
                case '/': push(x/y, S); break;
            }
        }
    }
    int r = top(S);
    destroy(&S);
    return r;
}

int main(void){
    char e[256];
    while(1){
        printf("Expression Not Necessarily Completely Parenthesized: ");
        fgets(e, sizeof(e), stdin);
        char *s = postfix(e);
        printf("Postfix Arithmetic Expression: %s\n", s);
        printf("Result: %d\n", result(s));
    }
    return 0;
}

