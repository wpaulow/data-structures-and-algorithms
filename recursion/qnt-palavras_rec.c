#include <stdio.h>
#include <string.h>

int palavras(char frase[], int p, int u){
   int aux = p;
   if(p == u) return 0;
   if(frase[p] != ' ' && (frase[++aux] == ' ' || frase[++aux] == '\0')) return palavras(frase, p+1, u)+1;   
   else return palavras(frase, ++p, u);
}

int main(void) {
   char *teste = "  Quantas  palavras existem    nesta cadeia  ";

   char *confirma = "E nessa   daqui, vagabundo    nato?";
   
   char *confirmas = "E nessa   daqui, vagabundo    nato?   A";
   
   printf("Existem %d palavras na cadeia: \"%s\".\n", palavras(teste, 0, strlen(teste)-1), teste);

   printf("Existem %d palavras na cadeia: \"%s\".\n", palavras(confirma, 0, strlen(confirma)-1), confirma);

    printf("Existem %d palavras na cadeia: \"%s\".\n", palavras(confirmas, 0, strlen(confirmas)-1), confirmas);
   
   return 0;
}
