#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexion.h"
void ejecutarQueryDesplegar(char *query, Conexion con){
    mysql_init(&con.mysql);
    if (!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0))
    {
        printf("Error al conectarse a la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }
    if (mysql_select_db(&con.mysql, con.db))
    {
        printf("Error al seleccionar la base de datos: %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }
    if (mysql_query(&con.mysql, query))
    {
        printf("Error al ejecutar el query %s\nPresiona enter para continuar...", mysql_error(&con.mysql));
        return;
    }
    else
    {
        printf("Se ha desplegado la tabla\nPresiona enter para continuar...");
        return;
    }
    mysql_close(&con.mysql);
}

void desplegart(char *tabla, int opcion, Conexion con){
    char query[700];
    if (opcion == 1)
    {
        puts("TABLA CLIENTES:");
        strcpy(query, "SELECT * FROM pr1_clientes");
        ejecutarQueryDesplegar(query, con);
    }

    if (opcion == 2)
    {
        puts("TABLA ASESORES:");
        strcpy(query, "SELECT * FROM pr1_asesores");
        ejecutarQueryDesplegar(query, con);
    }

    if (opcion == 3)
    {
        puts("TABLA PRODUCTOS:");
        strcpy(query, "SELECT * FROM pr1_productos");
        ejecutarQueryDesplegar(query, con);
    }

    if (opcion == 4)
    {
        puts("TABLA CATEGORIAS:");
        strcpy(query, "SELECT * FROM pr1_categorias_productos");
        ejecutarQueryDesplegar(query, con);
    }

    if (opcion == 5)
    {
        puts("TABLA DEPARTAMENTOS:");
        strcpy(query, "SELECT * FROM pr1_departamentos");
        ejecutarQueryDesplegar(query, con);
    }

    while ((con.row = mysql_fetch_row(con.res)))
    {
        for (int i = 0; i < mysql_num_fields(con.res); i++)
        {
            if (con.row[i] != NULL)
                printf("%s, ", con.row[i]);
            else
                printf("---");
        }
        printf("\n");
    }
    mysql_free_result(con.res);
    mysql_close(&con.mysql);
}