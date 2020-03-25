/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    inserciones.c
 * @brief:  Este archivo contiene las funciones de menu.
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "headers.h"
/* Desarrollo de funciones */
/* * Funcion que despliega el menu principal.
*/
void menu(){
    system("clear");
    puts("\t\t\tMENÚ\n");
    puts("\t1.- Altas (Clientes/Asesores/Productos/Categorias/Departamentos/Comentarios/Etc.)");
    puts("\t2.- Desplegar datos (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t3.- Actualizar datos (Clientes/Asesores/Productos/Categorias/Comentarios/Etc).");
    puts("\t4.- Eliminar (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t5.- Realizar compra.");
    puts("\t6.- Salir.");
    printf("\nIngresar opcion-> ");
}

/* * Funcion de menú de altas.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void menuAltas(Conexion con){
    int opcionSubMenu;
    char campos[9][7][150] = {
        {"nombre del asesor", "apellido materno", "apellido paterno"},
        {"nombre del producto", "descripcion", "precio", "stock", "costo de envio"},
        {"nombre de la categoria", "descripcion de la categoria", "id del departamento al que pertenece"},
        {"nombre del departamento"},
        {"username", "idProducto", "comentario"},
        {"id de compra", "id de producto a devolver", "comentario de devolucion"},
        {"comentario de cancelacion", "id de la compra"},
        {"username", "id del asesor", "comentario", "status 1/0"},
        {"numero de tarjeta", "fecha de vencimiento (AAAA-MM-DD)", "username"}
    };
    char camposDB[9][7][150] = {
        {"nombre", "apPaterno", "apMaterno"},
        {"nombreProducto", "descripcion", "precio", "stock", "costoEnvio"},
        {"nombreCategoria", "descripcionCategoria", "idDepartamento"},
        {"nombreDepartamento"},
        {"pr1_clientes_username", "pr1_productos_idProducto", "comentario"},
        {"idCompra", "idProductoDevuelto", "comentarioDevolucion"},
        {"comentarioCancelacion", "idCompra"},
        {"pr1_clientes_username", "pr1_asesores_idAsesor", "comentario", "status"},
        {"numeroTarjeta", "fechaVencimiento", "username"}
    };
    char nombresTablas[10][100] = {"pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos", "pr1_comentarios", "pr1_devoluciones", "pr1_cancelacion", "pr1_quejas", "pr1_tarjetas"};
    int numeroCampos[10] = {3, 5, 3, 1, 3, 3, 2, 4, 3};
    system("clear");
    puts("\t\t\tMENÚ ALTAS\n");
    opcionesMenu();
    printf("\nIngresar opcion-> ");
    scanf(" %d", &opcionSubMenu);
    if (opcionSubMenu == 1)
        insertarClientes(con);
    else if (opcionSubMenu >= 2 && opcionSubMenu <= 10)
        insertarDatos(campos[opcionSubMenu - 2], numeroCampos[opcionSubMenu - 2], nombresTablas[opcionSubMenu - 2], camposDB[opcionSubMenu - 2], con);
}

/* * Funcion de menu de actualizaciones.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void menuActualizaciones(Conexion con){
    int subMenuOpcion;
    char tablas[11][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos", "pr1_comentarios", "pr1_devoluciones", "pr1_cancelacion", "pr1_quejas", "pr1_tarjetas"};
    system("clear");
    setbuf(stdin, NULL); // Limpiando buffer
    puts("\t\t\tMENU ACTUALIZACIONES\n");
    opcionesMenu();
    printf("\nIngresar opcion-> ");
    scanf("%d", &subMenuOpcion);
    if(subMenuOpcion < 11 && subMenuOpcion > 0)
        actualizar(tablas[subMenuOpcion-1], subMenuOpcion, con);
    getchar();
}

/* * Funcion de menu de desplegar datos.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void menuDesplegar(Conexion con){
    int subMenuOpcion;
    char tablas[11][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos", "pr1_comentarios", "pr1_devoluciones", "pr1_cancelacion", "pr1_quejas", "pr1_tarjetas"};
    system("clear");
    puts("\t\t\tMENU DESPLEGAR DATOS\n");
    opcionesMenu();
    printf("\nIngresar opcion-> ");
    scanf(" %d", &subMenuOpcion);
    if (subMenuOpcion < 11 && subMenuOpcion > 0)
        desplegart(tablas[subMenuOpcion - 1], con);
    setbuf(stdin, NULL); // Limpiando buffer
    getchar();
}

/* * Funcion de menu de eliminar datos.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void menuEliminar(Conexion con){
    int subMenuOpcion;
    system("clear");
    puts("\t\t\tMENU ELIMINAR DATOS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Comentarios.");
    puts("\t7.- Quejas.");
    puts("\t8.- Tarjetas.");
    puts("\t9.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf(" %d", &subMenuOpcion);
    if (subMenuOpcion < 9 && subMenuOpcion > 0)
        eliminard(subMenuOpcion, con);
    setbuf(stdin, NULL); // Limpiando buffer
    getchar();
}

/* * Funcion que despliega las opciones de menu.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void opcionesMenu(){
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Comentarios.");
    puts("\t7.- Devoluciones.");
    puts("\t8.- Cancelaciones.");
    puts("\t9.- Quejas.");
    puts("\t10.- Tarjetas.");
    puts("\t11.- Volver.");
}