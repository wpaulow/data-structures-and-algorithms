/*
 * quociente-recursivo.c
 *  
 */


#include <stdio.h>
#include <stdlib.h>

int quociente(int m, int n) {
	if(m < n) return 0;
	if(m == n) return 1;
   if(n == 0) abort();
	
	return quociente(m-n, n) + 1;
}

int main(int argc, char **argv)
{
	printf("%d\n", quociente(1, 3));
   printf("%d\n", quociente(3, 1));
   printf("%d\n", quociente(6, 3));
   printf("%d\n", quociente(15, 3));
   printf("%d\n", quociente(5, 2));
   printf("%d\n", quociente(5, 0));

	return 0;
}

