
/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    24/marzo/2020
 * @file:    main.c
 * @brief:  
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <string.h>
#include "headers.h"

/* Funcion principal */
int main(){
    Conexion con;
    strcpy(con.server, "localhost");
    strcpy(con.user, "root");
    strcpy(con.password, "#Password123");
    strcpy(con.db, "practica1");
    void (*funcionesMenu[5])(Conexion con) = {menuAltas, NULL, menuActualizaciones};
    int opcion;
    do{
        menu();
        scanf(" %d", &opcion);
        if(opcion >= 1 && opcion < 6)
            funcionesMenu[opcion - 1](con);
        if(opcion == 6)
            puts("Saliendo... ");
    }while(opcion != 6);
    return 0;
}

 