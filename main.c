
/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    24/marzo/2020
 * @file:    main.c
 * @brief:  
 */
/* Archivos de inclusion */
#include <stdio.h>
#include <mysql/mysql.h>
#include "headers.h"


/* Funcion principal */
int main(){
    int opcion;
    do{
        menu();
        scanf(" %d", &opcion);
    }while(opcion != 6);
    return 0;
}

