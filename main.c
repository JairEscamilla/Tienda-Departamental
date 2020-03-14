
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
    int opcion, opcionSubMenu;
    do{
        menu();
        scanf(" %d", &opcion);
        if(opcion == 1){
            menuAltas();
            scanf(" %d", &opcionSubMenu);
            if(opcionSubMenu == 1)
                insertarClientes(con);
        }
    }while(opcion != 6);
    return 0;
}
