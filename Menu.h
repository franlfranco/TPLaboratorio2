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

void menunodoClienteoProductos(void);
void menuProductos(nodoProd * * listaProductos);
void menuMesas(nodoMesa * * listaMesas);
void menunodoClienteoClientes(void);
void menuClientes(void);
void menuPrincipal(void);




#endif /* Menu_h */
