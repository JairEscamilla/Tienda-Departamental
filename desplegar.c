/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    desplegar.c
 * @brief:  Este archivo contiene las funciones para desplegar las tablas de la base de datos.
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexion.h"

/* DESARROLLANDO LAS FUNCIONES */

/* * Funcion que ejecuta el query de desplegar.
   * @param char* query. Recibe una cadena de texto que será ejecutada como query en la base de datos.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void ejecutarQueryDesplegar(char *query, Conexion con){
    /* Nos conectamos con la base de datos */
    mysql_init(&con.mysql);
    if (!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        printf("Error al conectarse a la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if (mysql_select_db(&con.mysql, con.db)){
        printf("Error al seleccionar la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if (mysql_query(&con.mysql, query)){
        printf("Error al ejecutar el query %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if(!(con.res = mysql_store_result(&con.mysql))){
        printf("Ha ocurrido un error al obtener el query: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        getchar();
        return;
    }
    /* Obtenemos y desplegamos los datos obtenidos de la base de datos */ 
    while ((con.row = mysql_fetch_row(con.res))){
        printf("\t");
        for (int i = 0; i < mysql_num_fields(con.res); i++){
            if (con.row[i] != NULL)
                printf("%s, ", con.row[i]);
            else
                    printf("---");
            }
            printf("\n");
        }
        printf("Se ha desplegado la tabla\nPresiona enter para continuar...");
        return;
    mysql_free_result(con.res);
    mysql_close(&con.mysql);
}

/* * Funcion que genera el query para desplegar datos.
   * @param char* tabla. Recibe una cadena de texto que será el nombre de la tabla de donde obtendremos los datos.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void desplegart(char *tabla, Conexion con){
    char query[800] = "SELECT * FROM ";
    strcat(query, tabla);
    strcat(query, ";");
    puts("Desplegando tabla: ");
    ejecutarQueryDesplegar(query, con);
}