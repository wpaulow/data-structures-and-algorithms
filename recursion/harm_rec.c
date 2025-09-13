#include <stdio.h>

float h(int n) {
   if(n == 1) return 1;
   return h(n-1) + 1.0/n;
}

int main(void) {
   printf("Harmonica = %.2f\n", h(2));
   printf("Harmonica = %.2f\n", h(3));
   printf("Harmonica = %.2f\n", h(4));
   printf("Harmonica = %.2f\n", h(5));
   return 0;
}
