/********************************
Pontificia Universidad Javeriana
Autor: Carlos Eduardo Rojas
Fecha: 06/08/2024
Materia Sistemas Operativos
Tema: Evaluacion del Rendimiento de Sistemas De Computo
******************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DATA_RESERVA (1024*1024*64*3)

static double MEM_CHUNK[DATA_RESERVA];

/********************Funcion para multiplicar Matricez************/

void Mult_Matriz(int SZ, double *a, double *b, double *c){
  int i, j, k;
  for(i=0; i<SZ; i++){
    for(j=0; j<SZ; j++){
      double *pA, *pB, SumaTemp;
      SumaTemp = 0.0;
      pA = a+(i*SZ); pB= b+j;
      for(k=SZ; k>0; k--, pA++, pB+=SZ)
        SumaTemp += (*pA * *pB);
       c[i*SZ+j] = SumaTemp;
    }
  }
}

/********************Funcion para inicializar la matriz************/

void Init_Matriz(int SZ, double *a, double *b, double *c){
  int i, j, k;
  for(k=0; k<SZ; k++){
    for(j=0; j<SZ; j++){
      a[j+k*SZ]= 2.3*(j+k);
      b[j+k*SZ]= 3.2*(j-k);
      c[j+k*SZ]= 1.3; 
    }
  }
}

/********************Funcion para imprimir la matriz************/

void Print_Matriz(int SZ, double *a){
  int j, k;
  for(k=0; k<SZ; k++){
    for(j=0; j<SZ; j++){
      printf(" %f", a[j+k*SZ]);
    }
    printf("\n");
  }
  printf("----------------------------\n");
}

int main(int argc, char *argv[]){
  
  if(argc < 2){
    printf("./rojas MatrizSize NumHilos ....\n\n");
    return -1;
  }  
  
  int N = (int) atof(argv[1]);
  int h = (int) atof(argv[2]);
  
  double *A, *B, *C;
  /*Reserva de memoria inicial de las Matrizes*/
  A = MEM_CHUNK;
  B = A + N*N;
  C = B + N*N;
  
  printf("Valores Ingresados: \n");
  printf("Matriz Size (NxN): %dx%d \n",N,N);
  printf("Numero de hilos (h): %d\n",h);
  
  Init_Matriz(N, A, B, C);
  
  Print_Matriz(N, A);
  Print_Matriz(N, B);
  Mult_Matriz(N, A, B, C);
  Print_Matriz(N, C);
  
  return 0;
  
}