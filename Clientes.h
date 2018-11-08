//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Clientes

#ifndef Clientes_h
#define Clientes_h

#include "Funciones.h"
#include "Mesas.h"
#include "Comanda.h"

Cliente nuevoCliente (void);//Pide nombre de cliente, retorna struct Cliente

nodoCliente * inicNodoCliente (void);

nodoCliente * crearNodoCliente (Cliente cliente);

Fila inicFila (void);

nodoCliente * agregarFinalnodoCliente (nodoCliente * lista,nodoCliente * nuevo);//Agrega Cliente al final de la LISTA de clientes

void mostrarListaCliente (nodoCliente * listaCliente);// Muestra LISTA de clientes

void agregarClienteAFila (Fila * espera,Cliente ultimo);//Agrega cliente a FILA de clientes en espera

void mostrarFilaEspera (Fila espera);//Muestra la FILA de clientes en espera

Cliente extraerClienteEspera (Fila * espera);//Quita un cliente de la FILA de clientes en espera y retorna struct Cliente

void testFila (void);//Test Falopa que va a volar en cualquier momento

void altaCliente(arbolCuenta ** arbolCuentas, nodoMesa * * listaMesa, Fila * espera);//Atiende cliente o lo manda a lista de espera, funcion al menu

void atencionClienteEspera(nodoMesa ** listaMesa, Fila * espera, arbolCuenta ** arbolCuentas);//Chequea disponibilidad de mesa y fila y atiende al primer cliente en espera.

int eliminarNodoClienteDeFila (nodoCliente * * espera,char nombre[]);

void bajaClienteEspera(Fila * espera);

void mostrarClientesYMesas (arbolCuenta * comanda);//Funcion auxiliar a mostrarClientesAtendidos

void mostrarClientesAtendidos (arbolCuenta * arbol);//Muestra todos los clientes atendidos y la mesa que ocupan.

int chequearCliente (arbolCuenta * arbolcuentas,Fila espera,char nombreNuevo[]);
#endif /* Clientes_h */
