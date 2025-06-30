/*
 * produto-recursao.c
 *
 */
 
int produto(int m, int n) {
	if (n == 0) return 0;
	
	return produto(m, n-1) + m;
}


#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", produto(4, 3));
   printf("%d\n", produto(3, 4));
   printf("%d\n", produto(1, 3));
   printf("%d\n", produto(5, 1));	

	return 0;
}

