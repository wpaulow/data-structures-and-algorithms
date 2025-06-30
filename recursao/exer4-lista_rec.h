#include <stdlib.h>
#include "exer3-lista_rec.h"

int produto(int x, int y) {
   if(y == 0 || x == 0) return 0;
   return soma(x, produto(x, pred(y)));
}

int quociente(int x, int y) {
   if(y == 0) abort();   
   if(x < y) return 0;
	if(x == y) return 1;
   return suc(quociente(subtracao(x, y), y));
}

int resto(int x, int y) {
   if(y == 0) abort();  
   if(x < y) return x;
   return resto(subtracao(x, y), y);
}

int potencia(int x, int y) {
   if(y == 0) return 1;
   return produto(x, potencia(x, pred(y)));
}

int quadrado(int x) {
   if(x == 1) return 1;
	return suc(soma(dobro(pred(x)), quadrado(pred(x))));
}
