//Importa
#include <stdio.h>

//Exporta
#include "histograma.h"


void histograma(DataSet* mi_dataset) {
    int c;
    int longitud_palabra = 0;

    goto OUT;

    OUT:
        c = getchar();
        if (c != EOF) {
            if (c != ' ' && c != '\n' && c != '\t') {
                longitud_palabra++;
                goto IN;
            } else {
                if (longitud_palabra > 0 && longitud_palabra < mi_dataset->cant_max_caracteres) {
                    mi_dataset->valores[longitud_palabra-1]++;
                }
                longitud_palabra = 0;
                goto OUT;
            }
        } else {
            goto END;
        }

    IN:
        c = getchar();
        if (c != EOF) {
            if (c == ' ' || c == '\n' || c == '\t') {
                if (longitud_palabra > 0 && longitud_palabra < mi_dataset->cant_max_caracteres) {
                    mi_dataset->valores[longitud_palabra-1]++;
                }
                longitud_palabra = 0;
                goto OUT;
            } else {
                longitud_palabra++;
                goto IN;
            }
        } else {
            goto END;
        }

    END:
        if (longitud_palabra > 0 && longitud_palabra < mi_dataset->cant_max_caracteres) 
        {
            mi_dataset->valores[longitud_palabra-1]++;
        }
        return;
}
