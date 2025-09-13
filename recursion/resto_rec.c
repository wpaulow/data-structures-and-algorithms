/*
 * resto-recursivo.c
 *  
 */


#include <stdio.h>

int resto(int m, int n) {
	if(m < n) return m;
	
	return resto(m-n, n);
}

int main(int argc, char **argv)
{
	printf("%d\n", resto(7, 3));
   printf("%d\n", resto(15, 3));
   printf("%d\n", resto(3, 5));
	
	return 0;
}
