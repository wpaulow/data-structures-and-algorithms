#include <stdio.h>

void cp(int n) {
   if(n == 0) return;
   cp(n-1);
   printf("%d\n", n);
}

int main(void) {
   cp(5);
   return 0;
}
