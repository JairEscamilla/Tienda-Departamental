#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexion.h"

void ejecutarQueryDesplegar(char *query, Conexion con){
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

void desplegart(char *tabla, int opcion, Conexion con){
    char query[800] = "SELECT * FROM ";
    strcat(query, tabla);
    strcat(query, ";");
    puts("Desplegando tabla: ");
    ejecutarQueryDesplegar(query, con);
}