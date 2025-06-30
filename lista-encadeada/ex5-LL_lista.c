#include "lista.h"

Lista range(int p, int u, int k) {
   if((u-p) * k <= 0) return NULL;
   return no(p, range(p+k, u, k));
}

Lista progressao_passo(int p, int u, int k) {
   if(k <= 0) return NULL;
   if(p >= u) return NULL;
   return no(p, progressao_passo(p+k, u, k));
}

Lista regressao_passo(int p, int u, int k) {
   if(k >= 0) return NULL;
   if(p <= u) return NULL;
   return no(p, regressao_passo(p+k, u, k));
}

int main(void) {
//   Lista A = progressao_passo(0,7,2);
   Lista S = regressao_passo(10,0,-3);
//   exibidona(A);
   exibidona(S);

   return 0;
}
