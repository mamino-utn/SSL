#include <stdio.h>
#include "histograma.h"

int nc = 0;  // Variable global, numero de caracteres

void state_out(int c, DataSet* mi_DataSet);
void state_in(int c, DataSet* mi_DataSet);
void state_end(DataSet* mi_DataSet);

void state_out(int c, DataSet* mi_DataSet) {
    if (c != EOF) {
        nc = 0;
        if (c == ' ' || c == '\n' || c == '\t') {
            state_out(getchar(), mi_DataSet); // Llamadas recursivas
        } else {
            nc++;
            state_in(getchar(), mi_DataSet);
        }
    } else {
        state_end(mi_DataSet);
    }
}

void state_in(int c, DataSet* mi_DataSet) {
    if (c != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nc <= mi_DataSet->cant_max_caracteres) {
                mi_DataSet->valores[nc - 1]++;
            } 
            //else {
            //    mi_DataSet->valores[mi_DataSet->cant_max_caracteres - 1]++;
            //}
            nc = 0; // Reset count when transitioning to OUT
            state_out(getchar(), mi_DataSet);
        } else {
            ++nc;
            state_in(getchar(), mi_DataSet); // Llamadas recursivas
        }
    } else {
        state_end(mi_DataSet);
    }
}

void state_end(DataSet* mi_DataSet) {
    if (nc > 0) {
        if (nc <= mi_DataSet->cant_max_caracteres) {
            mi_DataSet->valores[nc - 1]++;
        } 
        //else {
        //    mi_DataSet->valores[mi_DataSet->cant_max_caracteres - 1]++;
        //}
    }
}

void histograma(DataSet* mi_DataSet) {
    for (int i = 0; i < mi_DataSet->cant_max_caracteres; i++) {
        mi_DataSet->valores[i] = 0;
    }
    state_out(getchar(), mi_DataSet);
}
