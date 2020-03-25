/*
 * @author:  Allan Jair Escamilla Hernández, María Gabriela Uribe 
 * @date:    27/marzo/2020
 * @file:    headers.h
 * @brief:  Este archivo contiene las los encabezados de las funciones.
 */
/* Archivos de inclusion */
#include "conexion.h"
/* Prototipos de las funciones */
void menu();
void menuAltas(Conexion con);
void insertarClientes(Conexion con);
void completarQuery(char datos[13][100], char query[]);
void insertarDatos(char campos[7][150], int numberFields, char* tabla, char camposDB[7][150], Conexion con);
void llenarCampos(char camposBD[7][150], int numberFields, char datos[7][150], char* query);
void menuActualizaciones(Conexion con);
void actualizar(char* tabla, int opcion, Conexion con);
void ejecutarQueryActualizacion(char* query, Conexion con);
void realizarCompra(Conexion con);
void generarCompra(char* queryCompra, char *username, char *idTipoPago);
void generarQueryCompra(char *queryAuxiliar, char *idCompra, char *idProducto);
void menuDesplegar(Conexion con);
void ejecutarQueryDesplegar(char *query, Conexion con);
void desplegart(char *tabla, Conexion con);
void errorCatcher(Conexion* con);

void menuEliminar(Conexion con);
void ejecutarQueryEliminar(char *query, Conexion con);
void eliminard(int opcion, Conexion con);
void opcionesMenu();