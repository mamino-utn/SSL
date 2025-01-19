#include "generadorDeCodigo.h"
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
// Atributos Standard
const char colorDef[] = "green";
const char borderDef[] = "blue";
const int ancho = 100, alto = 100;

void atributosStandard(char *border, char *color) {
    if (border == NULL || strcmp(border, "") == 0) {
        strcpy(border, borderDef);
    }
    if (color == NULL || strcmp(color, "") == 0) {
        strcpy(color, colorDef);
    }
}

// Gestion de codigo
char buffer[BUFFER_SIZE];
char temp[256];
char inicioSVG[256];

void emitirSvgParaRec(int x, int y, int base, int altura, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    snprintf(temp, sizeof(temp), "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" />\n", x, y, base, altura, color);
    strcat(buffer, temp);
    bufferSalida();
}

void emitirSvgParaCuad(int x, int y, int lado, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    snprintf(temp, sizeof(temp), "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" />\n", x, y, lado, lado, color);
    strcat(buffer, temp);
    bufferSalida();
}

void emitirSvgParaCirc(int x, int y, int diametro, char *border, char *color, char *texto) {
    int radio = diametro / 2;
    atributosStandard(border, color);
    snprintf(temp, sizeof(temp), "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", x + radio, y + radio, radio, color);
    strcat(buffer, temp);
    bufferSalida();
}

void emitirSvgParaTri(int x, int y, int alto, int ancho, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    snprintf(temp, sizeof(temp), "<polygon points=\"%d,%d %d,%d %d,%d\" fill=\"%s\" />\n", x, y + alto, x + ancho / 2, y, x + ancho, y + alto, color);
    strcat(buffer, temp);
    bufferSalida();
}

void bufferSalida() {
    char finalSVG[6];
    snprintf(finalSVG, sizeof(finalSVG), "</svg>");
    strcat(buffer, finalSVG);   
    printf("%s", buffer);
}

void limpiarBuffer() {
    memset(buffer, 0, sizeof(buffer));
    snprintf(inicioSVG, sizeof(inicioSVG), "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", ancho, alto);
    strcat(buffer, inicioSVG);
}

void emitirSVGParaFin(){
    limpiarBuffer();
}