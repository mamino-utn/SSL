#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "manejadorDeErrores.h"


typedef enum{
    INICIAL,
    ESPACIO,
    KEYWORD, 
    NUMERO, 
    SIMBOLO, 
    CADENA, 
    ERROR, 
}State;

typedef enum {
    
    PRUEBA,
    NUMBER,
    STRING,
    SEMICOLON,
    ASSIGN,
    ATTRIBUTE_OR_SEMICOLON,
    COLOR,
    STRING_DELIMITER,
    NONE,
    FIGURA,
    KEYWORD_CUADRADO,
    KEYWORD_RECTANGULO,
    KEYWORD_TRIANGULO,
    KEYWORD_CIRCULO,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_GREEN,
    KEYWORD_FILL,
    KEYWORD_BORDER,
    KEYWORD_TEXT,
    END_OF_FILE

} tokenType;


union Data{
    char* string; //Cadena literal
    int number; //Constante
};

typedef struct {
    union Data value;
    tokenType type;
} Token;	

void getNextToken(); //Obtener siguiente token
void peekNextToken();
void consumeToken();
int match(tokenType tipo_buscado);
char* obtenerCadena();
int obtenerNumero();

#endif