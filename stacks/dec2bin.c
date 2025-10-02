// converts a decimal number to binary
#include <stdio.h>
#include "stack.h"

int main(void) {
    int n;
    Stack S = stack(8*sizeof(int));
    printf("Decimal? ");
    scanf("%d",&n);
    do {
        push(n % 2, S);
        n /= 2;
    } while(n > 0);
    printf("Binary: ");
    while(!isEmpty(S))
        printf("%d", pop(S));
    printf("\n");
    destroyStack(&S);
    return 0;
}
