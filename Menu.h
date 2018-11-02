//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Menu

#ifndef Menu_h
#define Menu_h

#include "Funciones.h"
#include "Clientes.h"
#include "Mesas.h"
#include "Productos.h"
#include "Comanda.h"

void menuCuentas(arbolCuenta ** arbolCuentas,nodoProd * listaProductos);

void menuProductos(nodoProd * * listaProductos);

void menuListadoIndividualMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas);

void menuListadoMesas(nodoMesa * listaMesa, arbolCuenta * arbolCuentas);

void menuMesas(nodoMesa * * listaMesas, arbolCuenta * arbolCuentas);

void menuListadoClientes(Fila * espera, arbolCuenta * arbolCuentas);

void menuClientes(nodoMesa ** listaMesa, arbolCuenta ** arbolCuentas, Fila * espera);

void menuPrincipal(void);

#endif /* Menu_h */
