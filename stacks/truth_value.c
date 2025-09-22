/*
* Program that receives a fully parenthesized Boolean expression and returns
* it postfixed without parentheses and its truth value
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

char *postfix(char *e){
    static char s[256];
    int j = 0;
    Stack S = stack(256);
    for(int i = 0; e[i]; i++){
        if(isalpha(e[i])) s[j++] = e[i];
        else if(ispunct(e[i]) && e[i] != '(' && e[i] != ')') push(e[i], S);
        else if(e[i] == ')') s[j++] = pop(S);
    }
    s[j] = '\0';
    destroy(&S);

    return s;
}

int truthValue(char *e) {
    Stack S = stack(256);
    for(int i = 0; e[i]; i++){
        if(isalpha(e[i])) push(e[i], S);
        else if(e[i] == '!') {
            char x = pop(S);
            if(x == 'F') push('T', S);
            else if(x == 'T') push('F', S);
        } else if(e[i] == '&'){
            char x = pop(S);
            char y = pop(S);
            if(x == y) push('T', S);
            else push('F', S);
        } else if(e[i] == '|'){
            char x = pop(S);
            char y = pop(S);
            if(x == 'T' || y == 'T') push('T', S);
            else push('F', S);
        }
    }
    char truthValue = top(S);
    destroy(&S);
    if(truthValue == 'T') return 1;
    if(truthValue == 'F') return 0;
}


int main(void){
    char e[256];
    while(1){
        printf("Fully Parenthesized Boolean Expression:");
        fgets(e, sizeof(e), stdin);
        char *s = postfix(e);
        printf("Postfix: %s\n", s);
        printf("Truth Value: %d\n", truthValue(s));
    }
    return 0;
}
