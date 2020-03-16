#include <stdio.h>
#include <string.h>
#include "conexion.h"

void realizarCompra(Conexion con){
    char username[100], idProducto[5], cantidadProductos[5], query[700];
    system("clear");
    printf("\t\t\tREALIZANDO COMRA\n");
    printf("Ingresar el username para realizar compra-> ");
    setbuf(stdin, NULL);
    fgets(username, 100, stdin);
    username[strlen(username) - 1] = '\0';
    do{
        strcpy(query, "CALL hacer_compra(");
        strcat(query, username);
        strcat(query, ", ");
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
        puts(query);
    } while (strcmp(idProducto, "-1"));
    
    getchar();
}