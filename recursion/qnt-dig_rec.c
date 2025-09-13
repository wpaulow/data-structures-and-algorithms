/*
 * exer15-rec.c
 * 
 * quantidade de dígitos binários para representar um decimal
 */


#include <stdio.h>

int qd(int n) {
   if(n < 2) return 1;
	return qd(n / 2) + 1;
}

int main(int argc, char **argv)
{
	printf("para %d a quantidade de dígitos em binário é %d.\n", 13, qd(13));
   printf("para %d a quantidade de dígitos em binário é %d.\n", 130, qd(130));
	
	return 0;
}

