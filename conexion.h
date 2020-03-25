/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    conexion.h
 * @brief:  Este archivo contiene la estructura para la conexion con mysql
 */
/* Archivos de inclusion */
#include <mysql/mysql.h>
/* Desarrollando estructura de conexion */
typedef struct defConexion{
    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char server[15];
    char user[15];
    char password[15];
    char db[15];
} Conexion;