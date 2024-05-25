/* TablasdeConversion.c 
* Archivo que muestra por pantalla las tablas de conversion
* Editado por: Maria Musante, Camila Tobares , Martin Brustti , Gualtieri Agustin
* Ultima modificacion: 10/05/2024*/


#include <stdio.h>
#include "Conversion.h"

void printTablaCelsius(int LOWER,int UPPER,int STEP);
void printTablaFahrenheit(int LOWER, int UPPER, int STEP);
void printTablas(int LOWER,int UPPER,int STEP, double (*conversion)(double));
void printFila(int, double (*conversion)(double));
void printFilas(int LOWER,int UPPER, int STEP, double (*conversion)(double));

int main(void){
    const int LOWER = 0; // lower limit of table
    const int UPPER = 300; // upper limit
    const int STEP = 20; // step size

    //Version original--------
    //for(int cels = LOWER; cels <= UPPER; cels = cels + STEP)
    //    printf("%6.1f %3d\n", Fahrenheit(cels), cels );
    //for(int cels = LOWER; cels <= UPPER; cels = cels + STEP)
    //    printf("%6.1f %3d\n", Fahrenheit(cels), cels );

    //Version credito extra--------
    printTablaCelsius(LOWER, UPPER, STEP);
    printTablaFahrenheit(LOWER, UPPER, STEP);    
}

// Version credito extra 1

/*void printTablaCelsius(int LOWER,int UPPER,int STEP)
{
    printf("Tabla de Celcius a Fahrenheit \n");
    printTablas(LOWER, UPPER, STEP, Fahrenheit);
}

void printTablaFahrenheit(int LOWER, int UPPER, int STEP)
{
    printf("Tabla de Fahrenheit a Celcius \n");
    printTablas(LOWER, UPPER, STEP, Celsius);
}

void printTablas(int LOWER,int UPPER,int STEP, double (*conversion)(double))
{
    for(int x = LOWER; x <= UPPER; x = x + STEP)
        printf("%3d %6.1f\n", x, conversion(x));
} */

//Version credito extra 2

void printTablaCelsius(int LOWER,int UPPER,int STEP)
{
    printf("\nTabla de Celsius a Fahrenheit \n");
    printFilas(LOWER, UPPER, STEP, Fahrenheit);
}

void printTablaFahrenheit(int LOWER, int UPPER, int STEP)
{
    printf("\nTabla de Fahrenheit a Celsius \n");
    printFilas(LOWER, UPPER, STEP, Celsius);
}

void printFila(int valorOriginal, double (*conversion)(double))
{
    printf("%3d %6.1f\n", valorOriginal, conversion(valorOriginal));
}
void printFilas(int LOWER,int UPPER, int STEP, double (*conversion)(double))
{
    for(int x = LOWER; x <= UPPER; x += STEP)
    printFila(x,conversion);
}
