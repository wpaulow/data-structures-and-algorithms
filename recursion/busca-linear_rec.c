#include <stdio.h>

int rlsearch(int x, int *v, int n) {
   if(n == 0) return 0;
   if(x == v[n-1]) return 1;
   rlsearch(x, v, n-1);
}

int main(int argc, char **argv) {
   int v[8] = {66,80,31,48,27,75,19,52};
   printf("27: %s\n", rlsearch(27, v, 8) ? "está contido no vetor." : "não está contido no vetor.");
   printf("51: %s\n", rlsearch(51, v, 8) ? "está contido no vetor." : "não está contido no vetor.");
   
   return 0;
}
