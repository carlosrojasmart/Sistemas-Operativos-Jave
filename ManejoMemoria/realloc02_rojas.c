/********************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 13/08/2024
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria
 * Tópico: Uso de la función realloc()
 * 
 * Descripción:
 * Este programa demuestra cómo usar la función realloc() para ajustar el tamaño
 * de un bloque de memoria previamente reservado con malloc().
 * 
 * La función realloc() redimensiona un bloque de memoria reservado y puede
 * cambiar su ubicación en memoria si es necesario.
 ******************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Reserva inicial de memoria para un bloque de 5 enteros
    int *bloque = malloc(5 * sizeof(int));
    if (bloque == NULL) {
        printf("Error al reservar memoria.\n");
        return -1;
    }
  
    // Inicializa el bloque con valores
    for (int i = 0; i < 5; i++) {
        bloque[i] = i * 10;
        printf("Valor inicial de bloque[%d]: %d\n", i, bloque[i]);
    }
  
    // Redimensiona el bloque para que pueda contener 10 enteros
    int *bloqueRedimensionado = realloc(bloque, 10 * sizeof(int));
    if (bloqueRedimensionado == NULL) {
        printf("Error al redimensionar memoria.\n");
        free(bloque); // Libera el bloque original si realloc falla
        return -1;
    }
  
    // Inicializa el nuevo espacio en el bloque redimensionado
    for (int i = 5; i < 10; i++) {
        bloqueRedimensionado[i] = i * 20;
        printf("Valor redimensionado de bloque[%d]: %d\n", i, bloqueRedimensionado[i]);
    }
  
    // Imprime todos los valores del bloque redimensionado
    printf("\nValores finales del bloque redimensionado:\n");
    for (int i = 0; i < 10; i++) {
        printf("bloqueRedimensionado[%d]: %d\n", i, bloqueRedimensionado[i]);
    }
  
    // Liberación de memoria
    free(bloqueRedimensionado);
  
    return 0;
}
