///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
#ifndef Cuentas_h
#define Cuentas_h

#include "Funciones.h"

arbolCuenta * inicArbol (void);

arbolCuenta * agregarHojaArbolCuentas (arbolCuenta * arbol,arbolCuenta * nuevo); // Inserta un nodo en el arbolCuenta

void mostrarCuenta (nodoProd * lista); ///MUESTRA LA LISTA DE PRODUCTOS PEDIDOS POR EL CLIENTE

float sumarPreciosProd (nodoProd * lista); ///RETORNA FLOAT DE TOTAL DE CUENTA

void mostrarComanda (arbolCuenta * comanda); ///MUESTRA NRO MESA, CLIENTE Y LA LISTA DE PEDIDOS -> mostrarcuenta()

void mostrarArbolComandaPostOrden(arbolCuenta * arbol); ///MUESTRA EL ARBOL DE COMANDAS POST ORDEN -> mostrarComanda()

void mostrarArbolComandaPreOrden (arbolCuenta * arbol); ///MUESTRA EL ARBOL DE COMANDAS PRE ORDEN ->mostrarComanda()

void mostrarArbolComandaenOrden (arbolCuenta * arbol);///MUESTRA EL ARBOL DE COMANDAS ->mostrarComanda()

arbolCuenta * crearHojaComanda(Mesa mesa,Cliente cliente); //Crea un nodoArbol para insertar en el arbol

int ocuparMesa (nodoMesa ** lista,Mesa * pedida,int nro); ///PIDE LISTA, STRUCT MESA VACIA(CAMBIA OCUPADO A 1) Y NRO DE MESA, RETORNA 0 SI NO ENCONTRO LIBRE EL NRO Y 1 SI ESTA OK

arbolCuenta * ingresarClienteANodoArbol (nodoMesa * * listaMesa, Cliente nuevoCliente);//Ingresa un cliente a un nodoArbol, y asigna mesa

arbolCuenta * buscarComandaPorNroMesa (arbolCuenta * actual,int nro); //Retorna nodo

arbolCuenta * buscarComandaPorCliente (arbolCuenta * actual,char nombre[]);

arbolCuenta * sumarProductoCuenta (arbolCuenta * mesasOcupadas,nodoProd * cartaProductos);

arbolCuenta * restarProductoCuenta (arbolCuenta * mesasOcupadas);

float sumarGastosMesas (arbolCuenta * cuentas);

int contarCantidadProductosCuenta (nodoProd * lista);

arbolCuenta * buscarMenor (arbolCuenta * main);//Funcion auxiliar a borrarCuenta

arbolCuenta * buscarMayor (arbolCuenta * main);//Funcion auxiliar a borrarCuenta

arbolCuenta * borrarCuenta (arbolCuenta * arbolCuentas, int numMesa);//Funcion auxiliar a cerrarCuenta

void cerrarCuenta(arbolCuenta ** arbolCuentas, nodoMesa ** listaMesa, nodoProd ** listaProd, char aProducto[]);//Funcion que cierrar cuenta, al menu

#endif /* Comanda_h */
