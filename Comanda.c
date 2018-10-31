//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Comanda

#include "Comanda.h"
#include "Clientes.h"
#include "Mesas.h"

arbolCuenta * inicArbol (void){
    return NULL;
}

arbolCuenta * agregarHojaArbolCuentas (arbolCuenta * arbol,arbolCuenta * nuevo){ ///AGREGA UN ARBOL CUENTA AL PRINCIPAL
    if(!arbol){
        arbol=nuevo;
    }else{
        if(nuevo->mesa.numero>arbol->mesa.numero)
            arbol->der=agregarHojaArbolCuentas(arbol->der,nuevo);
        else
            arbol->izq=agregarHojaArbolCuentas(arbol->izq,nuevo);
    }
    return arbol;
}

void mostrarCuenta (nodoProd * lista){ ///MUESTRA LA LISTA DE PRODUCTOS PEDIDOS POR EL CLIENTE
    float total=0;
    printf("\n----------------Productos--------------------\n");
    while(lista){
        printf("%30s   ||$ %.2f\n",lista->prod.nombre,lista->prod.precio);
        total=total+lista->prod.precio;
        lista=lista->sig;
    }
    printf("\n\nTotal : $ %.2f\n",total);
    printf("\n---------------------------------------------\n");
}

float sumarPreciosProd (nodoProd * lista){ ///RETORNA FLOAT DE TOTAL DE CUENTA
    float total=0;
    while(lista){
        total=total+lista->prod.precio;
        lista=lista->sig;
    }
    return total;
}

void mostrarComanda (arbolCuenta * comanda){ ///MUESTRA NRO MESA, CLIENTE Y LA LISTA DE PEDIDOS -> mostrarcuenta()
    if(comanda){
        printf("\n=======================================================================\n");
        printf("\nMesa nro: %i\n",comanda->mesa.numero);
        printf("Cliente: %s\n",comanda->cliente.nombre);
        mostrarCuenta(comanda->listaProd);
        printf("\n=======================================================================\n");
    }
}

void mostrarArbolComandaenOrden (arbolCuenta * arbol){ ///MUESTRA EL ARBOL DE COMANDAS ->mostrarComanda()
    if(arbol){
        mostrarArbolComandaenOrden(arbol->izq);
        mostrarComanda(arbol);
        mostrarArbolComandaenOrden(arbol->der);
    }
}

arbolCuenta * crearHojaComanda(Mesa mesa,Cliente cliente){ ///CREA UNA COMANDA EN BASE A MESA Y CLIENTE, GENERA LISTA DE PEDIDOS VACIA
    arbolCuenta * aux=(arbolCuenta*)malloc(sizeof(arbolCuenta));
    aux->mesa=mesa;
    aux->cliente=cliente;
    aux->listaProd=inicListaProd();
    aux->izq=NULL;
    aux->der=NULL;
    return aux;
}

int ocuparMesa (nodoMesa ** lista,Mesa * pedida,int nro){ ///PIDE LISTA, STRUCT MESA VACIA Y NRO. RETORNA 0 SI NO ENCONTRO LIBRE EL NRO Y 1 SI ESTA OK
    int flag=0;
    if(*lista){
        nodoMesa * cursor=*lista;
        while (cursor) {
            if(cursor->mesa.numero==nro && cursor->mesa.ocupada==0){
                cursor->mesa.ocupada=1;
                *pedida=cursor->mesa;
                flag=1;
            }else{
                cursor=cursor->sig;
            }
        }
    }
    return flag;
}

arbolCuenta * ingresarClienteANodoArbol (nodoMesa * * listaMesa, Cliente nuevoCliente)//Ingresa un cliente a un nodoArbol, y asigna mesa
{
    Mesa mesa;
    arbolCuenta * nuevo=inicArbol();
    int elegir;
    int flag=0; ///CONDICION DE CIERRE DEL DO WHILE
    do
    {
        mostrarMesasLibres(*listaMesa);
        printf("Ingrese el numero de Mesa para %s\n- ",nuevoCliente.nombre);
        fflush(stdin);
        scanf("%i",&elegir);
        
        if(!ocuparMesa(listaMesa,&mesa,elegir))//retorna 1 si la mesa esta libre
        {
            printf("\nEl numero de mesa ingresada es incorrecto o esta ocupada. Ingrese nuevamente\n");
            system("pause");
            system("cls");
        }
        else
            flag=1;
    }while(flag==0);
    nuevo=crearHojaComanda(mesa,nuevoCliente);
    nuevo->cliente.atendido=1;
    printf("El cliente: %s fue asignado a la mesa: %i \n",nuevo->cliente.nombre,nuevo->mesa.numero);
    return nuevo;
}

arbolCuenta * buscarComandaPorNroMesa (arbolCuenta * actual,int nro) ///flag == 0 no se encontro la mesa
{
    arbolCuenta * rta=inicArbol();
    if(actual)
    {
        if(!rta)///si no se encontro el nro de mesa, busca en la izquierda
        rta=buscarComandaPorNroMesa(actual->izq,nro);
        if(!rta)
        {
            if(actual->mesa.numero==nro) ///si encuentra el dato, muestra la comanda
            {
                rta=actual;
            }
        }
        if(!rta) ///si no se encontro el nro, sigue buscando en los derechos
        rta=buscarComandaPorNroMesa(actual->der,nro);
    }
    return rta;
}

arbolCuenta * buscarComandaPorCliente (arbolCuenta * actual,char nombre[]) ///flag == 0 no se encontro la mesa
{
    arbolCuenta * rta=inicArbol();
    if(actual)
    {
        if(!rta)///si no se encontro el nro de mesa, busca en la izquierda
        rta=buscarComandaPorCliente(actual->izq,nombre);
        if(!rta)
        {
            if(strcmp(actual->cliente.nombre,nombre)==0) ///si encuentra el dato, muestra la comanda
            {
                rta=actual;
            }
        }
        if(!rta) ///si no se encontro el nro, sigue buscando en los derechos
        rta=buscarComandaPorCliente(actual->der,nombre);
    }
    return rta;
}

arbolCuenta * sumarProductoCuenta (arbolCuenta * mesasOcupadas,nodoProd * cartaProductos)
{
    int nroMesa;
    nodoProd * nuevo;
    arbolCuenta * actual=inicArbol();
    char nombreProducto[30];
    printf("\nIngrese nro de mesa a buscar a modificar: ");
    fflush(stdin);
    scanf("%i",&nroMesa);
    actual=buscarComandaPorNroMesa(mesasOcupadas,nroMesa);
    if(actual)
        {
            mostrarComanda(actual);
            printf("\n--------------------Carta--------------------\n");
            mostrarListProductos(cartaProductos);
            printf("\n--------------------Carta--------------------\n");
            printf("Ingrese nombre del producto que desea agregar: ");
            fflush(stdin);
            scanf("%s",nombreProducto);
            if(chequearProducto(aMesas,nombreProducto))
            {
                //nuevo=extraerProductoDeLista(cartaProductos,nombreProducto);
                nuevo=retornarNodoProductoDeLista(cartaProductos,nombreProducto);
                actual->listaProd=agregarProductoLista(actual->listaProd,nuevo);
                printf("\nProducto agregado con exito!...\n");
            }
            else
            {
                printf("\nNo se encuentra el nombre del producto ingresado...\n");
                system("pause");
            }
        }
    else
    {
        printf("\nNo se encuentra el numero de mesa actualmente ocupado...\n");
        system("pause");
    }
    return mesasOcupadas;
}
