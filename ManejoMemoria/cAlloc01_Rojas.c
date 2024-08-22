/********************************
*Pontificia Universidad Javeriana
*Autor: Carlos Eduardo Rojas
*Fecha: 13/08/2024
*Materia Sistemas Operativos
*Tema: Gestion  de Memoria
*Topico: Reserva de Memoria con la funcion calloc().
*La funcion calloc reserva un espacio de memoria de tamaño requerido.
******************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

  /*Se Declaran las variables y puntos de necesarios*/
  int *p1 = malloc(4*sizeof(int)); //Asignacion de memoria para un bloque de 4 enteros
  int *puntero = malloc(1*sizeof(int[4])); //Asignacion de memoria para un puntero de 1 enteros
  int *p3 = malloc(5*sizeof *p3); //Asignacion de memoria para un puntero de 5 enteros
  
  /*Bucle para llenar los espacios Primer Bloque reservado (puntero)*/

  printf("\nConstruccion y calculo de la secuencia de los primeros 10 terminos \n\n");
  for(int i=0; i<10; i++){
    *(puntero+i) = i; //Se llena la posicion 9na del puntero con el valor 9889
    printf("El valor de la secuencia es: %d \n\n", *(puntero+i));
  }
  
  /*Liberacion o retorno de memoria*/
  free(puntero);
  free(p1);
  free(p3);  
  return 0;

}