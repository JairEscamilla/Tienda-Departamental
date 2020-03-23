/* Archivos de inclusion */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "headers.h"
/* Desarrollo de funciones */
/* Menu principal */
void menu(){
    system("clear");
    puts("\t\t\tMENÚ\n");
    puts("\t1.- Altas (Clientes/Asesores/Productos/Categorias/Departamentos/Comentarios/Devoluciones.)");
    puts("\t2.- Desplegar datos (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t3.- Actualizar datos (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t4.- Eliminar (Clientes/Asesores/Productos/Categorias/Departamentos).");
    puts("\t5.- Realizar compra.");
    puts("\t6.- Salir.");
    printf("\nIngresar opcion-> ");
}

/* Menu de altas */
void menuAltas(Conexion con){
    int opcionSubMenu;
    char campos[8][7][150] = {
        {"nombre del asesor", "apellido materno", "apellido paterno"},
        {"nombre del producto", "descripcion", "precio", "stock", "costo de envio"},
        {"nombre de la categoria", "descripcion de la categoria", "id del departamento al que pertenece"},
        {"nombre del departamento"},
        {"username", "idProducto", "comentario"},
        {"id de compra", "id de producto a devolver", "comentario de devolucion"},
        {"comentario de cancelacion", "id de la compra"},
        {"username", "id del asesor", "comentario", "status 1/0"}
    };
    char camposDB[8][7][150] = {
        {"nombre", "apPaterno", "apMaterno"},
        {"nombreProducto", "descripcion", "precio", "stock", "costoEnvio"},
        {"nombreCategoria", "descripcionCategoria", "idDepartamento"},
        {"nombreDepartamento"},
        {"pr1_clientes_username", "pr1_productos_idProducto", "comentario"},
        {"idCompra", "idProductoDevuelto", "comentarioDevolucion"},
        {"comentarioCancelacion", "idCompra"},
        {"pr1_clientes_username", "pr1_asesores_idAsesor", "comentario", "status"}
    };
    char nombresTablas[9][100] = {"pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos", "pr1_comentarios", "pr1_devoluciones", "pr1_cancelacion", "pr1_quejas"};
    int numeroCampos[8] = {3, 5, 3, 1, 3, 3, 2, 4};
    system("clear");
    puts("\t\t\tMENÚ ALTAS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Comentarios.");
    puts("\t7.- Devoluciones.");
    puts("\t8.- Cancelaciones.");
    puts("\t9.- Quejas.");
    puts("\t10.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf(" %d", &opcionSubMenu);
    if (opcionSubMenu == 1)
        insertarClientes(con);
    else if (opcionSubMenu >= 2 && opcionSubMenu <= 9)
        insertarDatos(campos[opcionSubMenu - 2], numeroCampos[opcionSubMenu - 2], nombresTablas[opcionSubMenu - 2], camposDB[opcionSubMenu - 2], con);
}

void menuActualizaciones(Conexion con){
    int subMenuOpcion;
    char tablas[5][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos"};
    system("clear");
    setbuf(stdin, NULL); // Limpiando buffer
    puts("\t\t\tMENU ACTUALIZACIONES\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf("%d", &subMenuOpcion);
    if(subMenuOpcion < 6 && subMenuOpcion > 0)
        actualizar(tablas[subMenuOpcion-1], subMenuOpcion, con);
    getchar();
}

/* Menu desplegar datos */
void menuDesplegar(Conexion con){
    int subMenuOpcion;
    char tablas[5][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos"};
    system("clear");
    puts("\t\t\tMENU DESPLEGAR DATOS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf(" %d", &subMenuOpcion);
    if (subMenuOpcion < 6 && subMenuOpcion > 0)
        desplegart(tablas[subMenuOpcion - 1], subMenuOpcion, con);
    setbuf(stdin, NULL); // Limpiando buffer
    getchar();
}

/* Menu eliminar datos */
void menuEliminar(Conexion con){
    int subMenuOpcion;
    char tablas[5][100] = {"pr1_clientes", "pr1_asesores", "pr1_productos", "pr1_categorias_productos", "pr1_departamentos"};
    system("clear");
    puts("\t\t\tMENU ELIMINAR DATOS\n");
    puts("\t1.- Clientes.");
    puts("\t2.- Asesores.");
    puts("\t3.- Productos.");
    puts("\t4.- Categorias.");
    puts("\t5.- Departamentos.");
    puts("\t6.- Volver.");
    printf("\nIngresar opcion-> ");
    scanf(" %d", &subMenuOpcion);
    if (subMenuOpcion < 6 && subMenuOpcion > 0)
        eliminard(tablas[subMenuOpcion - 1], subMenuOpcion, con);
    setbuf(stdin, NULL); // Limpiando buffer
    getchar();
}