/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    compra.c
 * @brief:  Este archivo contiene las funciones para realizar una compra.
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <string.h>
#include "conexion.h"

/* DESARROLLANDO LAS FUNCIONES */

/* * Funcion que genera el query de compra.
   * @param char* queryCompra. Recibe una cadena de texto que será ejecutada como query en la base de datos.
   * @param char* username. Recibe una cadena de texto que será el username al que le pertenecerá la compra.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void generarCompra(char* queryCompra, char *username, char *idTipoPago){
    strcat(queryCompra, idTipoPago);
    strcat(queryCompra, ", '");
    strcat(queryCompra, username);
    strcat(queryCompra, "', 0);");
}

/* * Funcion que se ejecuta cada vez que se genera un error de mysql.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void errorCatcher(Conexion *con){
    printf("Ha ocurrido un error. %s\nPresione enter para continuar...", mysql_error(&(con->mysql)));
    getchar();
}

/* * Funcion que genera el query de compra e inserta productos en la tabla intermedia.
   * @param char* queryAuxiliar. Recibe una cadena de texto que será ejecutada como query en la base de datos.
   * @param char* idCompra. Recibe una cadena de texto que será el id de compra al que le pertenecerá el producto.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void generarQueryCompra(char *queryAuxiliar, char* idCompra, char* idProducto){
    strcpy(queryAuxiliar, "INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(");
    strcat(queryAuxiliar, idCompra);
    strcat(queryAuxiliar, ", ");
    strcat(queryAuxiliar, idProducto);
    strcat(queryAuxiliar, ");");
}

/* * Funcion que pide los datos de la compra.
   * @param Conexion con. Recibe la variable de conexion de la base de datos.
*/
void realizarCompra(Conexion con){
    char username[100], idProducto[5], cantidadProductos[5], query[700], idTipoPago[5], queryCompra[700] = "INSERT INTO pr1_compras(timestamp, idTipoPago, user, status) VALUES(NOW(), ", idCompra[5], queryAuxiliar[700];
    float totalCompra = 0, totalEnvio = 0;
    system("clear");
    printf("\t\t\tREALIZANDO COMPRA\n");
    printf("Ingresar el username para realizar compra-> ");
    setbuf(stdin, NULL);
    fgets(username, 100, stdin);
    username[strlen(username) - 1] = '\0';
    printf("Ingresar el id del tipo de pago-> "); // Insertamos el id del tipo de pago
    fgets(idTipoPago, 5, stdin);
    idTipoPago[strlen(idTipoPago) - 1] = '\0';
    generarCompra(queryCompra, username, idTipoPago);
    mysql_init(&con.mysql);
    /* Conexion y ejecucion de querys */
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
    con.res = mysql_store_result(&con.mysql); //  Obtenemos el id de la compra que se ha generado
    con.row = mysql_fetch_row(con.res);
    strcat(idCompra, con.row[0]);
    do{ // Repetimos proceso de generacion de query y compra de productos hasta que el usuario escriba -1
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
        con.row = mysql_fetch_row(con.res); // Obtenemos precio de envio y del producto y lo sumamos al total
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
    mysql_free_result(con.res);
    printf("Total de la compra: %f\nTotal del envio: %f\n", totalCompra, totalEnvio); // Desplegamos el total de la compra
    getchar();
}

