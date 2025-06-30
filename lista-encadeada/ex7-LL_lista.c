#include "lista.h"

Lista unico(Lista L){
    if(!L) return NULL;
    Lista resto = unico(L->prox);
   exibidinha(resto);
    return in(L->item, resto) ? resto : no(L->item, resto);
}

int main(){
    Lista I = no(1, no(3, no(1, no(2, no(3, no(2, (3, no(1, NULL))))))));
//    exibidinha(I);
    printf("Lista sem repeticoes:\n");
    exibidinha(unico(I));
    return 0;
}
