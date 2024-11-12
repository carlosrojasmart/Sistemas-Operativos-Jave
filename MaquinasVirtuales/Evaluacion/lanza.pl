#!/usr/bin/perl
#**************************************************************
#     Pontificia Universidad Javeriana
#     Autor: Carlos Eduardo Rojas
#     Fecha: 29/10/2024
#     Materia: Sistemas Operativos
#     Tema: Taller de Evaluación de Rendimiento
#     Fichero: script automatización ejecución por lotes 
#     Descripción: Este script automatiza la ejecución de un 
#                  programa de multiplicación de matrices en 
#                  paralelo para varios tamaños y cantidades 
#                  de hilos, guardando los resultados en archivos.
#****************************************************************/

# Obtiene el directorio actual
$Path = `pwd`;
chomp($Path);

# Configuración de parámetros
$Nombre_Ejecutable = "MM_ejecutable";  # Nombre del ejecutable a ejecutar
@Size_Matriz = ("200", "300");         # Tamaños de matriz a probar
@Num_Hilos = (1, 2);                   # Cantidades de hilos a usar
$Repeticiones = 2;                     # Número de repeticiones por configuración

# Bucle para cada tamaño de matriz
foreach $size (@Size_Matriz) {
    # Bucle para cada número de hilos
    foreach $hilo (@Num_Hilos) {
        # Nombre de archivo para almacenar resultados
        $file = "$Path/$Nombre_Ejecutable-" . $size . "-Hilos-" . $hilo . ".dat";
        
        # Ejecución repetida según número de repeticiones
        for ($i = 0; $i < $Repeticiones; $i++) {
            # Ejecuta el programa con el tamaño y número de hilos especificados
            # Guarda la salida en el archivo correspondiente
            # Descomentar la siguiente línea para ejecutar y almacenar los resultados
            system("$Path/$Nombre_Ejecutable $size $hilo >> \"$file\"");
            
            # Imprime el comando ejecutado (para fines de verificación)
            printf("$Path/$Nombre_Ejecutable $size $hilo \n");
        }
        close($file); # Cierra el archivo de resultados
    }
}
