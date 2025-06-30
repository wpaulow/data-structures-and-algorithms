#include <stdio.h>
#include "pilha.h"

int bal(char *s){
    Pilha P = pilha(256);
    
    for(int i=0; s[i]; i++){
        switch(s[i]){
            case '(': empilha(')', P); break;
            case '[': empilha(']', P); break;
            case '{': empilha('}', P); break;
            default: 
                if(vaziap(P) || s[i] != desempilha(P)){
                    destroip(&P);
                    return 0;
                }        
        }
    }
    int r = vaziap(P);
    destroip(&P);
    return r;
}

int main(void) {
    char e[256];
    while(1){
        printf("Expressão? ");
        gets(e);
        printf("balanceada: %s\n", bal(e) ? "sim" : "não");
    }
    return 0;
}
