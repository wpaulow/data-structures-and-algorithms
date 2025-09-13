int suc(int n) { return n+1; }

int pred(int n) { return n-1; }

int soma(int x, int y) {
   if(y == 0) return x;
   else return soma(suc(x), pred(y));
}

int subtracao(int x, int y) {
   if(y == 0) return x;
   else return subtracao(pred(x), pred(y));
}

int dobro(int n) {
   if(n == 0) return 0;
   else return suc(suc(dobro(pred(n))));
}

int metade(int n) {
   if(n < 2) return 0;
   else return suc(metade(pred(pred(n))));
}

int minimo(int x, int y) {
   if(x == y) return x;
   if(x == 0) return x;
   if(y == 0) return y;
   else return suc(minimo(pred(x), pred(y)));
}

int maximo(int x, int y) {
   if(x == y) return x;
   if(x == 0) return y;
   if(y == 0) return x;
   else return suc(maximo(pred(x), pred(y)));
}

int par(int n) {
   if(n == 0) return 1;
   if(n == 1) return 0;
   else return par(pred(pred(n)));
}

int impar(int n) {
   if(n == 0) return 0;
   if(n == 1) return 1;
   else return par(pred(pred(n)));
}
