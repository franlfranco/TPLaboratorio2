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

void menuCuentas(void);

void menuProductos(nodoProd * * listaProductos);

void menuListadoIndividualMesas(void);

void menuListadoMesas(void);

void menuMesas(nodoMesa * * listaMesas);

void menuListadoClientes(void);

void menuClientes(nodoMesa ** listaMesa, arbolCuenta ** arbolCuentas, Fila * espera);

void menuPrincipal(void);

#endif /* Menu_h */
