#include "arvore.h"

int main(void) {
//   printf("Árvore Completa:\n");
//   Arv C = NULL;
//   srand(time(NULL));
//   C = completa(5);
//   exibe(C, 5);
//   printf("Nós Árvore Completa: %d .\n", nos(C));
//   printf("\n\n\nPrint Em Ordem: \n");
//   erd(C, altura(C));

   
//   srand(time(NULL));
//   Arv B = NULL;
//   int itens = 9;
//   B = balanceada(itens);
//   printf("Nós Árvore Balanceada: %d.\n", nos(B));
//   printf("Altura de B com %d itens: %d.\n", itens, altura(B)); 
//   printf("Árvore balanceada:\n");  
//   exibe(B, altura(B));
//   Arv BB = espelho(B);
//   printf("Árvore espelhada:\n");
//   exibe(BB, altura(BB));
//   printf("\nAs árvores %s espelhos uma da outra.\n", eh_espelho(B, BB) ? "são" : "não são");


//   Arv bal = NULL;
//   bal = bal_range(1, 9);
//   exibe(bal, altura(bal));
//   printf("\n\n\nPrint Em Ordem: \n");
//   erd(bal);
//   printf("\n");
//   printf("\n\n\nPrint Pré-Ordem: \n");
//   red(bal);
//   printf("\n");
//   printf("\n\n\nPrint Pós-Ordem: \n");
//   edr(bal);
//   printf("\n");


//   Arv alea = NULL;
//   srand(time(NULL));
//   alea = aleatoria(6, 5);
//   alea = aleatorie(9);
//   alea = merda(9);
//   int nodes = nos(alea);
//   printf("Altura de Alea com %d nós: %d.\n", nodes, altura(alea)); 
//   printf("Árvore Aleatória:\n");  
//   exibe(alea, altura(alea));
//   printf("\n\n\nPrint Em Ordem: \n");
//   erd(alea);
//   printf("\n");
//   printf("Quantidade de itens %d nessa arvrinha: %d.\n", 0, conta_itens(0, alea));
//   

//   printf("\nAs árvores %s espelhos uma da outra.\n", eh_espelho(bal, alea) ? "são" : "não são");

//   printf("\nAs árvores %s iguais.\n", iguais(bal, alea) ? "são" : "não são");
//   Arv bal2 = NULL;
//   bal2 = bal_range(1, 7);
//   printf("\nAs árvores %s iguais.\n", iguais(bal, bal2) ? "são" : "não são");
//   printf("\n\n\n");
//   Arv clone_alea = clone(alea);
//   exibe(clone_alea, altura(clone_alea));
//   printf("\nAs árvores %s iguais.\n", iguais(alea, clone_alea) ? "são" : "não são");


//   destroi(&bal);
//   printf("\n\n\n");
//   exibe(bal, altura(bal));
//   printf("Altura da árvore com %d nós: %d.\n", nos(bal), altura(bal)); 


//   printf("\n\n\n");
//   substitui(0, 33, alea);
//   exibe(alea, altura(alea));


//   printf("\n\n\n");
//   inverte_sinal(alea);
//   exibe(alea, altura(alea));


//   Item vet[8] = {19,27,36,42,55,60,73,85};
//   Arv arvizinha = bal_vet(vet, 0, 7);
//   exibe(arvizinha, altura(arvizinha));

   Arv I = arv(arv(NULL, 5, arv(NULL, -8, NULL)), 1, arv(NULL, -6, arv(NULL, 3, NULL)));

   exibe(I, altura(I));

   printf("%d\n", pos(I));

   
   return 0;
}















