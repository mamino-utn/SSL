#include "generadorDeCodigo.h"
#include <string.h>
#include <stdio.h>

// const int buffer_size = 10000;
// Atributos Standard
const char colorDef[] = "green";
const char borderDef[] = "blue";
const int ancho = 100, alto = 100;

void atributosStandard(char *border, char *color) {
    //printf("Color de entrada %s",color);

    if (strcmp(border, "") == 0) {
        strcpy(border, borderDef);
        //printf("este es el valor default para border %s %s\n", border , borderDef);
    }
    if (strcmp(color, "") == 0) {
        strcpy(color, colorDef);
        //printf("este es el valor default para color %s %s\n", color , colorDef);
    }
}

// Gestion de codigo
char buffer[10000];
char temp[256];
char inicioSVG[256];

// Función para emitir texto en el SVG con tamaño de fuente ajustado
void emitirTexto(int x, int y, char *texto, int fontSize) {
    if (strcmp(texto, "") != 0) {
        snprintf(temp, sizeof(temp), "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=\"%d\" fill=\"%s\" text-anchor=\"middle\" alignment-baseline=\"middle\">%s</text>\n", x, y, fontSize, "black", texto);
        strcat(buffer, temp);
    }
}

// Función para rectángulo
void emitirSvgParaRec(int x, int y, int base, int altura, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    int fontSize = (base < altura ? base : altura) / 5; // Ajuste de tamaño de fuente
    snprintf(temp, sizeof(temp), "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" />\n", x, y, base, altura, color, border);
    strcat(buffer, temp);
    emitirTexto(x + base / 2, y + altura / 2, texto, fontSize);
}

// Función para cuadrado
void emitirSvgParaCuad(int x, int y, int lado, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    int fontSize = lado / 5; // Ajuste de tamaño de fuente
    snprintf(temp, sizeof(temp), "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" />\n", x, y, lado, lado, color, border);
    strcat(buffer, temp);
    emitirTexto(x + lado / 2, y + lado / 2, texto, fontSize);
}

// Función para círculo
void emitirSvgParaCirc(int x, int y, int diametro, char *border, char *color, char *texto) {
    int radio = diametro / 2;
    atributosStandard(border, color);
    int fontSize = diametro / 5; // Ajuste de tamaño de fuente
    snprintf(temp, sizeof(temp), "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\" />\n", x + radio, y + radio, radio, color, border);
    strcat(buffer, temp);
    emitirTexto(x + radio, y + radio, texto, fontSize);
}

// Función para triángulo
void emitirSvgParaTri(int x, int y, int alto, int ancho, char *border, char *color, char *texto) {
    atributosStandard(border, color);
    int fontSize = (ancho < alto ? ancho : alto) / 5; // Ajuste de tamaño de fuente
    snprintf(temp, sizeof(temp), "<polygon points=\"%d,%d %d,%d %d,%d\" fill=\"%s\" stroke=\"%s\" />\n", x, y + alto, x + ancho / 2, y, x + ancho, y + alto, color, border);
    strcat(buffer, temp);
    emitirTexto(x + ancho / 2, y + alto / 2, texto, fontSize);
}

// Función para finalizar SVG
void bufferSalida() {
    strcat(buffer, "</svg>");
    printf("%s", buffer);
}

void limpiarBuffer() {
    memset(buffer, 0, sizeof(buffer));
    snprintf(inicioSVG, sizeof(inicioSVG), "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", ancho, alto);
    strcat(buffer, inicioSVG);
}

void emitirSVGParaInicio() {
    limpiarBuffer();
}

void emitirSVGParaFin() {
    bufferSalida();
}