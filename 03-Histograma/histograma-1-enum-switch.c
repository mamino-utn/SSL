// Exporta
#include "histograma.h"

// Importa
#include <stdio.h>

typedef enum{
    IN, // Dentro de la palabra
    OUT, // Fuera de la palabra
    END // Fin
} State;

void histograma(DataSet* mi_dataset){
    
    // Inicialización de las variables:
    State estado = OUT; // Comenzamos con el estado fuera de la palabra
    int caracter = 0; // Variable para contar caracteres
    char c; // Variable para leer caracteres del texto
    int control = 1; // Variable para frenar el while

    // Algoritmo:
    while(control == 1){
        c = getchar();
        switch(estado){ // Verificamos nuestro estado
        // Fuera de la palabra
            case OUT:
                switch(c){
                    case '\n':
                    case '\t':
                    case ' ':
                        // Nada
                    break;
                    case EOF:
                        estado = END;
                    break;
                    default:
                        ++caracter; // Sumo el primer caracter encontrado
                        estado = IN; // Cambio de estado
                }
                break;
        // Dentro de la palabra
            case IN:
                switch(c){
                    case '\n':
                    case '\t':
                    case ' ': 
                        if(caracter <= mi_dataset->cant_max_caracteres){
                            mi_dataset->valores[caracter - 1]++; // Palabra con largo igual o menor a cant_max_caracteres
                        } 
                        //else {
                         //   mi_dataset->valores[mi_dataset->cant_max_caracteres - 1]++; // Palabra de más de cant_max_caracteres
                        //}
        
                        caracter = 0; // Reseteamos contador de caracteres
                        estado = OUT; // Cambio de estado
                    break;
                    case EOF:
                        estado = END;
                    break;
                    default:
                        ++caracter; // Cuento caracteres
                }
            break;
        // Caso EOF
            case END:
                if(caracter > 0){
                    if(caracter <= mi_dataset->cant_max_caracteres){
                        mi_dataset->valores[caracter - 1]++;
                    } 
                    //else {
                    //    mi_dataset->valores[mi_dataset->cant_max_caracteres - 1]++;
                    //}
                }
                control = 0;
            break;
        }
    }
}
