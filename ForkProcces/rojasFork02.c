/***********************************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 03/09/2024
 * Materia: Sistemas Operativos
 * Tema: Introducción a procesos con fork
 * 
 * Descripción:
 * Este programa demuestra el uso de la función fork() para crear un nuevo 
 * proceso. La función fork() genera un proceso hijo que es una copia del 
 * proceso padre, ambos con espacios de memoria separados. 
 * 
 * Nota:
 * - El proceso hijo siempre tendrá un ID de proceso (PID) igual a 0 en el 
 *   proceso padre.
 * - El proceso padre recibe el PID del proceso hijo.
 * 
 * Funcionalidad:
 * - Imprime un mensaje inicial.
 * - Divide la ejecución en secciones para el proceso padre y el proceso hijo.
 * - Cada proceso (padre e hijo) imprimirá números del 10 al 1.
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t id;  // Tipo de datos para almacenar el PID

    // Mensaje inicial
    printf("\nHola Carlos Rojas, profesional en formación\n");
    printf("\n\t ---> PROGRAMA PRINCIPAL <---\n");

    /* Creación de un nuevo proceso */
    id = fork();

    if (id > 0) {
        // Este bloque se ejecuta en el proceso padre
        printf("\n--> Sección del PADRE\n");
    } else if (id == 0) {
        // Este bloque se ejecuta en el proceso hijo
        printf("\n--> Sección del HIJO\n");
    } else {
        // Manejo de errores en caso de falla en fork()
        printf("\n\nHubo un error en la creación del proceso con fork\n\n");
        return 1;  // Retorna un código de error
    }

    /* Imprime números del 10 al 1 */
    for (int i = 10; i > 0; i--) {
        printf("->: %d\n", i);
    }

    // Mensaje de fin del programa
    printf("\n\nFin del Programa!!!\n\n");

    return 0;
}
