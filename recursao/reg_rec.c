#include <stdio.h>

void cr(int n) {
   if(n == 0) return;
   printf("%d\n", n);
   cr(n-1);
}

int main(void) {
   cr(5);
   return 0;
}
