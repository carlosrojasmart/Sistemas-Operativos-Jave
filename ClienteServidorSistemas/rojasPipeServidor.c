/******************************** 
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 24/09/2024
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos con FIFO
 * Descripción:
 * El programa crea un servidor que utiliza una tubería FIFO para recibir
 * mensajes de otros procesos. Si no existe la tubería, la crea utilizando 
 * `mknod`. El servidor lee mensajes en un bucle hasta recibir la palabra 
 * "fin", momento en el cual cierra la conexión y termina.
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
    char BusMensaje[80];
    char final[10];
    int fin;
    int cantidadBytes;

    printf("\n \t\t >>>>>>>> INICIO SERVIDOR <<<<<<<< \n");

    /* Crea el FIFO o Tubería si no existe */
    mknod(FIFO_FILE, S_IFIFO | 0640, 0);
    strcpy(final, "fin");
    
    while (1) {
        /* Abre la tubería FIFO para lectura */
        ArchivoDesc = open(FIFO_FILE, O_RDONLY);
        cantidadBytes = read(ArchivoDesc, BusMensaje, sizeof(BusMensaje));
        BusMensaje[cantidadBytes] = '\0'; // Termina la cadena leída

        printf("Cadena Recibida: \"%s\" y cantidad de Bytes %d\n", BusMensaje, (int)strlen(BusMensaje));

        /* Compara si el mensaje es "fin" para terminar */
        fin = strcmp(BusMensaje, final);
        if (fin == 0) {
            close(ArchivoDesc);
            break;
        }
    }

    return 0;
}
