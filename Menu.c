//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Menu

#include "Menu.h"

void menuCuentas(void){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU CUENTAS\n");
        printf("\n\t\t[1]. Listado\n");
        printf("\t\t[2]. Agregar producto a cuenta\n");
        printf("\t\t[3]. Quitar producto a cuenta\n");
        printf("\t\t[4]. Cerrar cuenta\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                //mostrarProducto();
                break;

            case 2:
                //mostrarProductoTipo();
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}



void menunodoClienteoProductos(void){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU nodoClienteO PRODUCTOS\n");
        printf("\n\t\t[1]. Por Producto\n");
        printf("\t\t[2]. Por tipo\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                //mostrarProducto();
                break;

            case 2:
                //mostrarProductoTipo();
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuProductos(nodoProd * * listaProductos){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        mostrarArchivoYFilaProd(aProductos,*listaProductos);
        tituloPrincipal();
        printf("\n\t\t\t\tSUBMENU PRODUCTOS\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. \n");
        printf("\t\t[4]. \n");
        printf("\t\t[5]. \n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaProducto(aProductos,listaProductos);
                //altaProducto();
                break;

            case 2:
                bajaProducto(listaProductos,aProductos);
                //bajaProducto();
                break;
            case 3:
                //modificacionProducto();
                break;

            case 4:
                //menunodoClienteoProductos();
                break;

            case 5:
                //ventaBarra();
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}




void menuMesas(nodoMesa * * listaMesas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        mostrarArchivoYFilaMesa(aMesas,*listaMesas);
        tituloPrincipal();
        printf("\n\t\t\t\tSUBMENU MESAS\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. \n");
        printf("\t\t[4]. \n");
        printf("\t\t[5]. \n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaMesa(aMesas,listaMesas);
                break;

            case 2:
                bajaMesa(listaMesas,aMesas);
                break;

            case 3:
                break;

            case 4:
                //modificarMesa();//agregar y sacar productos al array Productos en el struct Mesa
                break;

            case 5:
                //cerrarMesa();
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}
/*
void menunodoClienteoClientes(void){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU nodoClienteO CLIENTES\n");
        printf("\n\t\t[1]. Todos\n");
        printf("\t\t[2]. Atendidos\n");
        printf("\t\t[3]. En espera\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                //mostrarTodosClientes
                break;

            case 2:
                //mostrarClientesAtendidos
                break;

            case 3:
                //mostrarClientesEspera
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}
*/
void menuClientes(void){
    char repite = 1;
    int opcion = -1;
    //Cliente aux;

    do {
        system("cls");
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU CLIENTES\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Atención\n");
        printf("\t\t[3]. Baja\n");
        printf("\t\t[4]. nodoClienteo\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                //aux=altaCliente();
                break;

            case 2:
                //atencionCliente
                break;

            case 3:
                //bajaCliente
                break;

            case 4:
               // menunodoClienteoClientes();
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuPrincipal(void){ ///MAIN
    nodoMesa * listaMesas=archivoToListaMesa(aMesas,listaMesas);
    nodoProd * listaProductos=archivoToListaProducto(aProductos,listaProductos);

    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        tituloPrincipal();

        printf("\n\t\t\t\tMENU PRINCIPAL\n");
        printf("\n\t\t[1]. Clientes\n");
        printf("\t\t[2]. Mesas\n");
        printf("\t\t[3]. Productos\n");
        printf("\t\t[0]. Salir\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                menuClientes();
                break;
            case 2:
                menuMesas(&listaMesas);
                break;

            case 3:
                menuProductos(&listaProductos);
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

