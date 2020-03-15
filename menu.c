/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/* Desarrollo de funciones */
/* Menu principal */
void menu(){
    system("clear");
    puts("\t\t\tMENÚ\n");
    puts("\t1.- Altas (Clientes/Asesores/Productos/Categorias/Departamentos.)");
    puts("\t2.- Desplegar datos (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t3.- Actualizar datos (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t4.- Eliminar (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t5.- Realizar compra.");
    puts("\t6.- Salir.");
    printf("\nIngresar opcion-> ");
}

/* Menu de altas */
void menuAltas(){
    system("clear");
    puts("\t\t\tMENÚ ALTAS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
}