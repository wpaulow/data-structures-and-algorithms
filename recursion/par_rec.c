#include <stdio.h>

int par(int n) {
	if (n == 0) return 1;
	else if (n == 1) return 0;
	else return par(n-2);
}


int main(int argc, char **argv) {
	int num;
	printf("Digite um número inteiro: ");
	scanf("%d", &num);

	if (par(num)) printf("%d é um número par.\n", num);
	else printf("%d é um número ímpar.\n", num);

   par(num) ? printf("%d é um número par.\n", num) : printf("%d é um número ímpar.\n", num);

   printf("%d %s.\n", num, par(num) ? "é um número par" :  "é um número ímpar");

	return 0;
}
