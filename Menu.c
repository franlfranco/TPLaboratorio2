//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Menu

#include "Menu.h"

void menuCuentas(arbolCuenta ** arbolCuentas,nodoProd * listaProductos){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU CUENTAS\n");
        printf("\n\t\t[1]. Listado cuentas activas\n");
        printf("\t\t[2]. Agregar productos\n");
        printf("\t\t[3]. Quitar productos\n");
        printf("\t\t[4]. Cerrar cuenta\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                mostrarArbolComandaenOrden(*arbolCuentas);
                break;

            case 2:
                *arbolCuentas=sumarProductoCuenta(*arbolCuentas,listaProductos);
                //agregarProducto();
                break;

            case 3:
                *arbolCuentas=restarProductoCuenta(*arbolCuentas);
                //quitarProducto();
                break;

            case 4:
                //cerrarCuenta();
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
        printf("\t\t[3]. Modificacion productos\n");
        printf("\t\t[4]. Listado productos\n");
        printf("\t\t[5]. Venta en barra\n");
        printf("\t\t[6]. Estadisticas de productos\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaProducto(aProductos,listaProductos);
                break;

            case 2:
                bajaProducto(listaProductos,aProductos);
                break;
            case 3:
                modificarProducto(aProductos,listaProductos);
                //modificacionProducto();
                break;

            case 4:
                mostrarListProductos(*listaProductos);
                //mostrarProductos();
                break;

            case 5:
                ventaEnBarra(listaProductos,aProductos);
                //ventaBarra();
                break;
            case 6:
                mostrarEstadisticasProductos(*listaProductos);
                break;
            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuListadoIndividualMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        printf("\n\t\t\t\tSUBMENU MESAS\n");
        printf("\n\t\t[1]. Por numero mesa\n");
        printf("\t\t[2]. Por nombre cliente\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                mostrarMesaIndividualXNumero(listaMesa, arbolCuentas);
                break;
                
            case 2:
                mostrarMesaIndividualXNombre(listaMesa,arbolCuentas);
                //mostrarMesaIndividualXNombre
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListadoMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        printf("\n\t\t\t\tSUBMENU MESAS\n");
        printf("\n\t\t[1]. Individual\n");
        printf("\t\t[2]. Todas\n");
        printf("\t\t[3]. Libres\n");
        printf("\t\t[4]. Ocupadas\n");
        printf("\t\t[5]. Tabla\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuListadoIndividualMesas(listaMesa,arbolCuentas);
                break;
                
            case 2:
                mostrarTodasLasMesas (listaMesa,arbolCuentas);
                break;
                
            case 3:
                mostrarMesasLibres(listaMesa);
                break;
            
            case 4:
                mostrarMesasOcupadas(listaMesa);
                break;
                
            case 5:
                mostrarEstadisticasMesas(listaMesa, arbolCuentas);
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuMesas(nodoMesa * * listaMesas, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        mostrarArchivoYFilaMesa(aMesas,*listaMesas);
        tituloPrincipal();
        printf("\n\t\t\t\tSUBMENU MESAS\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. Listado\n");
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
                menuListadoMesas(*listaMesas,arbolCuentas);
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuListadoClientes(Fila * espera, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU LISTADO CLIENTES\n");
        printf("\t\t[1]. Atendidos\n");
        printf("\t\t[2]. En espera\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                mostrarClientesAtendidos(arbolCuentas);
                break;

            case 2:
                mostrarFilaEspera(*espera);
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuClientes(nodoMesa ** listaMesa, arbolCuenta ** arbolCuentas, Fila * espera){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        tituloPrincipal();

        printf("\n\t\t\t\tSUBMENU CLIENTES\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Atención\n");
        printf("\t\t[3]. Baja\n");
        printf("\t\t[4]. Listado\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaCliente(arbolCuentas, listaMesa, espera);
                break;

            case 2:
                atencionClienteEspera(listaMesa, espera, arbolCuentas);
                break;

            case 3:
                //bajaCliente
                bajaClienteEspera(espera);
                //Borrar nodo de lista doble, chequear que no sea cabecera o ultimo en la fila
                break;

            case 4:
                menuListadoClientes(espera, *arbolCuentas);
                break;

            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuPrincipal(void){ ///MAIN
    Fila espera=inicFila();
    nodoMesa * listaMesas=archivoToListaMesa(aMesas,listaMesas);
    nodoProd * listaProductos=archivoToListaProducto(aProductos,listaProductos);
    arbolCuenta * arbolCuentas=inicArbol();

    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        tituloPrincipal();

        printf("\n\t\t\t\tMENU PRINCIPAL\n");
        printf("\n\t\t[1]. Clientes\n");
        printf("\t\t[2]. Mesas\n");
        printf("\t\t[3]. Productos\n");
        printf("\t\t[4]. Cuentas\n");
        printf("\t\t[0]. Salir\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                menuClientes(&listaMesas, &arbolCuentas, &espera);
                break;
            case 2:
                menuMesas(&listaMesas,arbolCuentas);
                break;

            case 3:
                menuProductos(&listaProductos);
                break;

            case 4:
                menuCuentas(&arbolCuentas,listaProductos);
                break;
                
            case 0: ///COMPRUEBA QUE NO HAYA MESAS ACTIVAS, SI HAY, ASEGURA EL CIERRE
                if(arbolCuentas)
                {
                    char seguro='n';
                    printf("\nHay mesas activas, si se cierra la aplicacion estos datos se borraran...\n\tEsta seguro que desea salir? ingrese s: ");
                    fflush(stdin);
                    scanf("%c",&seguro);
                    if(seguro=='s')
                        repite=0;
                }
                else
                repite = 0;
                break;
        }

    } while (repite);
}

