/******************************** 
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 01/10/2024
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos usando FIFO
 * Codigo: Cliente De Envio de Mensajes Bidireccional
 * Descripción:
 * Este programa es un cliente que envía mensajes a través de un FIFO.
 * Los mensajes se envían continuamente hasta que el usuario ingresa "fin",
 * lo que termina la comunicación y cierra la conexión.
 ******************************/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define FIFO_FILE "/tmp/fifo_twoway" // Ruta del FIFO

int main() {
    int fd; // Descriptor de archivo para el FIFO
    int fin_proceso; // Variable para verificar si el mensaje es "fin"
    int longitud_cadena; // Longitud del mensaje
    int lectura_bytes; // Bytes leídos del FIFO
    char lecturaBuffer[80]; // Buffer para almacenar mensajes
    char fin_str[5]; // Cadena de comparación para "fin"
    
    printf("FIFO_CLIENTE: Envia mensajes, escribe 'fin' para finalizar\n");
    fd = open(FIFO_FILE, O_CREAT|O_RDWR); // Abre el FIFO para lectura y escritura
    strcpy(fin_str, "fin"); // Cadena de finalización

    while (1) {
        printf("Ingresa Mensaje: ");
        fgets(lecturaBuffer, sizeof(lecturaBuffer), stdin); // Lee el mensaje del usuario
        longitud_cadena = strlen(lecturaBuffer);
        lecturaBuffer[longitud_cadena - 1] = '\0'; // Elimina el salto de línea
        fin_proceso = strcmp(lecturaBuffer, fin_str); // Compara si el mensaje es "fin"

        if (fin_proceso != 0) { // Si no es "fin", envía el mensaje
            write(fd, lecturaBuffer, strlen(lecturaBuffer)); // Envía el mensaje al FIFO
            printf("FIFOCLIENTE: Enviando Mensaje: \"%s\" tamaño: %d\n", lecturaBuffer, (int)strlen(lecturaBuffer));
            lectura_bytes = read(fd, lecturaBuffer, sizeof(lecturaBuffer)); // Lee la respuesta del servidor
            lecturaBuffer[lectura_bytes] = '\0'; // Asegura que la cadena leída termine con '\0'
            printf("FIFOCLIENTE: Mensaje Recibido: \"%s\" tamaño: %d\n", lecturaBuffer, (int)strlen(lecturaBuffer));
        } else { // Si el mensaje es "fin", cierra el FIFO y termina
            write(fd, lecturaBuffer, strlen(lecturaBuffer)); // Envía el mensaje de cierre
            printf("FIFOCLIENTE: Enviando Mensaje: \"%s\" tamaño: %d\n", lecturaBuffer, (int)strlen(lecturaBuffer));
            close(fd); // Cierra la conexión
            break;
        }
    }
    return 0;
}
