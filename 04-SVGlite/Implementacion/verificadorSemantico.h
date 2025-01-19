#ifndef VERIFICADOR_SEMANTICO_H_INCLUDED
#define VERIFICADOR_SEMANTICO_H_INCLUDED

#include "manejadorDeErrores.h"

void checkInsideCanvas(int x, int y);

void checkAttributes(int* atributos_usados,int contador_atributos);

void cantidadDeAtributosValida(int contador_atributos);

#endif