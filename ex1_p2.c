/*
 * ex1_p2.c
 * 
 * 
 */


#include <stdio.h>

int f(int n) {
	if(n == 1) return 0;
	return f(n/2) + 1;
}

int main(int argc, char **argv)
{
	printf("%d\n", f(16));
	return 0;
}

