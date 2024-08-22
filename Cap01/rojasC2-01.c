/********************************
Autor: Carlos Eduardo Rojas
Fecha: 30/07/2024
Materia Sistemas Operativos
Tema: Argumentos de entradas en c
******************************/

#include<stdio.h>

/*Al inicio debe enviar el programa con el valor de la edad*/
/*Se presenta una serie de preguntas que el usuario debe responder*/

/**Funcion que de la Bienvenida**/
void bienvenida(){
  printf("\n\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

int main(int argc, char *argv[]){
  
   bienvenida();
  
  int x = 102;
  int *p = x;
  printf("\n El valor X es de: %d \n", x);
  printf("\n La direccion de X es: %p \n\n", p);
  
  int vector[] = {5,10,20,30,40,50,80};
  int *p1 = vector;
  int *p2 = vector+2;
  int diferencia = p2-p1;
  
  printf("\n El valor p2 es de: %p \n", p1);
  printf("\n El valor p2 es de: %p \n", p2);
  printf("\n El valor resta de: %d \n", diferencia);
  
  printf("\n");
  return 0;
  
}