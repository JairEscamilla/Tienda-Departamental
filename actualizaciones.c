#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexion.h"

void ejecutarQueryActualizacion(char *query, Conexion con){
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
    }
    else{
        printf("Se han actualizado los datos\nPresiona enter para continuar...");
        return;
    }
    mysql_close(&con.mysql);
}

void actualizar(char *tabla, int opcion, Conexion con){
    int numberOfFields[11] = {11, 4, 6, 4, 2, 2, 4, 3, 3, 4}, numeroCampo;
    char identificador[10], query[500] = "UPDATE ", valorNuevo[100];
    char campos[10][11][150] = {
        {"username", "password", "direccionEnvio", "idCategoria", "nombre", "apPaterno", "apMaterno", "fechaNac", "direccionFacturacion", "RFC", "codigoPostal"},
        {"idAsesor", "nombre", "apMaterno", "apPaterno"},
        {"idProducto", "nombreProducto", "descripcion", "precio", "stock", "costoEnvio"},
        {"idCategoriaP", "nombreCategoria", "descripcionCategoria", "idDepartamento"},
        {"idDepartamento", "nombreDepartamento"},
        {"idComentario", "comentario"},
        {"idDevolucion", "idCompra", "idProductoDevuelto", "comentarioDevolucion"},
        {"idCancelacion", "comentarioCancelacion", "idCompra"},
        {"idQueja",  "comentario", "status"},
        {"idTarjeta", "numeroTarjeta", "fechaVencimiento", "username"}
    };
    system("clear");
    puts("\t\t\tMENU DE CAMPOS A EDITAR");
    for(int i = 1; i < numberOfFields[opcion -1]; i++)
        printf("\t%d.- %s\n", i, campos[opcion - 1][i]);
    printf("\nSeleccione el campo que desea editar-> ");
    scanf("%d", &numeroCampo);
    if(numeroCampo < 1 || numeroCampo > numberOfFields[opcion - 1])
        return;
    setbuf(stdin, NULL);
    printf("Ingresar el %s que desea editar-> ", campos[opcion - 1][0]);
    fgets(identificador, 10, stdin);
    identificador[strlen(identificador) - 1] = '\0';
    if(opcion == 1 && numeroCampo == 7 )
        printf("Ingresar la fecha en el formato AAAA-MM-DD-> ");
    else 
        printf("Ingresar el nuevo valor para este campo-> ");
    fgets(valorNuevo, 100, stdin);
    valorNuevo[strlen(valorNuevo) - 1] = '\0';
    strcat(query, tabla);
    strcat(query, " SET ");
    strcat(query, campos[opcion - 1][numeroCampo]);
    strcat(query, " = '");
    strcat(query, valorNuevo);
    strcat(query, "' WHERE ");
    strcat(query, campos[opcion - 1][0]);
    strcat(query, " = '");
    strcat(query, identificador);
    strcat(query, "';");
    ejecutarQueryActualizacion(query, con);
}

