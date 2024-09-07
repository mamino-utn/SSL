#include <stdio.h>
#include "Graficador.h"


/*
void graficador(dataset mi_dataset){

    for(int i = 0; i < mi_dataset.cant_max_caracteres; i++){
        if(i < mi_dataset.cant_max_caracteres - 1)
            printf("Longitud (%d):", i+1);
        else
            printf("Longitud (%d o mas):", mi_dataset.cant_max_caracteres);
        for(int j = 0; j <= mi_dataset.valores[i]; j++){
            if(j>0)
                printf("|");
        }
        printf("\n");
    }

}*/


void generarSVG(DataSet mi_dataset ) {
    FILE *file = fopen("histograma.svg", "w");
    
    if (file == NULL) {
        fprintf(stderr, "Error abriendo el histograma.svg");
        return;
    }

    int width = 1000;
    int height = 600;
    int bar_width = width / mi_dataset.cant_max_caracteres;
    int max_height = 0;

    // Busco la altura maxima
    for (int i = 0; i < mi_dataset.cant_max_caracteres; ++i) {
        if (mi_dataset.valores[i] > max_height) {
            max_height = mi_dataset.valores[i];
        }
    }

    max_height++;


    fprintf(file, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", width, height);
    fprintf(file, "<rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>\n");

    // Dibujo las lineas
    for (int i = 0; i < mi_dataset.cant_max_caracteres; ++i) {
        double bar_height = ((double)mi_dataset.valores[i] / max_height) * (height - 50);
        fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"blue\"/>\n",
                i * bar_width, height - (int)bar_height - 50, bar_width - 10, (int)bar_height);

        fprintf(file, "<text x=\"%d\" y=\"%d\" font-family=\"Verdana\" font-size=\"10\" fill=\"black\">%d (%d)</text>\n",
                i * bar_width + bar_width / 4, height - 15, i + 1, mi_dataset.valores[i]);
    }

    fprintf(file, "</svg>\n");

    fclose(file);
}





