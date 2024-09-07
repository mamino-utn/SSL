#include <stdlib.h> // malloc free exit

void f(void);   // alcance global (externo)

int *g(int);

static int a;   //Static

int main (void) {
    int b=1;
    f();

    int *p= &b; //Stack
    *p=3;

    p = malloc(sizeof *p);  //Heap
    if (NULL==p) exit(1);   //Not enough memory
    *p=4;
    free(p);

    p= g(21);
}

void f () {
    int c=2;        //Stack
    extern int a;   //No definition, just declaration
    ++a;
    static int d=7; //Static
    ++d;
}

int *g(int i){      //i vive en call Stack de g
    int *p = malloc(sizeof *p); //Stack & Heap
    if(NULL ==p) exit(1);
    *p = i;
    return p;
}