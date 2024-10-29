/**************************************************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 29/10/2024
 * Materia: Sistemas Operativos
 * Tema: Taller de Evaluación de Rendimiento
 * Fichero: fuente de multiplicación de matrices NxN por hilos.
 * Objetivo: Evaluar el tiempo de ejecución del 
 *           algoritmo clásico de multiplicación de matrices.
 *           Se implementa con la Biblioteca POSIX Pthreads.
 **************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define DATA_SIZE (1024*1024*64*3) 

// Declaración de mutex y variables de matrices
pthread_mutex_t MM_mutex;
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;

// Estructura para parámetros de los hilos
struct parametros {
    int nH;     // Número de hilos
    int idH;    // ID del hilo
    int N;      // Tamaño de la matriz
};

// Variables para medición de tiempo
struct timeval start, stop;

/**
 * @brief Rellena matrices mA y mB con valores iniciales.
 * 
 * @param SZ Tamaño de la matriz cuadrada.
 */
void llenar_matriz(int SZ) { 
    srand48(time(NULL));
    for(int i = 0; i < SZ*SZ; i++) {
        mA[i] = 1.1 * i; // Valor inicial en matriz A
        mB[i] = 2.2 * i; // Valor inicial en matriz B
        mC[i] = 0;       // Inicializa matriz C en 0
    }
}

/**
 * @brief Imprime la matriz si su tamaño es pequeño (menor a 12x12).
 * 
 * @param sz Tamaño de la matriz cuadrada.
 * @param matriz Puntero a la matriz a imprimir.
 */
void print_matrix(int sz, double *matriz) {
    if(sz < 12) {
        for(int i = 0; i < sz * sz; i++) {
            if(i % sz == 0) printf("\n");
            printf(" %.3f ", matriz[i]);
        }    
        printf("\n>-------------------->\n");
    }
}

/**
 * @brief Inicializa la medición de tiempo.
 */
void inicial_tiempo() {
    gettimeofday(&start, NULL);
}

/**
 * @brief Finaliza la medición de tiempo y muestra el tiempo transcurrido.
 */
void final_tiempo() {
    gettimeofday(&stop, NULL);
    stop.tv_sec -= start.tv_sec;
    printf("\n:-> %9.0f µs\n", (double) (stop.tv_sec * 1000000 + stop.tv_usec));
}

/**
 * @brief Función de multiplicación de matrices ejecutada por cada hilo.
 * 
 * Cada hilo procesa una porción de la matriz y almacena el resultado en mC.
 * 
 * @param variables Estructura con los parámetros del hilo, incluyendo su ID, 
 *                  el número total de hilos, y el tamaño de la matriz.
 * 
 * @return NULL
 */
void *mult_thread(void *variables) {
    struct parametros *data = (struct parametros *)variables;
    int idH = data->idH;
    int nH  = data->nH;
    int N   = data->N;
    int ini = (N / nH) * idH;       // Índice inicial para este hilo
    int fin = (N / nH) * (idH + 1); // Índice final para este hilo

    // Multiplicación de la sección asignada
    for (int i = ini; i < fin; i++) {
        for (int j = 0; j < N; j++) {
            double *pA = mA + (i * N);
            double *pB = mB + (j * N);
            double sumaTemp = 0.0;
            
            // Cálculo de la celda i,j en mC
            for (int k = 0; k < N; k++, pA++, pB++) {
                sumaTemp += (*pA * *pB);
            }
            mC[i * N + j] = sumaTemp;
        }
    }

    pthread_mutex_lock(&MM_mutex);
    pthread_mutex_unlock(&MM_mutex);
    pthread_exit(NULL);
}

/**
 * @brief Función principal que inicia el programa de multiplicación de matrices.
 * 
 * Inicializa matrices, crea hilos, mide el tiempo de ejecución
 * y muestra el resultado.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Vector de argumentos. argv[1] es el tamaño de la matriz,
 *             argv[2] es el número de hilos.
 * 
 * @return 0 si la ejecución fue exitosa.
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
        return -1;    
    }

    int SZ = atoi(argv[1]);       // Tamaño de la matriz
    int n_threads = atoi(argv[2]); // Número de hilos a utilizar

    pthread_t p[n_threads];        // Array de hilos
    pthread_attr_t atrMM;

    // Inicialización de matrices en memoria
    mA = MEM_CHUNK;
    mB = mA + SZ * SZ;
    mC = mB + SZ * SZ;

    // Relleno e impresión inicial de matrices
    llenar_matriz(SZ);
    print_matrix(SZ, mA);
    print_matrix(SZ, mB);

    inicial_tiempo();
    pthread_mutex_init(&MM_mutex, NULL);
    pthread_attr_init(&atrMM);
    pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

    // Creación de hilos para multiplicación
    for (int j = 0; j < n_threads; j++) {
        struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
        datos->idH = j;
        datos->nH  = n_threads;
        datos->N   = SZ;
        pthread_create(&p[j], &atrMM, mult_thread, (void *)datos);
    }

    // Espera a que todos los hilos terminen
    for (int j = 0; j < n_threads; j++) {
        pthread_join(p[j], NULL);
    }

    final_tiempo();
    
    // Imprime la matriz resultante
    print_matrix(SZ, mC);

    // Limpieza de recursos
    pthread_attr_destroy(&atrMM);
    pthread_mutex_destroy(&MM_mutex);
    pthread_exit(NULL);
}
