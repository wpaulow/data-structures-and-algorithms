/*
 * soma-dig_recursivo.c
 * 
 * 
 */


#include <stdio.h>

int soma_digs(int n) {
	if(n < 10) return n;
	
	return soma_digs(n / 10) + n % 10;
}

int main(int argc, char **argv)
{
	printf("para %d a soma dos dígitos é %d.\n", 7859, soma_digs(7859));
	
	return 0;
}

