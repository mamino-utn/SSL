#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "figura.h"
#include "scanner.h"
#include "verificadorSemantico.h"
#include "manejadorDeErrores.h"
#include "generadorDeCodigo.h"






void parsear(FILE *in, FILE *out);
void unidadDeTraduccion();
void parsear_figura();
void cuadrado();
void rectangulo();
void triangulo();
void circulo();
void puntoycoma();
void emitir_codigo_figura();
void reestablecer_atributos();
int coordenada();
atributos_figura atributos();
int dimension();
void color();
void text();










#endif