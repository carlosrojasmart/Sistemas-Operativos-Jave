/********************************
Autor: Carlos Eduardo Rojas
Fecha: 23/07/2024
Materia Sistemas Operativos
Tema: Programacion en C: Primera Parte 
Requerimientos:
      -Funcion que sume 2 enteros
      -Funcion que calcule el area de una circunferencia
      -Funcion que de la bienvenida
******************************/

#include<stdio.h>

/**Funcion que de la Bienvenida**/
void bienvenida(){
  printf("Hola Mundo...\n");
  printf("\t\tBienvenido a mi clase de Sistemas Operativos :) \n");
}
/**Funcion que sume 2 enteros**/
void suma2Enteros(){
  int n1 = 0;
  int n2 = 0;
  printf("\nIngrese su primer entero: ");
  scanf("%d", &n1);
  printf("\nIngrese su Segundo entero es: ");
  scanf("%d", &n2);
  int suma = n1 + n2;
  printf("\nEl resultado de suma es: %d\n", suma);
}
/**Funcion Calcula Area De Una Circunferencia**/
void AreaCircunferencia(){
    int radio= 0;
    float pi = 3.14;
  printf("\nIngrese el radio: ");
  scanf("%d", &radio);
    float area = radio*radio*pi;
    printf("El Area es: %f\n", area);
}

int main(int argc, char *argv[]){
  
   bienvenida();
   
   suma2Enteros();
    
   AreaCircunferencia();
    
  return 0;
  
}