/********************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 06/08/2024
 * Materia: Sistemas Operativos
 * Tema: Evaluación del Rendimiento de Sistemas de Cómputo
 * 
 * Descripción:
 * Este programa realiza la multiplicación de matrices y muestra los resultados.
 * Utiliza un área de memoria reservada para las matrices y proporciona funciones 
 * para inicializar, multiplicar e imprimir matrices.
 * 
 * Requerimientos:
 *   - El tamaño de la matriz (N) y el número de hilos (h) deben ser proporcionados 
 *     como argumentos al ejecutar el programa.
 ******************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DATA_RESERVA (1024*1024*64*3) // Tamaño de la reserva de memoria en bytes

// Área de memoria reservada para las matrices
static double MEM_CHUNK[DATA_RESERVA];

/********************
 * Función para multiplicar matrices.
 * Realiza la multiplicación de dos matrices (a y b) y almacena el resultado en c.
 */
void Mult_Matriz(int SZ, double *a, double *b, double *c) {
    int i, j, k;
    for (i = 0; i < SZ; i++) {
        for (j = 0; j < SZ; j++) {
            double *pA, *pB, SumaTemp;
            SumaTemp = 0.0;
            pA = a + (i * SZ); 
            pB = b + j;
            for (k = SZ; k > 0; k--, pA++, pB += SZ) {
                SumaTemp += (*pA * *pB);
            }
            c[i * SZ + j] = SumaTemp;
        }
    }
}

/********************
 * Función para inicializar las matrices.
 * Asigna valores a las matrices a, b y c.
 */
void Init_Matriz(int SZ, double *a, double *b, double *c) {
    int i, j, k;
    for (k = 0; k < SZ; k++) {
        for (j = 0; j < SZ; j++) {
            a[j + k * SZ] = 2.3 * (j + k);
            b[j + k * SZ] = 3.2 * (j - k);
            c[j + k * SZ] = 1.3; 
        }
    }
}

/********************
 * Función para imprimir una matriz.
 * Muestra los valores de la matriz en la consola.
 */
void Print_Matriz(int SZ, double *a) {
    int j, k;
    for (k = 0; k < SZ; k++) {
        for (j = 0; j < SZ; j++) {
            printf(" %f", a[j + k * SZ]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

int main(int argc, char *argv[]) {
    // Verificar si se proporcionaron suficientes argumentos
    if (argc < 3) {
        printf("Uso: %s MatrizSize NumHilos\n\n", argv[0]);
        return -1;
    }  

    // Leer los argumentos de entrada
    int N = (int) atof(argv[1]); // Tamaño de la matriz (NxN)
    int h = (int) atof(argv[2]); // Número de hilos (no utilizado en el programa)
    
    // Punteros para las matrices
    double *A, *B, *C;
    /* Reserva de memoria inicial para las matrices */
    A = MEM_CHUNK;
    B = A + N * N;
    C = B + N * N;
    
    // Imprimir los valores ingresados
    printf("Valores Ingresados: \n");
    printf("Tamaño de la Matriz (NxN): %dx%d \n", N, N);
    printf("Número de hilos (h): %d\n", h);
    
    // Inicializar matrices y realizar multiplicación
    Init_Matriz(N, A, B, C);
    Print_Matriz(N, A); // Imprimir matriz A
    Print_Matriz(N, B); // Imprimir matriz B
    Mult_Matriz(N, A, B, C); // Multiplicar matrices A y B, guardar en C
    Print_Matriz(N, C); // Imprimir matriz C (resultado)
    
    return 0;
}
