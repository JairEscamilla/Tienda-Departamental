/* Archivos de inclusion */
#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "headers.h"

/* Desarrollando funciones */

/* Funcione que inserta clientes */
void insertarClientes(Conexion con){
    char usr[30], pwd[30], direccionEnvio[70], idCategoria[4], nombre[50], apPaterno[50], apMaterno[50];
    char diaNac[3], mesNac[3], anioNac[3], dirFact[70], rfc[16], cp[50];
    system("clear");
    mysql_init(&con.mysql);
    if(!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        fprintf(stderr, "Ha ocurrido un error al conectarse a la base de datos: %s\n", mysql_error(&(con.mysql)));
        return;
    }
    puts("\t\t\tINSERTANDO CLIENTES\n");
    /* Leyendo datos del usuario */
    printf("Ingresar username-> ");
    fgets(usr, 30, stdin);
    fgets(usr, 30, stdin);
    usr[strlen(usr) - 1] = '\0';
    printf("Ingresar password-> ");
    fgets(pwd, 30, stdin);
    pwd[strlen(pwd) - 1] = '\0';
    printf("Ingresar direccion de envio-> ");
    fgets(direccionEnvio, 70, stdin);
    direccionEnvio[strlen(direccionEnvio) - 1] = '\0';
    printf("Ingresar el id de la categoria del cliente-> ");
    fgets(idCategoria, 4, stdin);
    idCategoria[strlen(idCategoria) - 1] = '\0';
    printf("Ingresar el nombre del cliente-> ");
    fgets(nombre, 50, stdin);
    nombre[strlen(nombre) - 1] = '\0';
    printf("Ingresar el apellido paterno del cliente-> ");
    fgets(apPaterno, 50, stdin);
    apPaterno[strlen(apPaterno) - 1] = '\0';
    printf("Ingresar el apellido materno del cliente-> ");
    fgets(apMaterno, 50, stdin);
    apMaterno[strlen(apMaterno) - 1] = '\0';
    printf("Ingresar el dia de nacimiento del cliente-> ");
    fgets(diaNac, 50, stdin);
    diaNac[strlen(diaNac) - 1] = '\0';
    printf("Ingresar el mes de nacimiento del cliente-> ");
    fgets(mesNac, 50, stdin);
    mesNac[strlen(mesNac) - 1] = '\0';
    printf("Ingresar el anio de nacimiento del cliente-> ");
    fgets(anioNac, 50, stdin);
    anioNac[strlen(anioNac) - 1] = '\0';
    printf("Ingresar la direccion de facturacion-> ");
    fgets(dirFact, 50, stdin);
    dirFact[strlen(dirFact) - 1] = '\0';
    printf("Ingresar el RFC-> ");
    fgets(rfc, 50, stdin);
    rfc[strlen(rfc) - 1] = '\0';
    printf("Ingresar el codigo postal-> ");
    fgets(cp, 50, stdin);
    cp[strlen(cp) - 1] = '\0';

    mysql_close(&con.mysql);
}