#include <stdio.h>
#include <string.h>
#include "conexion.h"

void generarCompra(char* queryCompra, char *username, char *idTipoPago){
    strcat(queryCompra, idTipoPago);
    strcat(queryCompra, ", '");
    strcat(queryCompra, username);
    strcat(queryCompra, "', 0);");
}

void realizarCompra(Conexion con){
    char username[100], idProducto[5], cantidadProductos[5], query[700], idTipoPago[5], queryCompra[700] = "INSERT INTO pr1_compras(timestamp, idTipoPago, user, status) VALUES(NOW(), ", idCompra[5];
    float totalCompra = 0, totalEnvio = 0;
    system("clear");
    printf("\t\t\tREALIZANDO COMPRA\n");
    printf("Ingresar el username para realizar compra-> ");
    setbuf(stdin, NULL);
    fgets(username, 100, stdin);
    username[strlen(username) - 1] = '\0';
    printf("Ingresar el id del tipo de pago-> ");
    fgets(idTipoPago, 5, stdin);
    idTipoPago[strlen(idTipoPago) - 1] = '\0';
    generarCompra(queryCompra, username, idTipoPago);
    mysql_init(&con.mysql);
    if (!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        printf("Error al conectarse: %s\n", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if (mysql_select_db(&con.mysql, con.db)){ // Se conecta a la base de datos
        printf("Error al seleccionar la base de datos: %s", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if (mysql_query(&con.mysql, queryCompra) || mysql_query(&con.mysql, "SELECT idCompra FROM pr1_compras ORDER BY idCompra DESC LIMIT 1;")){
        printf("Error, no se ha podido generar la compra %s\n", mysql_error(&con.mysql));
        getchar();
        return;
    }
    con.res = mysql_store_result(&con.mysql);
    con.row = mysql_fetch_row(con.res);
    strcat(idCompra, con.row[0]);
    do{
        strcpy(query, "SELECT idProducto, nombreProducto, precio, stock, costoEnvio FROM pr1_productos WHERE idProducto = ");
        printf("Ingresar idProducto(-1 para terminar compra)-> ");
        fgets(idProducto, 5, stdin);
        idProducto[strlen(idProducto) - 1] = '\0';
        if (!strcmp(idProducto, "-1"))
            break;
        strcat(query, idProducto);
        strcat(query, ";");
        printf("Ingresar cantidad de productos-> ");
        fgets(cantidadProductos, 5, stdin);
        cantidadProductos[strlen(cantidadProductos) - 1] = '\0';
        if (mysql_query(&con.mysql, query)){
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
        if(cantidadProductos > con.row[3]){
            printf("No se puede realizar la compra debido a que no hay productos suficientes en stock):\nPresiona enter para continuar... ");
            getchar();
            return;
        }
        if(con.row[0] != NULL && con.row[1] != NULL){
            totalCompra += atof(con.row[0]);
            totalEnvio += atof(con.row[1]);
        }
    } while (strcmp(idProducto, "-1"));
    
    printf("Total de la compra: %f\nTotal del envio: %f\n", totalCompra, totalEnvio);
    getchar();
}

