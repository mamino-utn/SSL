#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"
#include "dataset.h"

int main(int argc,char* argv[]) {

    printf("Corriendo tests para implementacion %s\n", argv[1]);

    DataSet dataset = {23, {0}};
    

    // Crear archivo de prueba
    FILE *file = fopen("test_input.txt", "w");
    
    fprintf(file, "esta es la prueba numero uno\n");
    fclose(file);

    // Redirigir entrada estándar
    if (freopen("test_input.txt", "r", stdin) == NULL) {
        perror("Error al redirigir stdin");
        return 1;
    }
    // Contar palabras
    histograma(&dataset);

    // Pruebas con assert
    assert(dataset.valores[1] == 2); // "es" y "la"
    assert(dataset.valores[2] == 1); // "uno"
    assert(dataset.valores[3] == 1); // "esta"
    assert(dataset.valores[5] == 2); // "prueba" y "numero"

    // Restaurar entrada estándar
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        perror("Error al restaurar stdin");
        return 1;
    }

    // Vaciar el array
    for (int i = 0; i < dataset.cant_max_caracteres; i++) {
        dataset.valores[i] = 0;
    }

    // Prueba de entrada vacía
    file = fopen("test_input.txt", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo de prueba");
        return 1;
    }
    fclose(file); // Archivo vacío

    if (freopen("test_input.txt", "r", stdin) == NULL) {
        perror("Error al redirigir stdin");
        return 1;
    }
    histograma(&dataset);

    for (int i = 0; i < dataset.cant_max_caracteres; i++) {
        assert(dataset.valores[i] == 0); // No debería haber palabras
    }

    // Restaurar entrada estándar
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        perror("Error al restaurar stdin");
        return 1;
    }

    //restauro el array

    for (int i = 0; i < dataset.cant_max_caracteres; i++) {
        dataset.valores[i] = 0;
    }

    // Prueba de entrada con una sola palabra
    file = fopen("test_input.txt", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo de prueba");
        return 1;
    }
    fprintf(file, "rinoceronte");
    fclose(file);

    if (freopen("test_input.txt", "r", stdin) == NULL) {
        perror("Error al redirigir stdin");
        return 1;
    }

    histograma(&dataset);


    for (int i = 0; i < dataset.cant_max_caracteres; i++) {
        if (i != 10) {
            assert(dataset.valores[i] == 0);
        } else {
            assert(dataset.valores[10] == 1); // "rinoceronte" con 11 letras
        }
    }

    // Restaurar entrada estándar
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        perror("Error al restaurar stdin");
        return 1;
    }

    printf("Todas las pruebas para la implementacion %s se pasaron con exito\n", argv[1]);

    remove("test_input.txt");
    
    return 0;
}