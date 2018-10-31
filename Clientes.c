//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar
//Libreria Clientes

#include "Clientes.h"

Cliente nuevoCliente (void){ ///PIDE INGRESO DE NOMBRE Y RETORNA STRUCT CLIENTE
    Cliente nuevo;
    printf("\nIngresar nombre del cliente: ");
    fflush(stdin);
    scanf("%s",nuevo.nombre);
    nuevo.atendido=0;
    return nuevo;
}

nodoCliente * inicNodoCliente (void){
    return NULL;
}

nodoCliente * crearNodoCliente (Cliente cliente){
    nodoCliente * aux=(nodoCliente*)malloc(sizeof(nodoCliente));
    aux->cliente=cliente;
    aux->sig=NULL;
    aux->ante=NULL;
    return aux;
}

Fila inicFila (void){
    Fila aux;
    aux.cabecera=inicNodoCliente();
    aux.ultimo=inicNodoCliente();
    return aux;
}

nodoCliente * agregarFinalnodoCliente (nodoCliente * lista,nodoCliente * nuevo){
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        nodoCliente * cursor=lista;
        while(cursor->sig)
            cursor=cursor->sig;
        cursor->sig=nuevo;
        nuevo->ante=cursor;
    }
    return lista;
}//Agrega Cliente al final de la LISTA de clientes

void mostrarListaCliente (nodoCliente * listaCliente){// Muestra LISTA de clientes
    printf("\n");
    while(listaCliente){
        printf("| %s  ",listaCliente->cliente.nombre);
        listaCliente=listaCliente->sig;
    }
}

void agregarClienteAFila (Fila * espera,Cliente ultimo){
    nodoCliente * clienteNuevo=crearNodoCliente(ultimo);
    if(!espera->cabecera)
    {
        espera->cabecera=agregarFinalnodoCliente(espera->cabecera,clienteNuevo);///SI LA FILA ESTA VACIA, CREA NODO DE CLIENTE Y AGREGA
        espera->ultimo=espera->cabecera;
    }
    else
    {
        espera->cabecera=agregarFinalnodoCliente(espera->cabecera,clienteNuevo);
        espera->ultimo=clienteNuevo;
    }
}

void mostrarFilaEspera (Fila espera){
    printf("\nPrimero----------------------Fila de espera----------------------Ultimo\n");
    mostrarListaCliente(espera.cabecera);
    printf("\n\nPrimero----------------------Fila de espera----------------------Ultimo\n");
    //printf("Proximo cliente a atender: %s\n",espera.cabecera->cliente.nombre);
    //printf("Ultimo cliente de la fila: %s\n",espera.ultimo->cliente.nombre);
}

Cliente extraerClienteEspera (Fila * espera){
    Cliente rta;
    if(espera->cabecera) ///SI HAY GENTE EN FILA DE ESPERA
    {
        nodoCliente * aux=espera->cabecera;
        rta=aux->cliente;
        rta.atendido=1;
        if(espera->cabecera==espera->ultimo) ///SI HAY SOLO UNA PERSONA
        {
            espera->cabecera=inicNodoCliente();
            espera->ultimo=inicNodoCliente();
        }else{
            nodoCliente * aborrar=aux;
            aux=aux->sig;
            aux->ante=NULL;
            espera->cabecera=aux;
            free(aborrar);
        }
    }else{
        printf("No hay nadie en fila de espera...");
    }
    return rta;
}

void testFila (void){
    Fila espera=inicFila();
    Cliente atendido;
    int opc;
    do
    {
        printf("\n\n--------------------------.Testeo Filas.--------------------------\n\n");
        printf("1- Agregar a la fila\n");
        printf("2- Extraer al primero de la lista\n");
        printf("3- Mostrar la fila\n");
        printf("0- Salir\n- ");
        fflush(stdin);
        scanf("%i",&opc);
        switch(opc)
        {
            case 1:
                agregarClienteAFila(&espera,nuevoCliente());
                break;
            case 2:
                if(espera.cabecera)
                {
                    atendido=extraerClienteEspera(&espera);
                    printf("\nSe atendio a: %s | Status: %i\n",atendido.nombre,atendido.atendido);
                }
                else
                {
                    printf("\nNo hay clientes en espera...\n");
                }
                break;
            case 3:
                mostrarFilaEspera(espera);
                break;
            case 0:
                printf("\nSaliendo del test de Filas...\n");
                break;
            default:
                printf("\nOpcion incorrecta, ingrese otra...\n");
        }
        system("pause");
        system("cls");
    }while(opc!=0);
}

void altaCliente(arbolCuenta ** arbolCuentas, nodoMesa * * listaMesa, Fila * espera){
    Cliente nuevo=nuevoCliente();
    if(chequearDisponibilidadMesas(*listaMesa)){
        printf("Cliente al arbol\n");
        *arbolCuentas=agregarHojaArbolCuentas(*arbolCuentas, ingresarClienteANodoArbol(listaMesa, nuevo));
    }else{
        agregarClienteAFila(espera, nuevo);
        printf("Cliente a la fila\n");
    }
}

void atencionClienteEspera(nodoMesa ** listaMesa, Fila * espera, arbolCuenta ** arbolCuentas){
    if(chequearDisponibilidadMesas(*listaMesa)){
        if(espera->cabecera){
            Cliente atender=extraerClienteEspera(espera);
            *arbolCuentas=agregarHojaArbolCuentas(*arbolCuentas, ingresarClienteANodoArbol(listaMesa, atender));
        }else{
            printf("La fila esta vacia.\n");
        }
    }else{
        printf("No hay mesas libres.\n");
    }
}
