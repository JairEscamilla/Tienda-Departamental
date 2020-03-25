/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    main.c
 * @brief:  Este archivo contiene el menu principal con las funciones segun lo seleccionado por el usuario
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <string.h>
#include "headers.h"

/* Funcion principal */
int main(){
    Conexion con; // Creamos variable para la conexion
    int opcion; // Variable de opcion
    /* Copiamos los datos de ingresoa la variable de conexion */
    strcpy(con.server, "localhost");
    strcpy(con.user, "root");
    strcpy(con.password, "#Password123");
    strcpy(con.db, "practica1");
    void (*funcionesMenu[5])(Conexion con) = {menuAltas, menuDesplegar, menuActualizaciones, menuEliminar, realizarCompra}; // Arreglo de apuntadores a funciones que contiene las funciones del menú principal
    do{
        /* Desplegamos menú, leemos opcion y mandamos a llamar a la opcion seleccionada */
        menu();
        scanf(" %d", &opcion);
        if(opcion >= 1 && opcion < 6)
            funcionesMenu[opcion - 1](con);
        if(opcion == 6)
            puts("Saliendo... ");
    }while(opcion != 6);
    return 0;
}

 