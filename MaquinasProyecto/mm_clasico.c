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

// Mutex para sincronización en sección crítica
pthread_mutex_t MM_mutex;
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;  // Punteros para matrices

// Estructura para los parámetros de los hilos
struct parametros {
    int nH;     // Número total de hilos
    int idH;    // ID del hilo
    int N;      // Tamaño de la matriz
};

// Variables para medición de tiempo
struct timeval start, stop;

/**
 * @brief Llena las matrices mA y mB con valores iniciales.
 * 
 * @param SZ Tamaño de la matriz cuadrada (SZxSZ).
 */
void llenar_matriz(int SZ) { 
    srand48(time(NULL));  // Inicializa generador de números aleatorios
    for(int i = 0; i < SZ * SZ; i++) {
        mA[i] = 1.1 * i; // Asigna valores a la matriz A
        mB[i] = 2.2 * i; // Asigna valores a la matriz B
        mC[i] = 0;       // Inicializa matriz C en 0
    }    
}

/**
 * @brief Imprime la matriz en consola si su tamaño es menor que 12x12.
 * 
 * @param sz Tamaño de la matriz cuadrada.
 * @param matriz Puntero a la matriz a imprimir.
 */
void print_matrix(int sz, double *matriz) {
    if(sz < 12) { // Solo imprime matrices pequeñas
        for(int i = 0; i < sz * sz; i++) {
            if(i % sz == 0) printf("\n");
            printf(" %.3f ", matriz[i]);
        }    
        printf("\n>-------------------->\n");
    }
}

/**
 * @brief Inicia la medición de tiempo.
 */
void inicial_tiempo() {
    gettimeofday(&start, NULL);
}

/**
 * @brief Finaliza la medición de tiempo y muestra el tiempo transcurrido en µs.
 */
void final_tiempo() {
    gettimeofday(&stop, NULL);
    stop.tv_sec -= start.tv_sec;
    printf("\n:-> %9.0f µs\n", (double) (stop.tv_sec * 1000000 + stop.tv_usec));
}

/**
 * @brief Multiplica las matrices mA y mB en paralelo usando hilos.
 * 
 * Cada hilo realiza la multiplicación de una porción de la matriz
 * y almacena el resultado en mC.
 * 
 * @param variables Estructura con los parámetros del hilo, incluyendo su ID, 
 *                  el número total de hilos y el tamaño de la matriz.
 * 
 * @return NULL
 */
void *mult_thread(void *variables) {
    struct parametros *data = (struct parametros *)variables;
    int idH = data->idH;
    int nH  = data->nH;
    int N   = data->N;
    int ini = (N / nH) * idH;        // Índice de inicio de fila para este hilo
    int fin = (N / nH) * (idH + 1);  // Índice de fin de fila para este hilo

    // Multiplicación parcial de matrices
    for (int i = ini; i < fin; i++) {
        for (int j = 0; j < N; j++) {
            double *pA = mA + (i * N);
            double *pB = mB + j;
            double sumaTemp = 0.0;

            for (int k = 0; k < N; k++, pA++, pB += N) {
                sumaTemp += (*pA * *pB);  // Acumula producto escalar
            }
            mC[i * N + j] = sumaTemp;  // Almacena el resultado en mC
        }
    }

    pthread_mutex_lock(&MM_mutex);
    pthread_mutex_unlock(&MM_mutex);
    pthread_exit(NULL);
}

/**
 * @brief Función principal que prepara y ejecuta la multiplicación de matrices.
 * 
 * Inicializa matrices, crea hilos para la multiplicación, mide el tiempo de ejecución 
 * y muestra la matriz resultante.
 * 
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Vector de argumentos de línea de comandos. argv[1] es el tamaño de la matriz,
 *             argv[2] es el número de hilos.
 * 
 * @return 0 si la ejecución fue exitosa.
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <tamMatriz> <numHilos>\n", argv[0]);
        return -1;    
    }

    int SZ = atoi(argv[1]);        // Tamaño de la matriz
    int n_threads = atoi(argv[2]); // Número de hilos

    pthread_t p[n_threads];        // Array de hilos
    pthread_attr_t atrMM;

    // Asigna espacio de memoria para las matrices
    mA = MEM_CHUNK;
    mB = mA + SZ * SZ;
    mC = mB + SZ * SZ;

    // Relleno inicial e impresión de matrices
    llenar_matriz(SZ);
    print_matrix(SZ, mA);
    print_matrix(SZ, mB);

    inicial_tiempo();
    pthread_mutex_init(&MM_mutex, NULL);
    pthread_attr_init(&atrMM);
    pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

    // Creación de hilos para realizar la multiplicación
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
