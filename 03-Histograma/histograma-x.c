//Importa
#include <stdio.h>

//Exporta
#include "histograma.h"



//vamos a implementar una tabla 
//     |BLANCO | NO_BLANCO |EOF
// OUT |OUT    | IN        |END
// IN  |OUT    | IN        |END
// END |END    | END       |END

#define CANT_ESTADOS 3
#define CANT_ENTRADAS 3

// Definición de los estados
typedef enum {
    OUT, 
    IN, 
    END,
} Estado;

// Definición de los tipos de entrada
typedef enum {
    BLANCO,        // Caracteres blancos: espacio, nueva línea, tabulación
    NO_BLANCO,
    ENTRADA_EOF,     // Caracteres no blancos
} Entrada;

// Función para determinar el tipo de entrada basado en el carácter leído
Entrada obtenerTipoEntrada(char c) {

    if (c == ' ' || c == '\n' || c == '\t') {
        return BLANCO;
    } else {
        return NO_BLANCO;
    }
}

// Definición de la tabla de transiciones
Estado tablaTransiciones[CANT_ESTADOS][CANT_ENTRADAS] = {
    //      B    NB   EOF
    /*OUT*/{OUT, IN, END}, 
    /*IN*/ {OUT, IN, END},
    /*END*/{END, END, END}  
};

// Función para procesar la entrada y generar el histograma
void histograma(DataSet* mi_dataset) 
{   
    Estado estadoActual = OUT;   // Estado inicial
    int longitud_palabra = 0;
    char c;

    while ((c = getchar()) != EOF) {

        Entrada entrada = obtenerTipoEntrada(c);   // Determinar el tipo de entrada
        estadoActual = tablaTransiciones[estadoActual][entrada];  // Obtener el siguiente estado desde la tabla

        // Manejo de estados
        switch (estadoActual) {
            case OUT:
                if (longitud_palabra > 0) {
                    mi_dataset->valores[longitud_palabra-1]++;
                    longitud_palabra = 0;
                }
                break;
            case IN:
                //Si se llego al maximo de caracteres dejo de sumar a la longitud
                if (longitud_palabra <= mi_dataset->cant_max_caracteres) {
                    longitud_palabra++;
                }
                break;
        }
    } 
    estadoActual = tablaTransiciones[estadoActual][c]; //La entrada es EOF, actualizo el estado

    // Guardo la ultima palabra que se estaba contando
    if (longitud_palabra > 0) {
        mi_dataset->valores[longitud_palabra-1]++;
    }
}

