/* Archivos de inclusion */
#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "headers.h"

/* Desarrollando funciones */

/* Funcione que inserta clientes */
void insertarClientes(Conexion con){
    char query[800] = "INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, direccionFacturacion, RFC, codigoPostal, fechaNac) VALUES(";
    char campos[13][100] = {"username", "password", "direccion de envio", "id de categoria de cliente", "nombre", "apellido paterno", "apellido materno", "dia de nacimiento", "mes de nacimiento", "anio de nacimiento", "direccion de facturacion", "RFC", "codigo postal"};
    char datos[13][100];
    mysql_init(&con.mysql);
    if(!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        fprintf(stderr, "Ha ocurrido un error al conectarse a la base de datos: %s\n", mysql_error(&con.mysql));
        getchar();
        return;
    }
    if(mysql_select_db(&con.mysql, con.db)){
        fprintf(stderr, "Ha ocurrido un error al conectarse a la base de datos %s\n", mysql_error(&con.mysql));
        getchar();
        return;
    }
    system("clear");
    puts("\t\t\tINSERTANDO DATOS\n");
    setbuf(stdin, NULL);
    for(int i = 0; i < 13; i++){
        printf("Insertar %s-> ", campos[i]);
        fgets(datos[i], 100, stdin);
        datos[i][strlen(datos[i]) - 1] = '\0';
    }
    completarQuery(datos, query);
    // Ejecutamos el query
    if (mysql_query(&con.mysql, query)){
        fprintf(stderr, "Alguno de los datos ingresados son incorrectos: %s", mysql_error(&con.mysql));
        getchar(); 
        return;
    }
    mysql_close(&con.mysql);
    printf("Se ha insertado correctamente el cliente\nPresione enter para continuar... ");
    getchar();
}

void completarQuery(char datos[13][100], char query[]){
    char fechaNacimiento[20];
    strcpy(fechaNacimiento, datos[9]);
    strcat(fechaNacimiento, "-");
    strcat(fechaNacimiento, datos[8]);
    strcat(fechaNacimiento, "-");
    strcat(fechaNacimiento, datos[7]);
    for(int i = 0; i < 13; i++){
       if(i != 7 && i != 8 && i != 9){
           if(i != 3){
                strcat(query, "'");
                strcat(query, datos[i]);
                strcat(query, "'");
           }else  
                strcat(query, datos[i]);
            strcat(query, ", ");
       }
    }
    strcat(query, "'");
    strcat(query, fechaNacimiento);
    strcat(query, "'");
    strcat(query, ");");
}

void insertarDatos(char campos[7][150], int numberFields, char* tabla, char camposDB[7][150], Conexion con){
    char datos[7][150];
    char query[700] = "INSERT INTO ";
    system("clear");
    setbuf(stdin, NULL);
    strcat(query, tabla);
    puts("\t\t\tINSERTANDO DATOS\n");
    for(int i = 0; i < numberFields; i++){
        printf("Insertar %s-> ", campos[i]);
        fgets(datos[i], 150, stdin);
        datos[i][strlen(datos[i]) - 1] = '\0';
    }
    llenarCampos(camposDB, numberFields, datos, query);
    mysql_init(&con.mysql); // Inicializando mysql
    // Nos conectamos a la base de datos
    if(!mysql_real_connect(&con.mysql, con.server, con.user, con.password, con.db, 0, NULL, 0)){
        fprintf(stderr, "Ha ocurrido un error al conectarse a la base de datos: %s\nPresione enter para continuar... ", mysql_error(&con.mysql));
        getchar();
        return;
    }
    // Seleccionamos la base de datos
    if(mysql_select_db(&con.mysql, con.db)){
        fprintf(stderr, "Ha ocurrido un error al conectarse a la base de datos: %s\nPresione enter para continuar... ", mysql_error(&con.mysql));
        getchar();
        return;
    }
    // Ejecutamos el query
    if(mysql_query(&con.mysql, query)){
        fprintf(stderr, "Ha ocurrido un error al insertar los datos: %s\nPresione enter para continuar... ", mysql_error(&con.mysql));
        getchar();
        return;
    }else
        printf("Se ha insertado con exito la informacion ingresada\nPresione enter para continuar...");
    getchar();
}

void llenarCampos(char camposBD[7][150], int numberFields, char datos[7][150], char* query){
    strcat(query, "(");
    for(int i = 0; i < numberFields; i++){
        strcat(query, camposBD[i]);
        if(i != numberFields - 1)
            strcat(query, ", ");
    }
    strcat(query, ") VALUES (");
    for(int i = 0; i < numberFields; i++){
        strcat(query, "'");
        strcat(query, datos[i]);
        strcat(query, "'");
        if(i != numberFields - 1)
            strcat(query, ", ");
    }
    strcat(query, ");");
}