#include <stdio.h>

int termial(int n) {
   if(n == 0) return 0;
   return termial(n-1) + n;
}

int main(void) {
   //int n = 5;
   printf("Termial = %d\n", termial(5));
   return 0;
}
