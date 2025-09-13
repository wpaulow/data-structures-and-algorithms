#include "lista.h"

Lista progressao(int p, int u) {
   if(p == u) return no(p, NULL);
   return no(--p, progressao(++p, u));
}

Lista regressao(int p, int u) {
   if(p == u) return no(u, NULL);
   return no(++p, regressao(--p, u));
}

int main(void) {
   Lista K = progressao(2, 5);
   exibidinha(K);  

   Lista L = regressao(4, 1);
   exibidinha(L);

   return 0;
}
