// reverses all characters in a sentence except the word order
#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main(int argc, char **argv) {
	char phrase[100];
	printf("Type a phrase: ");
	fgets(phrase, 100, stdin);
	Stack S = stack(100);

	for(int i = 0; phrase[i]; i++){
		char charlinho = phrase[i];
		if(charlinho != ' ') push(charlinho, S);
		else {
			while(!isEmpty(S)) printf("%c", pop(S));
			printf("%c", charlinho);
		}
	}
	
	while(!isEmpty(S)) printf("%c", pop(S));
	puts(" ");

    destroy(&S);
    
	return 0;
}
