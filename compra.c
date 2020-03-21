#include <stdio.h>
#include <string.h>
#include "conexion.h"

void generarCompra(char* queryCompra, char *username, char *idTipoPago){
    strcat(queryCompra, idTipoPago);
    strcat(queryCompra, ", '");
    strcat(queryCompra, username);
    strcat(queryCompra, "', 0);");
}

void errorCatcher(Conexion *con){
    printf("Ha ocurrido un error. %s\nPresione enter para continuar...", mysql_error(&(con->mysql)));
    getchar();
}

void generarQueryCompra(char *queryAuxiliar, char* idCompra, char* idProducto){
    strcpy(queryAuxiliar, "INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(");
    strcat(queryAuxiliar, idCompra);
    strcat(queryAuxiliar, ", ");
    strcat(queryAuxiliar, idProducto);
    strcat(queryAuxiliar, ");");
}

void realizarCompra(Conexion con){
    char username[100], idProducto[5], cantidadProductos[5], query[700], idTipoPago[5], queryCompra[700] = "INSERT INTO pr1_compras(timestamp, idTipoPago, user, status) VALUES(NOW(), ", idCompra[5], queryAuxiliar[700];
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
        errorCatcher(&con);
        return;
    }
    if (mysql_select_db(&con.mysql, con.db)){ // Se conecta a la base de datos
        errorCatcher(&con);
        return;
    }
    if (mysql_query(&con.mysql, queryCompra) || mysql_query(&con.mysql, "SELECT idCompra FROM pr1_compras ORDER BY idCompra DESC LIMIT 1;")){
        errorCatcher(&con);
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
        if (mysql_query(&con.mysql, query)){
            errorCatcher(&con);
            return;
        }
        if (!(con.res = mysql_store_result(&con.mysql))){
            errorCatcher(&con);
            return;
        }
        con.row = mysql_fetch_row(con.res);
        if(con.row != NULL && con.row[2] != NULL && con.row[4] != NULL){
            totalCompra += atof(con.row[2]);
            totalEnvio += atof(con.row[4]);
        }
        generarQueryCompra(queryAuxiliar, idCompra, idProducto);
        if(mysql_query(&con.mysql, queryAuxiliar)){
            errorCatcher(&con);
            return;
        }
    } while (strcmp(idProducto, "-1"));
    sprintf(query, "UPDATE pr1_compras SET totalPagar = %f WHERE idCompra = %s;", totalCompra + totalEnvio, idCompra);
    if (mysql_query(&con.mysql, query)){
        errorCatcher(&con);
        return;
    }
    printf("Total de la compra: %f\nTotal del envio: %f\n", totalCompra, totalEnvio);
    getchar();
}

