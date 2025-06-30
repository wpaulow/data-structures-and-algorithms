#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "gconio.h"
#include "pilha.h"
#include "kbhit.h"
#define MAX 50


static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0,TCSANOW,&new_settings);
}

void close_keyboard()
{
    tcsetattr(0,TCSANOW,&initial_settings);
}

/* Le o teclado sem bloquear o programa */
unsigned char kbhit()
{
    unsigned char ch;
    int nread;

    new_settings.c_cc[VMIN]= 0;
    tcsetattr(0,TCSANOW,&new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&new_settings);
    if (nread==1)
    {
    return ch;
    }
    return 0;
}

void pausa(float tempo) {
   float duracao, inicio = clock();
   do { duracao = (clock()-inicio)/CLOCKS_PER_SEC; } while( duracao<tempo );
}

int main(void) {
   Pilha px = pilha(MAX);
   Pilha py = pilha(MAX);
   srand(time(NULL));
   while( !kbhit() ) {
      for(int i=0; i<MAX; i++) {
         int x = rand()%40 + 1;
         int y = rand()%20 + 1;
         gotoxy(x,y);
         textcolor(rand()%15+1);
         putchar('*');
         pausa(0.05);
         empilha(x,px);
         empilha(y,py);
      }
      while( !vaziap(px) ) {
         gotoxy(desempilha(px),desempilha(py));
         putchar(' ');
         pausa(0.02);
      }
   }
   destroip(&px);
   destroip(&py);
   return 0;
}
