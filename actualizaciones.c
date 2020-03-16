#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void actualizar(char *tabla, int opcion){
    int numberOfFields, numeroCampo;
    char identificador[10], query[500] = "UPDATE ", valorNuevo[100];
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
    system("clear");
    puts("\t\t\tMENU DE CAMPOS A EDITAR");
    for(int i = 1; i < numberOfFields; i++)
        printf("\t%d.- %s\n", i, campos[opcion - 1][i]);
    printf("\nSeleccione el campo que desea editar-> ");
    scanf("%d", &numeroCampo);
    if(numeroCampo < 1 || numeroCampo > numberOfFields)
        return;
    setbuf(stdin, NULL);
    printf("Ingresar el %s que desea editar-> ", campos[opcion - 1][0]);
    fgets(identificador, 10, stdin);
    identificador[strlen(identificador) - 1] = '\0';
    if(opcion == 1 && numeroCampo == 7 )
        printf("Ingresar la fecha en el formato AAAA-MM-DD-> ");
    else 
        printf("Ingresar el nuevo valor para este campo-> ");
    fgets(valorNuevo, 100, stdin);
    valorNuevo[strlen(valorNuevo) - 1] = '\0';
    strcat(query, tabla);
    strcat(query, " SET ");
    strcat(query, campos[opcion - 1][numeroCampo]);
    strcat(query, " = '");
    strcat(query, valorNuevo);
    strcat(query, "' WHERE ");
    strcat(query, campos[opcion - 1][0]);
    strcat(query, " = '");
    strcat(query, identificador);
    strcat(query, "';");
    puts(query);
    getchar();
}