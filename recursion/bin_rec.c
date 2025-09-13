#include <stdio.h>

void binario(int n) {
   if(n<2) printf("%d", n);
   else {
      binario(n/2);
      printf("%d", n%2);
   }
}

int main(void) {
   binario(16);
   return 0;
}
