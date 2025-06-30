#include <stdio.h>

typedef struct {
    char a;
    float b;
} Reg;

int main() {
    Reg r = {'x', 2.5};
    Reg *q = &r;
    printf("%c %lf\n", q->a, q->b);
    printf("%c %lf\n", (*q).a, (*q).b);
    
    return 0;
}
