/*
 * exer1-ord.c
 * 
 */

#include <stdio.h>
#include "ord_busca.h"
/*
void exibe(int *v, int nV){
	while(*v) printf("%d\n", *(v++));
}
*/

void exibe(int v[], int n_v){
	for(int i = 0; i < 10; i++) printf("%d\n", v[i]);
}

int main(int argc, char **argv)
{
	int v[10] = {83,31,91,46,27,20,96,25,96,80};
   bsort(v,10);
   exibe(v,10);
   return 0;
}

