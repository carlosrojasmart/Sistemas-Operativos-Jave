/********************************
Autor: Carlos Eduardo Rojas
Fecha: 30/07/2024
Materia Sistemas Operativos
Tema: Argumentos de entradas en c
******************************/

#include<stdio.h>
#include<stdbool.h>

/*Al inicio debe enviar el programa con el valor de la edad*/
/*Se presenta una serie de preguntas que el usuario debe responder*/

/**Funcion que de la Bienvenida**/
void bienvenida(){
  printf("\n\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}

int main(int argc, char *argv[]){
  
  bienvenida();
  
  char D1 = 'a';
  short D2 = 12;
  int D3 = 12356;
  long int D4 = 12346363636;
  bool D5 = 1;
  float D6 = 32.6;
  double D7 = 463.32;
  long double D8 = 463636.3253252523;
  
  
  printf("\n Un Dato Char es: %d\n\n", D1);
  printf("\n Un Dato Short es: %d\n\n", D2);
  printf("\n Un Dato Int es: %d\n\n", D3);
  printf("\n Un Dato Long es: %ld\n\n", D4);
  printf("\n Un Dato Bool es: %d\n\n", D5);
  printf("\n Un Dato Float es: %f\n\n", D6);
  printf("\n Un Dato Double es: %f\n\n", D7);
  printf("\n Un Dato Long Double es: %Lf\n\n", D8);
  
  
  printf("\n");
  return 0;
  
}