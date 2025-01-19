#ifndef MANEJADOR_DE_ERRORES_INCLUDED
#define MANEJADOR_DE_ERRORES_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int lineaActual=1;
//int columnaActual=1;

void emitirErrorSemantico(const char* mensaje);

void emitirErrorSintactico(const char* mensaje);

void emitirErrorLexico(const char* mensaje);

#endif