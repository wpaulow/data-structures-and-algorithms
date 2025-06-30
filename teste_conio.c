#include <stdio.h>
#include "gconio.h"
 
int main(){
  int linha=5, coluna=10;
  clrscr();   //limpa a tela
  gotoxy(coluna,linha);  //vai para a posição coluna 10, linha 5
  printf("--> Terminal de Informação <--nn");
  delay(2000);  //espera 2 segundos
  getchar();   //espera uma entrada do teclado
  return 0;
}
