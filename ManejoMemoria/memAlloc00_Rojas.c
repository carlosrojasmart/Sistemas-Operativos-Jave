/********************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 13/08/2024
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria
 * Tópico: Reserva de Memoria con la función malloc()
 * 
 * Descripción:
 * La función malloc() reserva un espacio de memoria de tamaño especificado en bytes
 * y devuelve un puntero a ese espacio reservado.
 ******************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Reserva de memoria para un bloque de 4 enteros
    int *bloque00 = malloc(4 * sizeof(int)); 
    // Reserva de memoria para un bloque de 15 enteros
    int *puntero = malloc(15 * sizeof(*puntero)); 

    // Verificación si la memoria fue reservada correctamente
    if (bloque00 == NULL || puntero == NULL) {
        printf("Error al reservar memoria.\n");
        free(bloque00); // Liberar la memoria ya reservada antes de salir
        free(puntero);  // Liberar la memoria ya reservada antes de salir
        return -1;
    }

    // Inicialización y visualización del primer bloque de memoria (bloque00)
    printf("Valores del bloque reservado 'bloque00':\n");
    for (int i = 0; i < 4; i++) {
        bloque00[i] = i * 2; // Asigna valores al bloque00
        printf("El valor de memoria reservada bloque00[%d] es: %d \n\n", i, bloque00[i]);
    }

    // Inicialización y visualización del segundo bloque de memoria (puntero)
    printf("Valores del bloque reservado 'puntero':\n");
    if (puntero != NULL) {
        *(puntero + 8) = 9889; // Establece el valor en la posición 9 del bloque 'puntero'
        printf("El valor de la 9a posición de puntero es: %d \n\n", *(puntero + 8));
        printf("El valor de la 9a posición de puntero es: %d \n\n", puntero[8]);
    }
  
    // Liberación de la memoria reservada
    free(bloque00);
    free(puntero);

    return 0;
}
