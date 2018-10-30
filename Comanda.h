//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Comanda

#ifndef Cuentas_h
#define Cuentas_h

#include "Funciones.h"

arbolCuenta * inicArbol (void);

arbolCuenta * agregarHojaArbolCuentas (arbolCuenta * arbol,arbolCuenta * nuevo);

void mostrarCuenta (nodoProd * lista);

float sumarPreciosProd (nodoProd * lista);

void mostrarComanda (arbolCuenta * comanda);

void mostrarArbolComandaenOrden (arbolCuenta * arbol);

int ocuparMesa (nodoMesa ** lista,Mesa * pedida,int nro);

arbolCuenta * crearHojaComanda(Mesa mesa,Cliente cliente);

arbolCuenta * ingresarClienteANodoArbol (nodoMesa * * listaMesa, Cliente nuevoCliente);//Ingresa un cliente a un nodoArbol, y asigna mesa

#endif /* Comanda_h */
