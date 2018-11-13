///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
#include "Comanda.h"
#include "Clientes.h"
#include "Mesas.h"
#include "Productos.h"

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
    nodoProd * cursor=lista;
    printf("Productos:\n");
    linea();
    while(cursor){
        printf("%s  ||$ %.2f\n",cursor->prod.nombre,cursor->prod.precio);
        cursor=cursor->sig;
    }
    printf("\n\nTotal : $ %.2f\n",sumarPreciosProd(lista));
    linea();
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
        linea();
        printf("\nMesa nro: %i\n",comanda->mesa.numero);
        printf("Cliente: %s\n",comanda->cliente.nombre);
        mostrarCuenta(comanda->listaProd);
        linea();
    }
}

void mostrarArbolComandaenOrden (arbolCuenta * arbol){ ///MUESTRA EL ARBOL DE COMANDAS ->mostrarComanda()
    if(arbol){
        mostrarArbolComandaenOrden(arbol->izq);
        mostrarComanda(arbol);
        mostrarArbolComandaenOrden(arbol->der);
    }
}

void mostrarArbolComandaPostOrden (arbolCuenta * arbol)  ///MUESTRA EL ARBOL DE COMANDAS ->mostrarComanda()
{
    if(arbol)
    {
        mostrarArbolComandaenOrden(arbol->izq);
        mostrarArbolComandaenOrden(arbol->der);
        mostrarComanda(arbol);
    }
}

void mostrarArbolComandaPreOrden (arbolCuenta * arbol)  ///MUESTRA EL ARBOL DE COMANDAS ->mostrarComanda()
{
    if(arbol)
    {
        mostrarComanda(arbol);
        mostrarArbolComandaenOrden(arbol->izq);
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
            lineaRoja();
            printf("El numero de mesa ingresada es incorrecto o esta ocupada. Ingrese nuevamente\n");
            lineaRoja();
            system("pause");
            system("cls");
        }
        else
            flag=1;
    }while(flag==0);
    nuevo=crearHojaComanda(mesa,nuevoCliente);
    nuevo->cliente.atendido=1;
    lineaVerde();
    printf("El cliente: %s fue asignado a la mesa: %i \n",nuevo->cliente.nombre,nuevo->mesa.numero);
    lineaVerde();
    return nuevo;
}

arbolCuenta * buscarComandaPorNroMesa (arbolCuenta * actual,int nro)
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
    char control='s';
    nodoProd * nuevo;
    arbolCuenta * actual=inicArbol();
    char nombreProducto[30];
    printf("\nIngrese nro de mesa a buscar a modificar: ");
    fflush(stdin);
    scanf("%i",&nroMesa);
    actual=buscarComandaPorNroMesa(mesasOcupadas,nroMesa);
    if(actual)
    {
        do
        {
            system("cls");
            mostrarComanda(actual);
            printf("\n--------------------Carta--------------------\n");
            mostrarListProductos(cartaProductos);
            printf("\n--------------------Carta--------------------\n");
            printf("Ingrese nombre del producto que desea agregar: ");
            fflush(stdin);
            scanf("%s",nombreProducto);
            if(chequearProducto(aProductos,nombreProducto))
            {
                nuevo=retornarNodoProductoDeLista(cartaProductos,nombreProducto);
                actual->listaProd=agregarProductoLista(actual->listaProd,nuevo);
                printf("\nProducto agregado con exito!...\n");
            }
            else
            {
                printf("\nNo se encuentra el nombre del producto ingresado...\n");
                system("pause");
            }
            printf("\nDesea agregar otro producto? ingrese s:  ");
            fflush(stdin);
            scanf(" %c",&control);
        }
        while(control=='s');
    }
    else
    {
        printf("\nNo se encuentra el numero de mesa actualmente ocupado...\n");
        system("pause");
    }
    return mesasOcupadas;
}
arbolCuenta * restarProductoCuenta (arbolCuenta * mesasOcupadas) ///Resta un producto de la lista del arbol
{
    int nroMesa;
    //nodoProd * nuevo;
    arbolCuenta * actual=inicArbol();
    char nombreProducto[30];
    printf("\nIngrese nro de mesa a buscar a modificar: ");
    fflush(stdin);
    scanf("%i",&nroMesa);
    actual=buscarComandaPorNroMesa(mesasOcupadas,nroMesa);
    if(actual)
    {
        system("cls");
        mostrarComanda(actual);
        if(actual->listaProd)
        {
            printf("Ingrese nombre del producto que desea eliminar de la cuenta: ");
            fflush(stdin);
            scanf("%s",nombreProducto);
            //if(chequearProducto(aProductos,nombreProducto))
                actual->listaProd=bajaListaProd(actual->listaProd,nombreProducto);
            //else
                //printf("\nEl nombre de producto ingresado es incorrecto\n");
            //Comentando estas lineas, no se bloquea el restar un producto que fue quitado del archivo durante la ejecucion,
            //pero no hay forma de avisar al usuario si se borro de la cuenta o no... Habria que trabajar la listaprod por * * para
            //retornar un flag (Pero habria que retocar todo el archivo)
        }
        else
        {
            printf("\nNo hay ningun producto cargado en la mesa actual\n");
        }
    }
    else
    {
        printf("\nNo se encuentra el numero de mesa actualmente ocupado...\n");
        system("pause");
    }
    return mesasOcupadas;
}

