/***********************************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 03/09/2024
 * Materia: Sistemas Operativos
 * Tema: Introducción a procesos con fork y comunicación con pipes
 * 
 * Descripción:
 * Este programa demuestra el uso de la función fork() para crear un nuevo proceso
 * y la función pipe() para establecer una comunicación unidireccional entre el
 * proceso padre y el proceso hijo.
 * 
 * Nota:
 * - La función fork() crea un nuevo proceso (hijo) que es una copia del proceso padre.
 * - La función pipe() crea una tubería que permite la comunicación entre los procesos.
 * 
 * Funcionalidad:
 * - El proceso padre recibe un mensaje enviado por el proceso hijo a través de una tubería.
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    pid_t proceso;  // Identificador del proceso
    int auxiliar;   // Variable para el tamaño de lectura del mensaje

    // Mensaje a ser enviado del proceso hijo al proceso padre
    char sms[] = "Hola, te envío este mensaje profesional en formación";
    char lectorMensaje[80];  // Buffer para recibir el mensaje

    // Arreglo para almacenar los descriptores de archivo de la tubería
    int tuberia[2];

    // Crear la tubería
    if (pipe(tuberia) == -1) {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }

    // Crear un nuevo proceso
    if ((proceso = fork()) > 0) {
        // Proceso padre
        // Cerrar el descriptor de escritura de la tubería
        close(tuberia[1]);

        // Leer el mensaje del descriptor de lectura de la tubería
        auxiliar = read(tuberia[0], lectorMensaje, sizeof(lectorMensaje));
        if (auxiliar == -1) {
            perror("Error al leer de la tubería");
            exit(EXIT_FAILURE);
        }

        // Mostrar el mensaje recibido
        printf("\n ---> Mensaje Recibido: \n\t%s\n", lectorMensaje);

        // Cerrar el descriptor de lectura de la tubería
        close(tuberia[0]);
    } else if (proceso == 0) {
        // Proceso hijo
        printf("\n --> Sección del HIJO\n");

        // Cerrar el descriptor de lectura de la tubería
        close(tuberia[0]);

        // Escribir el mensaje en el descriptor de escritura de la tubería
        if (write(tuberia[1], sms, (strlen(sms) + 1)) == -1) {
            perror("Error al escribir en la tubería");
            exit(EXIT_FAILURE);
        }

        // Cerrar el descriptor de escritura de la tubería
        close(tuberia[1]);

        // Terminar el proceso hijo
        exit(EXIT_SUCCESS);
    } else {
        // Manejo de errores en caso de falla en fork()
        perror("Error al crear el proceso");
        exit(EXIT_FAILURE);
    }

    // Mensaje de fin del programa
    printf("\n\nFin del Programa!!!\n\n");

    return 0;
}
