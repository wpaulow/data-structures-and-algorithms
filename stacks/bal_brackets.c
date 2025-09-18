/*
* balancing parentheses, braces, brackets
* balanced    =  "[{()()}{}]"
* unbalanced  =  "{[(}])"
*/

#include <stdio.h>
#include <string.h>
#include "stack.h"

int bal(char *str){
    Stack S = stack(256);
    
    for(int i = 0; str[i]; i++){
        switch(str[i]){
            case '(': push(')', S); break;
            case '[': push(']', S); break;
            case '{': push('}', S); break;
            default: 
                if(isEmpty(S) || str[i] != pop(S)){
                    destroy(&S);
                    return 0;
                }        
        }
    }
    int r = isEmpty(S);
    destroy(&S);
    return r;
}

int main(void) {
    char e[256];
    while(1){
        printf("Expression? ");
        fgets(e, 256, stdin);
        e[strcspn(e, "\n")] = '\0';
        printf("Your expression is: %s\n", bal(e) ? "balanced" : "unbalanced");
    }
    return 0;
}
