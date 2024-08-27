/***************************************
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
 ******************************************/

/******************************************

IMPLEMENTACION DE FUNCIONES DE LA BIBLIOTECA

******************************************/

#ifndef ROJASLIBRERIA_H
#define ROJASLIBRERIA_H


void vectorInicio(vectorDinamico *V);

int totalVector(vectorDinamico *V);

static void resizeVector(vectorDinamico *V, int capacidad);

void addVector(vectorDinamico *V, void *elemento);

void freeVector(vectorDinamico *V);
  
void *getVector(vectorDinamico *V, int indice);

void setVector(vectorDinamico *V, int indice, void *elemento);

void borrarVector(vectorDinamico *V, int indice);

#endif
