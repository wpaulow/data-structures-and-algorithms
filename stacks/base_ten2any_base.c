#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

char baseAZ(int n){
    if (n >= 10 && n <= 35)
        return 'A' + (n - 10);
    return -1;
}

char *convertBase(int n, int base){
    static char converted[256];
    Stack S = stack(256);
    int rest, i = 0;

    while(n > 0){
        rest = n % base;
        n /= base;
        if(rest > 10) push(baseAZ(rest), S);
        else push(rest + '0', S);
    }
    while(!isEmpty(S)) converted[i++] = pop(S);
    converted[i] = '\0';
    destroy(&S);
    return converted;
}

int main(void){
    char n_in[100], base_in[100];
    int n, base;
    while(1){
        printf("Please enter a number, in base 10, of course: ");
        fgets(n_in, sizeof(n_in), stdin);
        printf("Please enter a base, between 2 and 36: ");
        fgets(base_in, sizeof(base_in), stdin);
        n = atoi(n_in);
        base = atoi(base_in);
        char *based = convertBase(n, base);
        printf("The number %d converted to %d base is %s.\n\n", n, base, based);
    }
    return 0;
}
