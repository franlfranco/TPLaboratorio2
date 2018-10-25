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

arbolCuenta * nuevaCuenta (arbolCuenta * arbol,arbolCuenta * nuevo){ ///AGREGA UN ARBOL CUENTA AL PRINCIPAL
    if(!arbol){
        arbol=nuevo;
    }else{
        if(nuevo->mesa.numero>arbol->mesa.numero)
            arbol->der=nuevaCuenta(arbol->der,nuevo);
        else
            arbol->izq=nuevaCuenta(arbol->izq,nuevo);
    }
    return arbol;
}

//Muestra de arbol
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

//Renombrar a crearNodoArbolCuenta
arbolCuenta * nuevaComanda(Mesa mesa,Cliente cliente){ ///CREA UNA COMANDA EN BASE A MESA Y CLIENTE, GENERA LISTA DE PEDIDOS VACIA
    arbolCuenta * aux=(arbolCuenta*)malloc(sizeof(arbolCuenta));
    aux->mesa=mesa;
    aux->cliente=cliente;
    aux->listaProd=inicListaProd();
    aux->izq=NULL;
    aux->der=NULL;
    return aux;
}

int reservarMesa (nodoMesa * lista,Mesa * pedida,int nro) ///PIDE LISTA, STRUCT MESA VACIA Y NRO. RETORNA 0 SI NO ENCONTRO LIBRE EL NRO Y 1 SI ESTA OK
{
    int flag=0;
    while(lista)
    {
        if(lista->mesa.numero==nro && lista->mesa.ocupada==0)
        {
            lista->mesa.ocupada=1;
            *pedida=lista->mesa;
            flag=1;
        }
        else
        {
            lista=lista->sig;
        }
        
    }
    return flag;
}

arbolCuenta * atenderCliente (nodoMesa * mesas)
{
    Cliente cliente;
    Mesa mesa;
    arbolCuenta * nuevo=inicArbol();
    cliente=nuevoCliente();
    if(mostrarMesasLibres(mesas)) ///SI HAY MESAS DISPONIBLES
    {
        int elegir;
        int flag=0; ///CONDICION DE CIERRE DEL DO WHILE
        do
        {
            printf("Ingrese el numero de Mesa para %s\n- ",cliente.nombre);
            fflush(stdin);
            scanf("%i",&elegir);
            if(!reservarMesa(mesas,&mesa,elegir))
            {
                printf("\nEl numero de mesa ingresada es incorrecto o esta ocupada... Ingrese nuevamente\n");
                system("pause");
                system("cls");
                mostrarMesasLibres(mesas);
            }
            else
                flag=1;
        }while(flag==0);
        nuevo=nuevaComanda(mesa,cliente);
        nuevo->cliente.atendido=1;
        printf("El cliente: %s fue asignado a la mesa: %i \n",nuevo->cliente.nombre,nuevo->mesa.numero);
    }
    else ///MESAS LLENAS
    {
        printf("\nNo hay mesas disponibles... A la fila!\n");
    }
    return nuevo;
}
