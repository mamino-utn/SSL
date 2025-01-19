#ifndef TOKEN_H_
#define TOKEN_H_


typedef enum {
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
    NUMBER,
    STRING,
    SEMICOLON,
    ASSIGN,
    ATTRIBUTE_OR_SEMICOLON,
    COLOR,
    STRING_DELIMITER,
    NONE,
    FIGURA

} tokenType;

union Data{
    char* keyword; //Figura, Color, Atributo, Cadena literal, Simbolo, EOF
    int number; //Constante
};

typedef struct {
    union Data value;
    tokenType type;
} Token;	

#endif