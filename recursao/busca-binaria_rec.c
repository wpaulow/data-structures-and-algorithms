#include <stdio.h>

int rbsearch(int x, int *v, int p, int u){
   if(p > u) return 0;
   int m = (p + u) / 2;
   if(x == v[m]) return 1;
   if(x < v[m]) rbsearch(x, v, p, m-1);
   else rbsearch(x, v, m+1, u);
}

int main(int argc, char **argv) {   
   int v[8] = {19,27,31,48,52,66,75,80};
   printf("27: %s\n", rbsearch(27, v, 0, 7) ? "está contido no vetor." : "não está contido no vetor.");
   printf("51: %s\n", rbsearch(51, v, 0, 7) ? "está contido no vetor." : "não está contido no vetor.");   
   printf("52: %s\n", rbsearch(52, v, 0, 7) ? "está contido no vetor." : "não está contido no vetor."); 

   return 0;
}
