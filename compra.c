#include <stdio.h>
#include <string.h>
#include "conexion.h"

void realizarCompra(Conexion con){
    char username[100], idProducto[5], cantidadProductos[5], query[700];
    float totalCompra = 0, totalEnvio = 0;
    system("clear");
    printf("\t\t\tREALIZANDO COMRA\n");
    printf("Ingresar el username para realizar compra-> ");
    setbuf(stdin, NULL);
    fgets(username, 100, stdin);
    username[strlen(username) - 1] = '\0';
    mysql_init(&con.mysql);
    if (!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        printf("Error al conectarse: %s\n", mysql_error(&con.mysql));
        return;
    }
    // Se conecta a la base de datos
    if (mysql_select_db(&con.mysql, con.db)){
        printf("Error al seleccionar la base de datos: %s", mysql_error(&con.mysql));
        return;
    }
    do{
        strcpy(query, "CALL hacerCompra(");
        strcat(query, "'");
        strcat(query, username);
        strcat(query, "', ");
        printf("Ingresar idProducto(-1 para terminar compra)-> ");
        fgets(idProducto, 5, stdin);
        idProducto[strlen(idProducto) - 1] = '\0';
        if (!strcmp(idProducto, "-1"))
            break;
        printf("Ingresar cantidad de productos-> ");
        fgets(cantidadProductos, 5, stdin);
        cantidadProductos[strlen(cantidadProductos) - 1] = '\0';
        strcat(query, idProducto);
        strcat(query, ", ");
        strcat(query, cantidadProductos);
        strcat(query, ", @totalVenta, @pagoEnvio);");
        if (mysql_query(&con.mysql, query)){
            printf("Error al ejecutar el query %s\n", mysql_error(&con.mysql));
            getchar();
            return;
        }
        if (mysql_query(&con.mysql, "SELECT @totalVenta, @pagoEnvio;")){
            printf("Error al ejecutar el query %s\n", mysql_error(&con.mysql));
            getchar();
            return;
        }
        if (!(con.res = mysql_store_result(&con.mysql))){
            printf("Error al obtener el query: %s\n", mysql_error(&con.mysql));
            getchar();
            return;
        }
        con.row = mysql_fetch_row(con.res);
        if(con.row[0] != NULL && con.row[1] != NULL){
            totalCompra += atof(con.row[0]);
            totalEnvio += atof(con.row[1]);
        }
    } while (strcmp(idProducto, "-1"));
    
    printf("Total de la compra: %f\nTotal del envio: %f\n", totalCompra, totalEnvio);
    getchar();
}