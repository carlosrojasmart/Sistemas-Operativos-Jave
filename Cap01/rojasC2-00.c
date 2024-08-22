/*********************************************
 * Autor: Carlos Eduardo Rojas
 * Fecha: 30/07/2024
 * Materia: Sistemas Operativos
 * Tema: Argumentos de Entrada en C
 * 
 * Descripción:
 * Este programa demuestra el uso de argumentos de entrada (argumentos de línea de comandos) en C.
 * El programa espera recibir varios argumentos al ser ejecutado y los imprime en la consola.
 * 
 * Requerimientos:
 *   - Los siguientes argumentos deben incluir:edad, mes actual, nombre, apellido, comida favorita,
 *     universidad, hobby, y ciudad actual.
 *********************************************/

#include <stdio.h>

/**
 * Función para mostrar un mensaje de bienvenida.
 */
void bienvenida() {
    printf("\n\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

int main(int argc, char *argv[]) {
    // Llamar a la función de bienvenida
    bienvenida();
  
    // Mostrar el número total de argumentos ingresados
    printf("\nNúmero de argumentos ingresados: [%d]\n\n", argc);
  
    // Imprimir los argumentos proporcionados por el usuario
    printf("Edad: %s\n", argv[1]);          // Primer argumento: Edad
    printf("Mes Actual: %s\n", argv[2]);   // Segundo argumento: Mes Actual
    printf("Nombre: %s\n", argv[3]);       // Tercer argumento: Nombre
    printf("Apellido: %s\n", argv[4]);     // Cuarto argumento: Apellido
    printf("Comida Favorita: %s\n", argv[5]); // Quinto argumento: Comida Favorita
    printf("Universidad: %s\n", argv[6]);  // Sexto argumento: Universidad
    printf("Hobby: %s\n", argv[7]);        // Séptimo argumento: Hobby
    printf("Ciudad Actual: %s\n", argv[8]); // Octavo argumento: Ciudad Actual
  
    printf("\n");
    return 0;
}
