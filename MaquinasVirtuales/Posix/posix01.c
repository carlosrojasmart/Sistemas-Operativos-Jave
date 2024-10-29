/**********************************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 15/10/2024
 * Materia: Sistemas Operativos
 * Tema: POSIX - Problema de Productor y Consumidor
 * Descripción: Este programa implementa el problema 
 *              clásico de productor y consumidor usando
 *              hilos y variables de condición en POSIX.
 **********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

// Variables compartidas y constantes
int counter = 0;            // Contador de ítems producidos/consumidos
int max = 4;                // Número máximo de hilos productores y consumidores

// Inicialización de mutex y variables de condición
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condVarProd  = PTHREAD_COND_INITIALIZER;
pthread_cond_t  condVarCons  = PTHREAD_COND_INITIALIZER;

// Declaración de funciones para hilos productor y consumidor
void *consumidor();
void *productor();

/**
 * @brief Función ejecutada por los hilos productores.
 *        Incrementa el contador si no está lleno y 
 *        notifica a los consumidores. 
 */
void *productor() {
    while(1) {
        pthread_mutex_lock(&condp_mutex);
        
        // Espera si el contador ha alcanzado el límite superior (10)
        while(counter >= 10) {
            pthread_cond_wait(&condVarProd, &condp_mutex);
        }
        pthread_mutex_unlock(&condp_mutex);

        pthread_mutex_lock(&counter_mutex);
        counter++;  // Incrementa el contador de ítems producidos
        pthread_cond_signal(&condVarCons);  // Notifica a un consumidor disponible
        printf("Soy productor %ld valor contador = %d\n", pthread_self(), counter);
        pthread_mutex_unlock(&counter_mutex);

        if(counter == 5) {
            sleep(1); // Simulación de espera al alcanzar el contador de 5
        }
    }
    return NULL;
}

/**
 * @brief Función ejecutada por los hilos consumidores.
 *        Decrementa el contador si hay ítems disponibles 
 *        y notifica a los productores.
 */
void *consumidor() {
    while(1) {
        sleep(1);  // Espera de 1 segundo para simular consumo
        
        pthread_mutex_lock(&condc_mutex);
        
        // Espera si no hay ítems disponibles para consumir
        while(counter == 0) {
            pthread_cond_signal(&condVarProd);  // Notifica a un productor
            pthread_cond_wait(&condVarCons, &condc_mutex);
        }
        pthread_mutex_unlock(&condc_mutex);

        pthread_mutex_lock(&counter_mutex);
        if(counter > 0) {
            printf("Soy consumidor %ld valor contador = %d\n", pthread_self(), counter);
            counter--;  // Decrementa el contador tras consumir un ítem
            pthread_cond_signal(&condVarProd);  // Notifica a un productor
        }
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

/**
 * @brief Función principal que crea y espera a los hilos productores
 *        y consumidores. Configura cinco hilos de cada tipo.
 * 
 * @return 0 si el programa finaliza correctamente.
 */
int main() {
    pthread_t proHilo[max], conHilo[max]; // Arrays de hilos para productores y consumidores
    int i;

    // Creación de cinco hilos productores y cinco hilos consumidores
    for(i = 0; i < max; i++) {
        pthread_create(&proHilo[i], NULL, &productor, NULL);
        pthread_create(&conHilo[i], NULL, &consumidor, NULL);
    }

    // Espera a que todos los hilos terminen
    for(i = 0; i < max; i++) {
        pthread_join(proHilo[i], NULL);
        pthread_join(conHilo[i], NULL);
    }

    return 0;
}
