
/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    24/marzo/2020
 * @file:    main.c
 * @brief:  
 */
/* Archivos de inclusion */
#include<stdio.h>
#include<mysql/mysql.h>

/* Prototipos de funciones */
void menu();

/* Funcion principal */
int main(){
    int opcion;
    do{
        menu();
        scanf(" %d", &opcion);
    }while(opcion != 6);
    return 0;
}

/* Desarrollo de funciones */

void menu(){
    /*Texto cool*/
    system("clear");
    /*printf(" _____  _                _       \ņ");
    printf("|_   _|(_) ___  _ _   __| | __ _ \ņ");
    printf("  | |  | |/ -_)| ' \\ / _` |/ _` |\ņ");
    printf("  |_|  |_|\\___||_||_|\\__,_|\\__,_|\ņ");
    printf("\ņ");*/
     

                                  
    printf("\t1.- Altas (Clientes/Asesores/Productos/Categorias/Departamentos)\n");
    printf("\t2.- Desplegar datos (Clientes/Asesores/Productos/Categorias/Departamentos)\n");
    printf("\t3.- Actualizar datos (Clientes/Asesores/Productos/Categorias/Departamentos)\n");
    printf("\t4.- Eliminar (Clientes/Asesores/Productos/Categorias/Departamentos)\n");
    printf("\t5.- Realizar compra\n");
    printf("\t6.- Salir\n");
    printf("\nIngresar opcion-> ");
}