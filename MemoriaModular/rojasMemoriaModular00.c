/********************************
 * Pontificia Universidad Javeriana
 * Autor: Carlos Eduardo Rojas
 * Fecha: 27/08/2024
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria, punteros y memoria dinámica
 * Tópico: Compilacion Modular
 * 
 * Descripción:
 *
 * Subdivide un sistema en partes más pequeñas llamadas módulos o plataformas, 
 * que pueden crearse de manera independiente y luego usarse en diferentes sistemas.
 *
 *Cada Modulo contiene una parte del codigo y puede gestionarse de forma autonoma 
 *facilitando el desarollo, mantenimiento y pruebas de software
 *
 *Esto permite que los cambios de un modulo no requieran la recompilacion de todo
 *el programa
 *
 ******************************/

#include <stdio.h>
#include <stdlib.h>


#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}

void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

void freeVector(vectorDinamico *V){
        free(V->elementos);
}

void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}


void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}

int main(){
        int i;
        vectorDinamico editor;
        vectorInicio(&editor);
        printf("\n");

        addVector(&editor, "\nHola");
        addVector(&editor, "Profesional");
        addVector(&editor, "en");
        addVector(&editor, "Formacion");
        addVector(&editor, "en");
        addVector(&editor, "Ingenieria");

        for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
  
        printf("\n\n");  

        while(i>1){
          borrarVector(&editor, i);
          i--;
        }  
   
        setVector(&editor, 1, "Buenos");
        addVector(&editor, "Dias");


        for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
  
        freeVector(&editor);
  
        printf("\n\n");

        return 0;
}
