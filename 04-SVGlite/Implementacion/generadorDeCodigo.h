#ifndef GENERADORDECODIGO_H
#define GENERADORDECODIGO_H

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Atributos estándar predeterminados
/*
const char colorDef[];
const char borderDef[];
const int ancho;
const int alto;
*/

// Declaraciones de funciones
void atributosStandard(char *border, char *color);

void emitirSvgParaRec(int x, int y, int base, int altura, char *border, char *color, char *texto);

void emitirSvgParaCuad(int x, int y, int lado, char *border, char *color, char *texto);

void emitirSvgParaCirc(int x, int y, int diametro, char *border, char *color, char *texto);

void emitirSvgParaTri(int x, int y, int alto, int ancho, char *border, char *color, char *texto);

void emitirTexto(int x, int y, char *texto, int fontSize);

void bufferSalida();

void limpiarBuffer();

void emitirSVGParaFin();

void emitirSVGParaInicio();

#endif 