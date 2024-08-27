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

#include "rojasLibreria.h"

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