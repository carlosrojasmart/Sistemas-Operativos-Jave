/*********************************************
 * Autor: Carlos Eduardo Rojas
 * Fecha: 23/07/2024
 * Materia: Sistemas Operativos
 * Tema: Programación en C: Primera Parte
 * 
 * Descripción:
 * Este programa en C incluye funciones básicas para:
 *   - Sumar dos enteros
 *   - Calcular el área de una circunferencia
 *   - Mostrar un mensaje de bienvenida
 * 
 * Requerimientos:
 *   - Función para sumar dos enteros
 *   - Función para calcular el área de una circunferencia
 *   - Función para dar la bienvenida
 *********************************************/

#include <stdio.h>

/**
 * Función para mostrar un mensaje de bienvenida.
 */
void bienvenida() {
    printf("Hola Mundo...\n");
    printf("\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

/**
 * Función para sumar dos enteros ingresados por el usuario.
 */
void suma2Enteros() {
    int n1 = 0;
    int n2 = 0;
    printf("\nIngrese su primer entero: ");
    scanf("%d", &n1);
    printf("\nIngrese su segundo entero: ");
    scanf("%d", &n2);
    int suma = n1 + n2;
    printf("\nEl resultado de la suma es: %d\n", suma);
}

/**
 * Función para calcular el área de una circunferencia dada su radio.
 */
void AreaCircunferencia() {
    int radio = 0;
    float pi = 3.14;
    printf("\nIngrese el radio: ");
    scanf("%d", &radio);
    float area = radio * radio * pi;
    printf("El área de la circunferencia es: %f\n", area);
}

int main(int argc, char *argv[]) {
    // Llamar a la función de bienvenida
    bienvenida();
   
    // Llamar a la función que suma dos enteros
    suma2Enteros();
    
    // Llamar a la función que calcula el área de una circunferencia
    AreaCircunferencia();
    
    return 0;
}