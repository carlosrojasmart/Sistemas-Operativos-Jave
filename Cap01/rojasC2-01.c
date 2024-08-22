/********************************
 * Autor: Carlos Eduardo Rojas
 * Fecha: 30/07/2024
 * Materia: Sistemas Operativos
 * Tema: Argumentos de Entrada en C
 * 
 * Descripción:
 * Este programa demuestra el uso de punteros y la aritmética de punteros en C.
 * Se muestra cómo trabajar con direcciones de memoria y la diferencia entre punteros.
 * 
 * Requerimientos:
 *   - El programa utiliza punteros para manejar valores y arrays.
 *   - Se imprimen tanto los valores como las direcciones de memoria asociadas.
 ******************************/

#include <stdio.h>

/**
 * Función que da la bienvenida al usuario.
 */
void bienvenida() {
    printf("\n\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

int main(int argc, char *argv[]) {
    // Llamar a la función de bienvenida
    bienvenida();
  
    // Definir una variable entera y un puntero a esa variable
    int x = 102;
    int *p = &x; // El puntero debe ser inicializado con la dirección de memoria de 'x'
  
    // Imprimir el valor de 'x' y la dirección de memoria de 'x'
    printf("\nEl valor de X es: %d \n", x);
    printf("La dirección de X es: %p \n\n", (void *)p);
  
    // Definir un array y punteros para el array
    int vector[] = {5, 10, 20, 30, 40, 50, 80};
    int *p1 = vector;       // Puntero al primer elemento del array
    int *p2 = vector + 2;   // Puntero al tercer elemento del array
    int diferencia = p2 - p1; // Diferencia en elementos entre p2 y p1
  
    // Imprimir las direcciones de memoria y la diferencia entre punteros
    printf("El valor de p1 es: %p \n", (void *)p1);
    printf("El valor de p2 es: %p \n", (void *)p2);
    printf("La diferencia entre p2 y p1 es: %d \n", diferencia);
  
    printf("\n");
    return 0;
}