int contarCantidadProductosCuenta (nodoProd * lista)
{
    int rta=0;
    while(lista)
    {
        rta++;
        lista=lista->sig;
    }
return rta;
}

float sumarGastosMesas (arbolCuenta * cuentas)
{
    float rta;
    if(cuentas)
    {
        rta=sumarPreciosProd(cuentas->listaProd);
        rta+=sumarGastosMesas(cuentas->izq);
        rta+=sumarGastosMesas(cuentas->der);
    }
    else
        rta=0;
return rta;
}

arbolCuenta * buscarMenor (arbolCuenta * main)
{
    arbolCuenta * rta=inicArbol();
    if(main)
    {
        rta=main;
        arbolCuenta * aux=buscarMenor(main->izq);
        if(aux && aux->mesa.numero<rta->mesa.numero)
        {
            rta=aux;
        }
    }
    return rta;
}

arbolCuenta * buscarMayor (arbolCuenta * main)
{
    arbolCuenta * rta=inicArbol();
    if(main)
    {
        rta=main;
        arbolCuenta * aux=buscarMayor(main->der);
        if(aux && aux->mesa.numero>rta->mesa.numero)
        {
            rta=aux;
        }
    }
    return rta;
}

arbolCuenta * borrarCuenta (arbolCuenta * arbolCuentas, int numMesa)
{
    if(arbolCuentas) ///SI MAIN TIENE DATOS
    {
        arbolCuentas->izq=borrarCuenta(arbolCuentas->izq,numMesa);
        if(arbolCuentas->mesa.numero==numMesa) ///SI EL MATCH SE DA EN EL NODO ACTUAL
        {
            arbolCuenta * aux;
            if(arbolCuentas->izq && arbolCuentas->der) ///TIENE DOS HIJOS
            {
                aux=buscarMayor(arbolCuentas->izq);
                arbolCuentas->mesa=aux->mesa;
                arbolCuentas->cliente=aux->cliente;
                arbolCuentas->listaProd=aux->listaProd;
                arbolCuentas->izq=borrarCuenta(arbolCuentas->izq,arbolCuentas->mesa.numero);
            }
            else ///TIENE 1 O NINGUN HIJO
            {
                if(!arbolCuentas->izq && !arbolCuentas->der) ///ES HOJA
                {

                    free(arbolCuentas->listaProd);
                    free(arbolCuentas);
                    arbolCuentas=inicArbol();
                }
                else
                {
                    if(arbolCuentas->izq) ///TIENE HIJO A LA IZQ
                    {

                        aux=buscarMayor(arbolCuentas->izq);
                        arbolCuentas->mesa=aux->mesa;
                        arbolCuentas->cliente=aux->cliente;
                        arbolCuentas->listaProd=aux->listaProd;
                        arbolCuentas->izq=borrarCuenta(arbolCuentas->izq,aux->mesa.numero);
                    }
                    if(arbolCuentas->der) ///TIENE HIJO A LA DERECHA
                    {

                        aux=buscarMenor(arbolCuentas->der);
                        arbolCuentas->mesa=aux->mesa;
                        arbolCuentas->cliente=aux->cliente;
                        arbolCuentas->listaProd=aux->listaProd;
                        arbolCuentas->der=borrarCuenta(arbolCuentas->der,arbolCuentas->mesa.numero);
                    }
                }
            }
        }
        if(arbolCuentas)
            arbolCuentas->der=borrarCuenta(arbolCuentas->der,arbolCuentas->mesa.numero);
    }
    return arbolCuentas;
}

void cerrarCuenta(arbolCuenta ** arbolCuentas, nodoMesa ** listaMesa, nodoProd ** listaProd, char aProducto[])
{
    if(*arbolCuentas)
    {
        int numero;
        char control='s';
        printf("\nIngrese el numero de mesa a cerrar: ");
        fflush(stdin);
        scanf("%i",&numero);
        if(chequearMesaOcupada(*listaMesa, numero))
        {
            arbolCuenta * aux=buscarComandaPorNroMesa(*arbolCuentas, numero);
            mostrarComanda(aux);
            printf("\nEsta seguro que desea cerrar la cuenta? ingrese s: ");
            fflush(stdin);
            scanf("%c",&control);
            if(control=='s')
            {
                cierreListaProductos(aux->listaProd, listaProd, aProducto);
                desocuparMesa(listaMesa, numero);
                *arbolCuentas=borrarCuenta(*arbolCuentas, numero);
                printf("\nLa vaca esta contenta. :) Mesa cerrada\n");
            }
            else
                printf("\nCancelando el cierre de cuenta.\n");
        }
        else
        {
            printf("\nLa mesa ingresada esta libre o no existe.");
        }
    }
    else
        printf("\nNo hay ninguna cuenta activa.");
}
