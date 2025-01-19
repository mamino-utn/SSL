#ifndef FIGURA_H_
#define FIGURA_H_



typedef struct{
    char border[10];
    char fill[10];
    char texto[1024];
}atributos_figura;


typedef struct {
    int x;
    int y;
    int diametro;
    atributos_figura atributos_figura;
}circ;

typedef struct {
    int x;
    int y;
    int lado;
    atributos_figura atributos_figura;
}cuad;

typedef struct {
    int x;
    int y;
    int base;
    int altura;
    atributos_figura atributos_figura;
}rect;

typedef struct {
    int x;
    int y;
    int base;
    int altura;
    atributos_figura atributos_figura;
}tri;

typedef union 
{
    circ circulo;
    cuad cuadrado;
    tri triangulo;
    rect rectangulo;
}figura_a_dibujar;
typedef enum {
    CUADRADO,
    RECTANGULO,
    TRIANGULO,
    CIRCULO
}tipos_de_figura;

typedef struct{
    tipos_de_figura tipo;
    figura_a_dibujar datos;
}Figura;

#endif