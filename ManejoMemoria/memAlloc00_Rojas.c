/********************************
*Pontificia Universidad Javeriana
*Autor: Carlos Eduardo Rojas
*Fecha: 13/08/2024
*Materia Sistemas Operativos
*Tema: Gestion  de Memoria
*Topico: Reserva de Memoria con la funcion malloc().
*La funcion malloc reserva un espacio d ememoria de tamaño bytes y devuelve un puntero
a ese espacio reservado.
******************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

  /*Se Declaran las variables y puntos de necesarios*/
  int *bloque00 = malloc(4*sizeof(int)); //Asignacion de memoria para un bloque de 4 enteros
  int *puntero = malloc(15*sizeof(*puntero)); //Asignacion de memoria para un puntero de 15 enteros

  /*Bucle para llenar los espacios Primer Bloque reservado (bloque00)*/
  for(int i=0; i<4; i++){
    bloque00[i] = i*2;
    printf("El valor de memoria reservada bloque00[%d] es: %d \n\n", i, bloque00[i]);
  }

  /*Bucle para llenar los espacios Primer Bloque reservado (puntero)*/
  if(puntero!=NULL){
    *(puntero+8) = 9889; //Se llena la posicion 9na del puntero con el valor 9889
    printf("El valor de la 9a posicion de puntero es: %d \n\n", *(puntero+8));
    printf("El valor de la 9a posicion de puntero es: %d \n\n", puntero[8]);
  }
  
  /*Liberacion o retorno de memoria*/
  free(bloque00);
  free(puntero);
  return 0;

}