/*
 * quadrado-recursivo.c
 * 
 * 
 */
#include <stdio.h>

int quad_rec(int n) {
	if(n == 1) return 1;
	
	return quad_rec(n-1) + (2 * n-1);
}

int main(int argc, char **argv)
{
	printf("quadrado de %d é %d.\n", 2, quad_rec(2));
	printf("quadrado de %d é %d.\n", 4, quad_rec(4));
	printf("quadrado de %d é %d.\n", 5, quad_rec(5));
	
	return 0;
}

