//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Comanda

#ifndef Cuentas_h
#define Cuentas_h

#include "Funciones.h"

arbolCuenta * inicArbol (void);

arbolCuenta * nuevaCuenta (arbolCuenta * arbol,arbolCuenta * nuevo);

void mostrarCuenta (nodoProd * lista);

float sumarPreciosProd (nodoProd * lista);

void mostrarComanda (arbolCuenta * comanda);

void mostrarArbolComandaenOrden (arbolCuenta * arbol);

arbolCuenta * nuevaComanda(Mesa mesa,Cliente cliente);

#endif /* Comanda_h */
