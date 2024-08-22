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
  
  printf("\n Ha ingresado [%d]: \n\n",argc);
  printf("\n Ha ingresado la edad: %s;\n\n", argv[1]);
  printf("\n Ha ingresado el mes actual: %s\n\n", argv[2]);
  printf("\n Ha ingresado la Nombre: %s;\n\n", argv[3]);
  printf("\n Ha ingresado el Apellido: %s\n\n", argv[4]);
  printf("\n Ha ingresado la Comida Favorita: %s;\n\n", argv[5]);
  printf("\n Ha ingresado el Universidad: %s\n\n", argv[6]);
  printf("\n Ha ingresado el Hobby: %s\n\n", argv[7]);
  printf("\n Ha ingresado el Ciudad Actual: %s\n\n", argv[8]);
  
  printf("\n");
  return 0;
  
}