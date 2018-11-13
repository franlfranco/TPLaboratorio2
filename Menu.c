///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
#include "Menu.h"
#include "windows.h"

void menuMostrarArbol(arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        menuMuestraComandaUi();
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                system("cls");
                tituloPrincipal();
                mostrarArbolComandaPreOrden(arbolCuentas);
                system("pause");
                break;

            case 2:
                system("cls");
                tituloPrincipal();
                mostrarArbolComandaenOrden(arbolCuentas);
                system("pause");
                break;

            case 3:
                system("cls");
                tituloPrincipal();
                mostrarArbolComandaPostOrden(arbolCuentas);
                system("pause");
                break;
            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuMuestraComandaUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Muestra de Comanda]\n\n\n");
    linea();
    printf("  [ 1 ]\t Pre-orden \n");
    linea();
    printf("  [ 2 ]\t In-orden \n");
    linea();
    printf("  [ 3 ]\t Post-orden \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}

void menuCuentas(arbolCuenta ** arbolCuentas,nodoProd ** listaProductos, nodoMesa ** listaMesa){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        menuCuentasUi();
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                menuMostrarArbol(*arbolCuentas);
                system("pause");
                break;

            case 2:
                *arbolCuentas=sumarProductoCuenta(*arbolCuentas,*listaProductos);
                //agregarProducto();
                break;

            case 3:
                *arbolCuentas=restarProductoCuenta(*arbolCuentas);
                //quitarProducto();
                break;

            case 4:
                cerrarCuenta(arbolCuentas, listaMesa, listaProductos, aProductos);
                system("pause");
                break;


            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuCuentasUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Cuentas]\n\n\n");
    linea();
    printf("  [ 1 ]\t Listado cuentas activas \n");
    linea();
    printf("  [ 2 ]\t Agregar producto \n");
    linea();
    printf("  [ 3 ]\t Quitar producto \n");
    linea();
    printf("  [ 4 ]\t Cerrar cuenta \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}

void menuProductos(nodoProd * * listaProductos){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        //mostrarArchivoYFilaProd(aProductos,*listaProductos);
        menuProductosUi();
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaProducto(aProductos,listaProductos);
                break;

            case 2:
                bajaProducto(listaProductos,aProductos);
                system("pause");
                break;
            case 3:
                modificarProducto(aProductos,listaProductos);
                //modificacionProducto();
                break;

            case 4:
                mostrarListProductos(*listaProductos);
                system("pause");
                //mostrarProductos();
                break;

            case 5:
                mostrarEstadisticasProductos(*listaProductos);
                break;

            case 6:
                ventaEnBarra(listaProductos,aProductos);
                break;
            case 0:
                repite = 0;
                break;
        }

    } while (repite);
}

void menuProductosUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Productos]\n\n\n");
    linea();
    printf("  [ 1 ]\t Alta  \n");
    linea();
    printf("  [ 2 ]\t Baja \n");
    linea();
    printf("  [ 3 ]\t Modificacion productos\n");
    linea();
    printf("  [ 4 ]\t Listado por productos \n");
    linea();
    printf("  [ 5 ]\t Estadisticas de productos \n");
    linea();
    printf("  [ 6 ]\t Venta en barra \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}



void menuListadoIndividualMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        menuListadoIndividualMesasUi();
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

void menuListadoIndividualMesasUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Listado Mesas]\n\n\n");
    linea();
    printf("  [ 1 ]\t Por numero mesa  \n");
    linea();
    printf("  [ 2 ]\t Por nombre cliente \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}


void menuListadoMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        menuListadoMesasUi();
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
                system("pause");
                break;

            case 4:
                mostrarMesasOcupadas(listaMesa);
                system("pause");
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

void menuListadoMesasUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Listado Mesas]\n\n\n");
    linea();
    printf("  [ 1 ]\t Individual  \n");
    linea();
    printf("  [ 2 ]\t Todas \n");
    linea();
    printf("  [ 3 ]\t Libres \n");
    linea();
    printf("  [ 4 ]\t Ocupadas \n");
    linea();
    printf("  [ 5 ]\t Tabla \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}

void menuMesas(nodoMesa * * listaMesas, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        ///mostrarArchivoYFilaMesa(aMesas,*listaMesas);
        menuMesasUi();
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

void menuMesasUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Mesas]\n\n\n");
    linea();
    printf("  [ 1 ]\t Alta  \n");
    linea();
    printf("  [ 2 ]\t Baja \n");
    linea();
    printf("  [ 3 ]\t Listado \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}



void menuListadoClientes(Fila * espera, arbolCuenta * arbolCuentas){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOW
        menuListadoClientesUi();
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                system("cls");
                tituloPrincipal();
                printf("\t Listado de clientes atendidos :\n");
                mostrarClientesAtendidos(arbolCuentas);
                printf("\n\n\n");
                system("pause");
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

void menuListadoClientesUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Listado Clientes]\n\n\n");
    linea();
    printf("  [ 1 ]\t Atendidos \n");
    linea();
    printf("  [ 2 ]\t En espera \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
}



void menuClientes(nodoMesa ** listaMesa, arbolCuenta ** arbolCuentas, Fila * espera){
    char repite = 1;
    int opcion = -1;

    do {
        system("cls");
        menuClientesUi();
        fflush(stdin);
        scanf(" %i",&opcion );

        switch (opcion) {

            case 1:
                altaCliente(arbolCuentas, listaMesa, espera);
                break;

            case 2:
                atencionClienteEspera(listaMesa, espera, arbolCuentas);
                system("pause");
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

void menuClientesUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Clientes]\n\n\n");
    linea();
    printf("  [ 1 ]\t Alta \n");
    linea();
    printf("  [ 2 ]\t Atencion \n");
    linea();
    printf("  [ 3 ]\t Baja \n");
    linea();
    printf("  [ 4 ]\t Listado \n");
    linea();
    printf("  [ 0 ]\t Volver al menu anterior \n");
    linea();
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
        menuPrincipalUi();
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
                menuCuentas(&arbolCuentas, &listaProductos, &listaMesas);
                break;

            case 0: ///COMPRUEBA QUE NO HAYA MESAS ACTIVAS, SI HAY, ASEGURA EL CIERRE
                if(arbolCuentas)
                {
                    char seguro='n';
                    printf("\nHay mesas activas, si se cierra la aplicacion estos datos se borraran...\n\tEsta seguro que desea salir? ingrese s: ");
                    fflush(stdin);
                    scanf(" %c",&seguro);
                    if(seguro=='s')
                        repite=0;
                }
                else
                repite = 0;
                break;
        }

    } while (repite);
}

void menuPrincipalUi()
{
    linea();
    printf("\n\n\t\t\t\t\t[#La Vaca Bar Menu Principal]\n\n\n");
    linea();
    printf("  [ 1 ]\t Clientes \n");
    linea();
    printf("  [ 2 ]\t Mesas \n");
    linea();
    printf("  [ 3 ]\t Productos \n");
    linea();
    printf("  [ 4 ]\t Cuentas \n");
    linea();
    printf("  [ 0 ]\t Salir \n");
    linea();
}

void splashScreen()
{
    linea();
    printf("\n\n\t\t                                                                           (      ) \n");
    printf("\t\t     __ __  __             _    __                    ____                 ~(^^^^)~ \n");
    printf("\t\t  __/ // /_/ /   ____ _   | |  / /___ __________ _   / __ )____ ______      ) @@ \\~_          |\\ \n");
    printf("\t\t /_  _  __/ /   / __ `/   | | / / __ `/ ___/ __ `/  / __  / __ `/ ___/     /     | \\        \\~ / \n");
    printf("\t\t/_  _  __/ /___/ /_/ /    | |/ / /_/ / /__/ /_/ /  / /_/ / /_/ / /        ( 0  0  ) \\        | |    \n");
    printf("\t\t /_//_/ /_____/\\__,_/     |___/\\__,_/\\___/\\__,_/  /_____/\\__,_/_/          ---___/~  \\       | | \n");
    printf("\t\t                                                                            /'__/ |   ~-_____/ /\n");
    printf("\t\t                                                                        _   ~----~      ___---~ \n");
    printf("\t\t                                                                      //     |         | \n");
    linea();
    printf("\t\t\t\t\t\t Por Fran Mati y Luca\n");
    linea();
    system("Pause");
    menuPrincipal();
}
