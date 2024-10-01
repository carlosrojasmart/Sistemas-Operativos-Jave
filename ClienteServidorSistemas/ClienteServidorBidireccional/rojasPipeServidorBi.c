/******************************** 
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 01/10/2024
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos usando FIFO
 * Descripción:
 * Este programa crea un servidor que utiliza una tubería FIFO para recibir mensajes.
 * Si la tubería no existe, la crea con `mkfifo`. El servidor sigue leyendo mensajes
 * hasta que recibe "fin", lo que cierra la conexión y termina el proceso.
 ******************************/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define FIFO_FILE "/tmp/fifo_twoway" // Ruta del FIFO

void string_reservado(char *); // Prototipo de función para invertir cadenas

int main() {
    int fd; // Descriptor de archivo para el FIFO
    char lecturaBuffer[80]; // Buffer para almacenar los mensajes recibidos
    char fin[10]; // Cadena para comparar con "fin"
    int proceso_fin; // Variable para verificar si el mensaje es "fin"
    int lectura_bytes; // Bytes leídos del FIFO

    mkfifo(FIFO_FILE, S_IFIFO|0640); // Crea el FIFO si no existe
    strcpy(fin, "fin"); // Define la cadena de finalización
    fd = open(FIFO_FILE, O_RDWR); // Abre el FIFO para lectura y escritura

    while (1) {
        lectura_bytes = read(fd, lecturaBuffer, sizeof(lecturaBuffer)); // Lee un mensaje del FIFO
        lecturaBuffer[lectura_bytes] = '\0'; // Añade el terminador de cadena
        printf("FIFOSERVIDOR: Mensaje Recibido: \"%s\" tamaño: %d\n", lecturaBuffer, (int)strlen(lecturaBuffer));
        proceso_fin = strcmp(lecturaBuffer, fin); // Compara si el mensaje es "fin"

        if (proceso_fin == 0) { // Si es "fin", cierra el FIFO y termina
            close(fd);
            break;
        }

        string_reservado(lecturaBuffer); // Invierte el mensaje recibido
        printf("FIFOSERVIDOR: Enviando Mensaje Invertido: \"%s\" tamaño: %d\n", lecturaBuffer, (int)strlen(lecturaBuffer));
        write(fd, lecturaBuffer, strlen(lecturaBuffer)); // Envía el mensaje invertido
        sleep(2); // Espera para permitir que otro proceso lea el mensaje
    }
    return 0;
}

// Función para invertir una cadena
void string_reservado(char *str) {
    int Ultima, Limite, Primera;
    char temp;
    Ultima = strlen(str) - 1; // Índice del último carácter
    Limite = Ultima / 2; // Límite hasta el que se invierte la cadena
    Primera = 0; // Índice del primer carácter

    while (Primera < Ultima) { // Intercambia caracteres de los extremos hacia el centro
        temp = str[Primera];
        str[Primera] = str[Ultima];
        str[Ultima] = temp;
        Primera++;
        Ultima--;
    }
    return;
}
