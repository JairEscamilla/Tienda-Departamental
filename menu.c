/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "headers.h"
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
void menuAltas(Conexion con){
    int opcionSubMenu;
    char campos[5][7][150] = {
        {"nombre del asesor", "apellido materno", "apellido paterno"},
        {"nombre del producto", "descripcion", "precio", "stock", "costo de envio"},
        {"nombre de la categoria", "descripcion de la categoria", "id del departamento al que pertenece"},
        {"nombre del departamento"}
    };
    char camposDB[5][7][150] = {
        {"nombre", "apPaterno", "apMaterno"},
        {"nombreProducto", "descripcion", "precio", "stock", "costoEnvio"},
        {"nombreCategoria", "descripcionCategoria", "idDepartamento"},
        {"nombreDepartamento"}
    };
    system("clear");
    puts("\t\t\tMENÚ ALTAS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf(" %d", &opcionSubMenu);
    if (opcionSubMenu == 1)
        insertarClientes(con);
    if (opcionSubMenu == 2)
        insertarDatos(campos[0], 3, "pr1_asesores", camposDB[0], con);
    if (opcionSubMenu == 3)
        insertarDatos(campos[1], 5, "pr1_productos", camposDB[1], con);
    if (opcionSubMenu == 4)
        insertarDatos(campos[2], 3, "pr1_categorias_productos", camposDB[2], con);
    if (opcionSubMenu == 5)
        insertarDatos(campos[3], 1, "pr1_departamentos", camposDB[3], con);
}

void menuActualizaciones(Conexion con){
    int subMenuOpcion;
    char tablas[5][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos"};
    system("clear");
    setbuf(stdin, NULL); // Limpiando buffer
    puts("\t\t\tMENU ACTUALIZACIONES\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf("%d", &subMenuOpcion);
    if(subMenuOpcion < 6 && subMenuOpcion > 0)
        actualizar(tablas[subMenuOpcion-1], subMenuOpcion, con);
    getchar();
}