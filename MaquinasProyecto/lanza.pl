#!/usr/bin/perl
#**************************************************************
# Pontificia Universidad Javeriana
# Autor: Carlos Eduardo Rojas
# Fecha: 29/10/2024
# Materia: Sistemas Operativos
# Tema: Taller de Evaluación de Rendimiento
# Fichero: Script de automatización para ejecutar MM_ejecutable en diversas configuraciones.
#**************************************************************

# Ruta y nombre del ejecutable
$Path = `pwd`;
chomp($Path);
$Nombre_Ejecutable = "MM_ejecutable";

# Crear la carpeta DatosEjecucion si no existe
mkdir "$Path/DatosEjecucion" unless -d "$Path/DatosEjecucion";

# Configuración de la batería de experimentos
@Tamanos_Matriz = (2600, 2800, 3000, 3200, 3400, 3600, 3800, 4000);
@Num_Hilos = (1, 2, 4, 8);
$Repeticiones = 30;

# Ejecuta la batería de experimentos
foreach $size (@Tamanos_Matriz) {
    foreach $hilo (@Num_Hilos) {
        # Define el archivo de salida en la carpeta DatosEjecucion
        $file = "$Path/DatosEjecucion/${Nombre_Ejecutable}-${size}-Hilos-${hilo}.dat";
        
        for ($i = 0; $i < $Repeticiones; $i++) {
            # Ejecuta el programa y guarda la salida en el archivo correspondiente
            system("$Path/$Nombre_Ejecutable $size $hilo >> \"$file\"");
            print "$Path/$Nombre_Ejecutable $size $hilo \n";  # Muestra la ejecución actual en la terminal
        }
    }
}
