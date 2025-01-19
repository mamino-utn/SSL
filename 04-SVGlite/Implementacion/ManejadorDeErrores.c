#include "manejadorDeErrores.h"

/*
typedef enum
{
    ERROR_LEXICO,
    ERROR_SINTACTICO,
    ERROR_SEMANTICO
} TipoError;
*/

typedef struct 
{
    //TipoError tipoError;
    const char* tipoError;
    //int linea;  // Posible implementacion futura para identificar el error en una linea
    //int columna;
    char mensaje[256];
}Error;

void emitirError(const char* type, const char* mensaje){
    // Creo el error 
    Error error;
    error.tipoError = type; // Le defino el tipo de error 
    //error.linea=lineaActual; //numero de linea
    //error.columna=columnaActual;
    snprintf(error.mensaje,sizeof(error.mensaje),"%s",mensaje); //guarda en el array el mensaje recibido como parametro


    //const char* typeError = (type==ERROR_LEXICO ? "lexico" : "sintactico") ? : "semantico";

    //printf("Error %s en la linea %s, %s",typeError,error.linea,error.mensaje);
    printf("\nError %s , %s",error.tipoError,error.mensaje); // Imprimo en consola el tipo de error y el mensaje

    exit(1);
}

void emitirErrorSemantico(const char* mensaje){
    //emitirError(ERROR_SEMANTICO,mensaje);
    emitirError("semantico",mensaje);
}

void emitirErrorSintactico(const char* mensaje){
    //emitirError(ERROR_SINTACTICO,mensaje);
    emitirError("sintactico",mensaje);
}

void emitirErrorLexico(const char* mensaje){
    //emitirError(ERROR_LEXICO,mensaje);
    emitirError("lexico",mensaje);
}