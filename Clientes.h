//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Clientes

#ifndef Clientes_h
#define Clientes_h

#include "Funciones.h"

Cliente nuevoCliente (void); // Pide nombre de cliente y retorna el dato Cliente

nodoCliente * inicNodoCliente (void);

nodoCliente * crearNodoCliente (Cliente cliente);

Fila inicFila (void);

nodoCliente * agregarFinalnodoCliente (nodoCliente * lista,nodoCliente * nuevo);

void mostrarListaCliente (nodoCliente * listaCliente);

void agregarClienteAFila (Fila * espera,Cliente ultimo);

void mostrarFilaEspera (Fila espera);

Cliente extraerClienteEspera (Fila * espera);

void testFila (void);

#endif /* Clientes_h */
