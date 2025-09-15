// Descending and non-repeating order

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
	
	while(!isEmpty(B)) {
		num = pop(B);
		while(!isEmpty(A) && top(A) > num) push(pop(A), B);
		if(isEmpty(A) || top(A) != num) push(num, A);
	}	
	
	puts("");
	while(!isEmpty(A)) printf("%d ", pop(A));
	puts("");

	destroy(&A);
	destroy(&B);
	
	return 0;
}
