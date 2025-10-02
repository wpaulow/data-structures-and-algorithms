#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "gconio.h"
#include "kbhit.h"
#include "stack.h"
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

// Read the keyboard without blocking the program
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

void stop(float time_x) {
    float duration, start = clock();
    do {
        duration = (clock()-start)/CLOCKS_PER_SEC;
    } while(duration < time_x);
}

int main(void) {
    init_keyboard();
    Stack px = stack(MAX);
    Stack py = stack(MAX);
    srand(time(NULL));
    while(!kbhit()) {
        for(int i=0; i < MAX; i++) {
            int x = rand() % 40 + 1;
            int y = rand() % 20 + 1;
            gotoxy(x,y);
            textcolor(rand() % 15 + 1);
            putchar('*');
            stop(0.05);
            push(x,px);
            push(y,py);
        }
        while(!isEmpty(px)) {
            gotoxy(pop(px), pop(py));
            putchar(' ');
            stop(0.02);
        }
    }
    close_keyboard();
    destroyStack(&px);
    destroyStack(&py);
    return 0;
}
