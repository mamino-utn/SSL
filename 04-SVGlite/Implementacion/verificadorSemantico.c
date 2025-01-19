#include "verificadorSemantico.h"

const int coordenada_x_max = 100;
const int coordenada_y_max = 100;
const int atributos_max = 3;

void checkInsideCanvas(int x, int y){  
    if(coordenada_x_max < x || coordenada_y_max < y){
        emitirErrorSemantico("Las coordenadas especificadas para la figura estan por fuera del lienzo");
    }
}

void checkAttributes(int* atributos_usados, int contador_atributos){
     for (int i = 0; i < contador_atributos + 1; i++) {
        for (int j = i + 1; j < contador_atributos + 1; j++) {
            if (atributos_usados[i] == atributos_usados[j]) {
                emitirErrorSemantico("El atributo esta repetido\n");
            }
        }
    }
}

void cantidadDeAtributosValida(int contador_atributos){
    if (contador_atributos > atributos_max ){
        emitirErrorSemantico("Limite de atributos alcanzado\n");
    }
}