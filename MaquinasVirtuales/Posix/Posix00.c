/******************************************************
 * Pontificia Universidad Javeriana                    *
 * Facultad de Ingeniería                              *
 * Departamento de Ingeniería de Sistemas              *
 * Autor: Carlos Eduardo Rojas                         *
 * Fecha de Creación: 29/10/2024                       *
 * Materia: Sistemas Operativos                        *
 * Proyecto: Introducción a Pthreads                   *
 * Descripción: Este programa utiliza Pthreads para    *
 *              ejecutar múltiples hilos que procesan  *
 *              trabajos asignados. Cada hilo imprime  *
 *              su identificador de trabajo en pantalla*
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

/**
 * @brief Función ejecutada por cada hilo.
 * 
 * Esta función imprime el identificador del trabajo asociado
 * al hilo en ejecución.
 * 
 * @param argumentos Puntero a `size_t` que indica el número
 * del trabajo que se debe procesar.
 * 
 * @return NULL
 */
static void *funcion(void *argumentos) {
    size_t job = *(size_t *) argumentos; // Obtiene el identificador de trabajo
    printf("\n\t Job %zu \n", job);      // Imprime el trabajo en ejecución
    return NULL;
}

/**
 * @brief Función principal del programa.
 * 
 * En esta función se crean y ejecutan múltiples hilos
 * para procesar trabajos. El número de hilos y trabajos 
 * se determina a partir del argumento de entrada.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Vector de argumentos pasados al programa.
 *             El segundo argumento (argv[1]) debe ser 
 *             un número entero que indica la cantidad 
 *             de trabajos y hilos a crear.
 * 
 * @return 0 si la ejecución fue exitosa.
 */
int main(int argc, char *argv[]) {
    // Verificación de argumento de entrada
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <numero de hilos>\n", argv[0]);
        return 1;
    }
    
    // Número de trabajos y hilos a crear
    int N = atoi(argv[1]);
    
    // Vectores de trabajos e identificadores de hilos
    size_t jobs[N];            // Vector de trabajos
    pthread_t hilos[N];        // Vector de hilos

    // Creación de hilos y asignación de trabajos
    for (int i = 0; i < N; i++) {
        jobs[i] = i;  // Asigna un identificador de trabajo
        // Crea el hilo y ejecuta la función `funcion`
        pthread_create(&hilos[i], NULL, funcion, jobs + i);
    }

    // Espera a que todos los hilos terminen su ejecución
    for (int i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);
    }

    return 0;
}
