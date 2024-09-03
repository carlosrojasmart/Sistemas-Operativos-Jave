/***********************************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 03/09/2024
 * Materia: Sistemas Operativos
 * Tema: Introducción a procesos con fork
 * 
 * Descripción:
 * Este programa utiliza la función fork() para crear un nuevo proceso.
 * La función fork() genera un proceso hijo que es una copia del proceso padre.
 * Ambos procesos (padre e hijo) tienen espacios de memoria separados, pero 
 * son idénticos hasta que el programador decida modificarlos.
 * 
 * Nota:
 * - El proceso hijo siempre tendrá un ID de proceso (PID) igual a 0 en el 
 *   proceso padre. 
 * - El proceso padre recibe el PID del proceso hijo.
 * 
 * Funcionalidad:
 * - Imprime un mensaje para el proceso padre y el proceso hijo.
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t id;  // Tipo de datos para almacenar el PID

    // Mensaje inicial
    printf("\nHola Carlos Rojas, profesional en formación\n");

    /* Creación de un nuevo proceso */
    id = fork();

    if (id > 0) {
        // Este bloque se ejecuta en el proceso padre
        printf("\nSoy el proceso PADRE con ID = %d\n\n", getpid());
    } else if (id == 0) {
        // Este bloque se ejecuta en el proceso hijo
        printf("\nSoy el proceso HIJO con ID = %d\n\n", getpid());
    } else {
        // Manejo de errores en caso de falla en fork()
        printf("\n\nHubo un error en la creación del proceso con fork\n\n");
    }

    return 0;
}
