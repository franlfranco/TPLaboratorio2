///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
#include "Clientes.h"

Cliente nuevoCliente (void)  ///PIDE INGRESO DE NOMBRE Y RETORNA STRUCT CLIENTE
{
    Cliente nuevo;
    printf("\nIngresar nombre del cliente: ");
    fflush(stdin);
    scanf("%s",nuevo.nombre);
    nuevo.atendido=0;
    return nuevo;
}

nodoCliente * inicNodoCliente (void)
{
    return NULL;
}

nodoCliente * crearNodoCliente (Cliente cliente)
{
    nodoCliente * aux=(nodoCliente*)malloc(sizeof(nodoCliente));
    aux->cliente=cliente;
    aux->sig=NULL;
    aux->ante=NULL;
    return aux;
}

Fila inicFila (void)
{
    Fila aux;
    aux.cabecera=inicNodoCliente();
    aux.ultimo=inicNodoCliente();
    return aux;
}

nodoCliente * agregarFinalnodoCliente (nodoCliente * lista,nodoCliente * nuevo)
{
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

void mostrarListaCliente (nodoCliente * listaCliente) // Muestra LISTA de clientes
{
    printf("\n");
    while(listaCliente)
    {
        printf("| %s  ",listaCliente->cliente.nombre);
        listaCliente=listaCliente->sig;
    }
}

void agregarClienteAFila (Fila * espera,Cliente ultimo)
{
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

void mostrarFilaEspera (Fila espera)
{
    system("cls");
    tituloPrincipal();
    mostrarListaCliente(espera.cabecera);
    printf("\n\n[Primero]");
    mediaLinea();
    printf("[Fila de espera]");
    mediaLinea();
    printf("[Ultimo]\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}

Cliente extraerClienteEspera (Fila * espera)
{
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
        }
        else
        {
            nodoCliente * aborrar=aux;
            aux=aux->sig;
            aux->ante=NULL;
            espera->cabecera=aux;
            free(aborrar);
        }
    }
    else
    {
        linea();
        printf("No hay nadie en fila de espera...");
        linea();
    }
    return rta;
}

/*
void testFila (void)
{
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
    }
    while(opc!=0);
}
*/

void altaCliente(arbolCuenta ** arbolCuentas, nodoMesa * * listaMesa, Fila * espera)
{
    int nombreRepetido;
    Cliente nuevo;
    do
    {
        system("cls");
        tituloPrincipal();
        nuevo=nuevoCliente();
        nombreRepetido=chequearCliente(*arbolCuentas,*espera,nuevo.nombre);
        if(nombreRepetido)
        {
            lineaRoja();
            printf("Ese nombre ya se encuentra en uso, por favor ingrese otro\n\a");
            lineaRoja();
            printf("\n\n\n\n\n\n\n\n");
            system("pause");
        }
        else
        {
            nombreRepetido=0;
        }
    }
    while(nombreRepetido);
    if(chequearDisponibilidadMesas(*listaMesa))
    {
        //printf("Cliente al arbol\n");
        *arbolCuentas=agregarHojaArbolCuentas(*arbolCuentas, ingresarClienteANodoArbol(listaMesa, nuevo));
        system("pause");
    }
    else
    {
        agregarClienteAFila(espera, nuevo);
        lineaVerde();
        printf("Cliente a la fila\n");
        lineaVerde();
        printf("\n\n\n\n\n\n\n\n");
        system("pause");
    }
}

void atencionClienteEspera(nodoMesa ** listaMesa, Fila * espera, arbolCuenta ** arbolCuentas)
{
    system("cls");
    tituloPrincipal();
    if(chequearDisponibilidadMesas(*listaMesa))
    {
        if(espera->cabecera)
        {
            Cliente atender=extraerClienteEspera(espera);
            *arbolCuentas=agregarHojaArbolCuentas(*arbolCuentas, ingresarClienteANodoArbol(listaMesa, atender));
        }
        else
        {
            lineaVerde();
            printf("La fila esta vacia.\n");
            lineaVerde();
            printf("\n\n\n\n\n");
            system("pause");
        }
    }
    else
    {
        lineaRoja();
        printf("No hay mesas libres.\n\a");
        lineaRoja();
        printf("\n\n\n\n\n");
        system("pause");
    }
}

int eliminarNodoClienteDeFila (nodoCliente * * espera,char nombre[]) ///MODIFICA LA LISTA DE ESPERA, RETORNA 1 SI ELIMINO
{
    int flag=0;
    if(*espera!=NULL)
    {
        nodoCliente * aborrar=inicNodoCliente();
        if(strcmp((*espera)->cliente.nombre,nombre)==0)
        {
            aborrar=*espera;
            *espera=(*espera)->sig;
            if(*espera)
            {
                (*espera)->ante=inicNodoCliente();
            }
            free(aborrar);
            flag=1;
        }
        else
        {
            nodoCliente * cursor=(*espera)->sig;
            while(cursor && strcmp(cursor->cliente.nombre,nombre)!=0)
            {
                cursor=cursor->sig;
            }
            if(cursor)
            {
                nodoCliente * ante=cursor->ante;
                aborrar=cursor;
                cursor=cursor->sig;
                ante->sig=cursor;
                if(cursor)
                {
                    cursor->ante=ante;
                }
                free(aborrar);
                flag=1;
            }
        }
    }
    return flag;
}

void bajaClienteEspera(Fila * espera)
{
    if(espera->cabecera)
    {
        char nombre[30];
        system("cls");
        tituloPrincipal();
        printf("Ingrese el nombre de la persona que desea eliminar de la fila: ");
        fflush(stdin);
        scanf("%s",nombre);
        nodoCliente * ultimo=espera->ultimo;
        if(strcmp(ultimo->cliente.nombre,nombre)==0)
            ultimo=ultimo->ante;
        if(eliminarNodoClienteDeFila(&espera->cabecera,nombre))
        {
            printf("\n\n");
            lineaVerde();
            printf("Se elimino a %s con exito.\n",nombre);
            lineaVerde();
            printf("\n\n\n\n\n");
            system("pause");
        }
        else
        {
            printf("\n\n");
            lineaRoja();
            printf("No se encuentra el nombre %s en la fila.\n\a",nombre);
            lineaRoja();
            printf("\n\n\n\n\n");
            system("pause");
        }
    }
    else
    {
        printf("No hay nadie en la fila de espera.\n");
    }
}

void mostrarClientesYMesas (arbolCuenta * comanda)  ///MUESTRA NRO MESA Y CLIENTE
{
    if(comanda)
    {
        linea();
        printf("Mesa nro: %i\n",comanda->mesa.numero);
        printf("Cliente: %s\n",comanda->cliente.nombre);
    }
}

void mostrarClientesAtendidos (arbolCuenta * arbol)  ///Muestra el arbol de comandas sin los productos
{
    if(arbol)
    {
        mostrarClientesAtendidos(arbol->izq);
        mostrarClientesYMesas(arbol);
        mostrarClientesAtendidos(arbol->der);
    }
}

int chequearCliente (arbolCuenta * arbolcuentas,Fila espera,char nombreNuevo[])
{
    int flag=0;
    Cliente aux;
    nodoCliente * cliente=espera.cabecera;
    arbolCuenta * busqueda=inicArbol();
    while(cliente && flag==0)
    {
        aux=cliente->cliente;
        if(strcmp(aux.nombre,nombreNuevo)==0)
        {
            flag=1;
        }
        else
        {
            cliente=cliente->sig;
        }
    }
    busqueda=buscarComandaPorCliente(arbolcuentas,nombreNuevo);
    if(busqueda)
    {
        flag=1;
    }
    return flag;
}
