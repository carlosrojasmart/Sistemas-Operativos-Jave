/********************************
 * Autor: Carlos Eduardo Rojas
 * Fecha: 30/07/2024
 * Materia: Sistemas Operativos
 * Tema: Uso de Variables en C
 * 
 * Descripción:
 * Este programa demuestra el uso de diferentes tipos de variables en C.
 * Se definen variables de distintos tipos y se imprime su valor utilizando
 * el formato adecuado para cada tipo.
 * 
 * Requerimientos:
 *   - El programa muestra variables de tipo char, short, int, long int, bool,
 *     float, double y long double.
 ******************************/

#include <stdio.h>
#include <stdbool.h>

/**
 * Función que da la bienvenida al usuario.
 */
void bienvenida() {
    printf("\n\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

int main(int argc, char *argv[]) {
    // Llamar a la función de bienvenida
    bienvenida();
  
    // Definir variables de diferentes tipos
    char D1 = 'a';                   // Variable de tipo char
    short D2 = 12;                   // Variable de tipo short
    int D3 = 12356;                 // Variable de tipo int
    long int D4 = 12346363636;      // Variable de tipo long int
    bool D5 = 1;                    // Variable de tipo bool (1 para true)
    float D6 = 32.6;                // Variable de tipo float
    double D7 = 463.32;             // Variable de tipo double
    long double D8 = 463636.3253252523; // Variable de tipo long double
  
    // Imprimir los valores de las variables
    printf("\nUn dato char es: %c\n\n", D1);              // %c para char
    printf("Un dato short es: %d\n\n", D2);             // %d para short
    printf("Un dato int es: %d\n\n", D3);               // %d para int
    printf("Un dato long es: %ld\n\n", D4);             // %ld para long int
    printf("Un dato bool es: %d\n\n", D5);              // %d para bool (1 para true, 0 para false)
    printf("Un dato float es: %f\n\n", D6);             // %f para float
    printf("Un dato double es: %f\n\n", D7);            // %f para double
    printf("Un dato long double es: %Lf\n\n", D8);      // %Lf para long double
  
    printf("\n");
    return 0;
}
