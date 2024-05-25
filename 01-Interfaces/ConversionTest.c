/* ConversionTest.c 
* Archivo que muestra por pantalla las tablas de conversion
* Editado por: Maria Ladrero, Matias Miño
* Ultima modificacion: 10/05/2024*/


#include <assert.h>
#include <stdbool.h>
#include "Conversion.h"

bool areNear(double ,double, double);

int main() {
    // Prueba 1: -10 Fahrenheit deberían ser -23.33 Celsius
    assert(areNear(Celsius(-10),-23.33,0.01));

    // Prueba 2: 0 Fahrenheit deberían ser -17.77 Celsius
    assert(areNear(Celsius(0),-17.77,0.01));

    // Prueba 3: 32 Fahrenheit deberían ser 0 Celsius
    assert(areNear(Celsius(32),0,0.01));

    // Prueba 4: 100 Fahrenheit deberían ser 37.77 Celsius
    assert(areNear(Celsius(100),37.77,0.01));

    //Prueba 5: 0 Celsius deberian ser  32 Fahrenheit
    assert(areNear(Fahrenheit(0),32,0.01));

   //Prueba 6: 100 Celsius deberian ser  212 Fahrenheit
    assert(areNear(Fahrenheit(100),212,0.01));

   //Prueba 7: -10 Celsius deberian ser  14 Fahrenheit
    assert(areNear(Fahrenheit(-10),14,0.01));


    return 0;
}

bool areNear(double x,double y, double e){
    double diff = x - y;
    if (diff < 0)
        diff = -diff;

    return diff <= e;
}