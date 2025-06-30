#include <stdio.h>

int main(void) {
   // Operadores lógicos bit a bit
   int a = 5; // 00000101 em binário
   int b = 3; // 00000011 em binário

   int c = a & b; // 00000001 em binário, apenas os bits 1 em ambos os operandos são 1
   int d = a | b; // 00000111 em binário, pelo menos um bit 1 em ambos os operandos é 1
   int e = a ^ b; // 00000110 em binário, os bits diferentes em ambos os operandos são 1
   int f = ~a; // 11111010 em binário, todos os bits são invertidos

   // Operadores de deslocamento de bits
   int x = 3; 
   x = x << 1; // multiplica por 2, se desloca 1

   int y = 5; 
   y = y >> 1; // divide por 2, se desloca 1
   
   printf("a = %d\n", a); // 5
   printf("b = %d\n", b); // 3
   printf("c = %d\n", c); // 1
   printf("d = %d\n", d); // 7
   printf("e = %d\n", e); // 6
   printf("f = %d\n", f); // -6

   printf("x = %d\n", x); // 6
   printf("a = %d\n", y); // 2
      

   return 0;
}
