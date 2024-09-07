//Importa
#include "histograma.h"
#include "Graficador.h"

#include <stdio.h>
#include "dataset.h"


void main()
{
    DataSet mi_dataset = {23 , {0}};
    
    histograma(&mi_dataset);  // Generar el histograma

    generarSVG(mi_dataset);   // Grafico SVG
}
