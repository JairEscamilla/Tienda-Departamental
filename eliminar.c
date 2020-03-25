/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    eliminar.c
 * @brief:  Este archivo contiene las funciones necesarias para eliminar informacion de la base de datos
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexion.h"
/* DESARROLLANDO LAS FUNCIONES */

/* * Funcion que ejecuta el query para eliminar datos.
   * @param char* query. Recibe una cadena de texto que será ejecutada como query en la base de datos.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void ejecutarQueryEliminar(char *query, Conexion con){
    /* Conexion y ejecucion del query en la base de datos */
    mysql_init(&con.mysql);
    if (!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        printf("Error al conectarse a la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }
    if (mysql_select_db(&con.mysql, con.db)){
        printf("Error al seleccionar la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }
    if (mysql_query(&con.mysql, query)){
        printf("Error al ejecutar el query %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }else{
        printf("Se han eliminado los datos\nPresiona enter para continuar...");
        return;
    }
    mysql_close(&con.mysql);
}

/* * Funcion que pide datos de la informacion que se desea eliminar.
   * @param int opcion. Recibe la opcion seleccionada por el usuario,
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void eliminard(int opcion, Conexion con){
    char usern[30], idA[3], idP[3], idC[3], idD[3];
    char query[150];
    if(opcion == 1){
        puts("Insertar el username del Cliente que desea eliminar: ");
        scanf (" %[^\n]",usern);
        sprintf(query,"DELETE FROM pr1_clientes WHERE username = '%s'", usern);
        ejecutarQueryEliminar(query, con);
    }

    if(opcion == 2){
        puts("Insertar el id de Asesor que desea eliminar: ");
        scanf (" %[^\n]",idA);
        sprintf(query,"DELETE FROM pr1_asesores WHERE idAsesor = '%s'", idA);
        ejecutarQueryEliminar(query, con);
    }

    if(opcion == 3){
        puts("Insertar el id del producto que desea eliminar: ");
        scanf (" %[^\n]",idP);
        sprintf(query,"DELETE FROM pr1_productos WHERE idProducto = '%s'", idP);
        ejecutarQueryEliminar(query, con);
    }

    if(opcion == 4){
        puts("Insertar el id de categoria que desea eliminar: ");
        scanf (" %[^\n]",idC);
        sprintf(query,"DELETE FROM pr1_categorias_productos WHERE idCategoriap = '%s'", idC);
        ejecutarQueryEliminar(query, con);
    }

    if(opcion == 5){
        puts("Insertar el id de departamento que desea eliminar: ");
        scanf (" %[^\n]",idD);
        sprintf(query,"DELETE FROM pr1_departamentos WHERE idDepartamento = '%s'", idD);
        ejecutarQueryEliminar(query, con);
    }
    if(opcion == 6){
        puts("Insertar el id de comentario que desea eliminar: ");
        scanf (" %[^\n]", idD);
        sprintf(query,"DELETE FROM pr1_comentarios WHERE idComentario = '%s'", idD);
        ejecutarQueryEliminar(query, con);
    }
    if(opcion == 7){
        puts("Insertar el id de queja que desea eliminar: ");
        scanf (" %[^\n]", idD);
        sprintf(query,"DELETE FROM pr1_quejas WHERE idQueja = '%s'", idD);
        ejecutarQueryEliminar(query, con);
    }
    if(opcion == 8){
        puts("Insertar el id de tarjeta que desea eliminar: ");
        scanf (" %[^\n]", idD);
        sprintf(query,"DELETE FROM pr1_tarjetas WHERE idTarjeta = '%s'", idD);
        ejecutarQueryEliminar(query, con);
    }
}
