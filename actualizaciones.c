#include <stdio.h>
#include <stdlib.h>
void actualizar(char *tabla, int opcion){
    int numberOfFields, numeroCampo;
    if(opcion == 1)
        numberOfFields = 11;
    if(opcion == 2)
        numberOfFields = 4;
    if(opcion == 3)
        numberOfFields = 6;
    if(opcion == 4)
        numberOfFields = 4;
    if(opcion == 5)
        numberOfFields = 2;
    char campos[5][11][150] = {
        {"username", "password", "direccionEnvio", "idCategoria", "nombre", "apPaterno", "apMaterno", "fechaNac", "direccionFacturacion", "RFC", "codigoPostal"},
        {"idAsesor", "nombre", "apMaterno", "apPaterno"},
        {"idProducto", "nombreProducto", "descripcion", "precio", "stock", "costoEnvio"},
        {"idCategoriaP", "nombreCategoria", "descripcionCategoria", "idDepartamento"},
        {"idDepartamento", "nombreDepartamento"}
    };
    setbuf(stdin, NULL);
    system("clear");
    puts("\t\t\tMENU DE CAMPOS A EDITAR");
    for(int i = 1; i < numberOfFields; i++)
        printf("\t%d.- %s\n", i, campos[opcion - 1][i]);
    printf("\nSeleccione el campo que desea editar-> ");
    scanf("%d", &numeroCampo);
    if(numeroCampo < 1 || numeroCampo > numberOfFields)
        return;
    
    getchar();
}