/******************************** 
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 24/09/2024
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos con FIFO
 * Descripción:
 * El programa actúa como un cliente que envía mensajes a través de una 
 * tubería FIFO previamente creada. El cliente envía mensajes de forma 
 * continua hasta que el mensaje "fin" es ingresado, lo que detiene la 
 * comunicación y cierra la conexión.
 ******************************/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define FIFO_FILE "MYFIFO"

int main() {
    int ArchivoDesc;
    int fin_proceso;
    int cadena;
    char BusMensaje[80];
    char senalFin[5];

    printf("\n \t\t >>>>>>>> INICIO CLIENTE <<<<<<<< \n");

    printf("FIFO_CLIENTE: Enviando Mensajes, para finalizar, ingrese \"fin\"\n");
    ArchivoDesc = open(FIFO_FILE, O_CREAT | O_WRONLY);
    strcpy(senalFin, "fin");

    while (1) {
        /* Solicita al usuario un mensaje */
        printf("Ingrese Mensaje: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);
        cadena = strlen(BusMensaje);
        BusMensaje[cadena - 1] = '\0';  // Elimina el salto de línea final

        /* Compara si el mensaje es "fin" para finalizar */
        fin_proceso = strcmp(BusMensaje, senalFin);
        printf("Final de proceso %d\n", fin_proceso);

        if (fin_proceso != 0) {
            /* Envía el mensaje por la tubería FIFO */
            write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
            printf("Mensaje Enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
        } else {
            /* Envía el mensaje final "fin" y cierra la conexión */
            write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
            printf("Mensaje Enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
            close(ArchivoDesc);
            break;
        }
    }

    return 0;
}
