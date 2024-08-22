/********************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 13/08/2024
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria
 * Tópico: Reserva de Memoria con la función calloc()
 * 
 * Descripción:
 * Este programa muestra cómo reservar memoria utilizando la función calloc().
 * Se reserva memoria para diferentes bloques y se inicializa un bloque con 
 * una secuencia de números. Al final, se libera la memoria reservada.
 ******************************/

#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declaración de punteros y reserva de memoria usando calloc
    int *p1 = calloc(4, sizeof(int));  // Reserva memoria para un bloque de 4 enteros e inicializa a cero
    int *puntero = calloc(4, sizeof(int));  // Reserva memoria para un bloque de 4 enteros e inicializa a cero
    int *p3 = calloc(5, sizeof(*p3));  // Reserva memoria para un bloque de 5 enteros e inicializa a cero

    // Verificación de si la memoria se ha reservado correctamente
    if (p1 == NULL || puntero == NULL || p3 == NULL) {
        printf("Error al reservar memoria.\n");
        return -1;
    }
  
    // Construcción y cálculo de la secuencia de los primeros 10 términos
    printf("\nConstrucción y cálculo de la secuencia de los primeros 10 términos \n\n");
    for (int i = 0; i < 10; i++) {
        *(puntero + i) = i;  // Llena la posición i del puntero con el valor i
        printf("El valor de la secuencia es: %d \n\n", *(puntero + i));
    }

    // Liberación de memoria
    free(puntero);
    free(p1);
    free(p3);  
    
    return 0;
}
