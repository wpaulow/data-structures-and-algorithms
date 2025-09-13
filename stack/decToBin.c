    #include <stdio.h>
    #include "pilha.h"

    int main(void) {
        int n;
        Pilha P = pilha(8*sizeof(int));
        printf("Decimal? ");
        scanf("%d",&n);
        do {
            empilha(n%2,P);
            n /= 2;
        } while( n>0 );
        printf("Binario: ");
        while( !vaziap(P) )
        printf("%d",desempilha(P));
        printf("\n");
        destroip(&P);
        return 0;
    }
