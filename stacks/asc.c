// Ascending order

#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv)
{
	int x, y, num;
	printf("Enter the length of the input: ");
	scanf("%d", &x);

	Stack A = stack(x);
	Stack B = stack(x);

	printf("Enter the following %d numbers:\n", x);

	for(int i = 0; i < x; i++) {
		scanf("%d", &y);
		push(y, B);
	}
	
	while(!stackIsEmpty(B)) {
		num = pop(B);
		while(!stackIsEmpty(A) && top(A) < num) push(pop(A), B);
		push(num, A);
	}	
	
	puts("");
	while(!stackIsEmpty(A)) printf("%d ", pop(A));
	puts("");

    destroyStack(&A);
    destroyStack(&B);

	return 0;
}

