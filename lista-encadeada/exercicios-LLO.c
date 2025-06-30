#include <stdio.h>
#include "lista-ord.h"

int main() {
   // exercício 2
//   Lista I = NULL;
//
//   ins_isr(4,&I);
//   ins_isr(1,&I);
//   ins_isr(3,&I);
//   ins_isr(5,&I);
//   ins_isr(3,&I);
//   ins_isr(2,&I);
//
//   exibidona(I);

   // exercício 3
   Lista I = NULL;
   
   ins_rec(4,&I);
   ins_rec(1,&I);
   ins_rec(3,&I);
   ins_rec(5,&I);
   ins_rec(3,&I);
   ins_rec(3,&I);
   ins_rec(2,&I);

   exibidona(I);
//
   // exercício 4
//   Lista I = NULL;
//   
//   ins_rsr(4,&I);
//   ins_rsr(1,&I);
//   ins_rsr(3,&I);
//   ins_rsr(5,&I);
//   ins_rsr(3,&I);
//   ins_rsr(2,&I);
//
//   exibidona(I);

   // exercício 5 é o exibe_rec() ou o exibidona() da lista.h

   // exercício 6
//   exiba_ri(I);

   // exercício 8
//   rem_todo(3, &I);
//   exibidona(I);

   // exercício 10
//   printf("O Item %d %s na lista.\n", 2, pert_rec(2, I) ? "está" : "não está");
//   printf("O Item %d %s na lista.\n", 7, pert_rec(7, I) ? "está" : "não está");

   // exercício 11
//   printf("A lista %s simplesmente crescente.\n", osc(I) ? "está" : "não está");
//   printf("A lista %s estritamente crescente.\n", oec(I) ? "está" : "não está");
//
//   Lista A = NULL;
//   
//   ins_inv(4,&A);
//   ins_inv(1,&A);
//   ins_inv(3,&A);
//   ins_inv(5,&A);
//   ins_inv(3,&A);
//   ins_inv(3,&A);
//   ins_inv(2,&A);
//
//   exibidona(A);
//
//   printf("A lista %s simplesmente decrescente.\n", osd(A) ? "está" : "não está");
//   printf("A lista %s estritamente decrescente.\n", oed(A) ? "está" : "não está");

//   rem_rec(3, &I);
//   exibidona(I);
//
//   rem_todo_rec(3, &I);
//   exibidona(I);

//   remove_toda(3, &I);
//   exibidona(I);

//   remove_toda_rec(3, &I);
//   exibidona(I);

//   printf("%d.\n", remove_maximo(&I));
//   exibidona(I);

   printf("%d.\n", remove_maximo_rec(&I));
   exibidona(I);

   return 0;

}
