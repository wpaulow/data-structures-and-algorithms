/*
 * super-digito_recursivo.c
 * 
 * 
 */


#include <stdio.h>

int soma_digs(int n) {
	if(n < 10) return n;
	
	return soma_digs(n / 10) + n % 10;
}

int super_digito(int n) {
	if(n < 10) return n;
	
	return super_digito(soma_digs(n));
}

int main(int argc, char **argv)
{
	printf("para %d o super dígito é %d.\n", 7859, super_digito(7859));
	
	return 0;
}

