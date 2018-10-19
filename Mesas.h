//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Mesas

#ifndef Mesas_h
#define Mesas_h

#include "Funciones.h"

nodoMesa * inicListaMesa(void);

nodoMesa * crearNodoMesa(Mesa mesa);

nodoMesa * buscarUltimoNodoMesa(nodoMesa * listaMesa);

nodoMesa * agregarMesaFinal(nodoMesa * listaMesa, nodoMesa * nuevo);

void nuevaMesa (char archivoMesas[],int ultimaMesa); ///AGREGA UNA MESA AL ARCHIVO CON EL NUMERO ULTIMO+1

int buscarUltimaMesa (char archivoMesas[]); ///RETORNA ULTIMO NUMERO DE MESA / 0 SI NO HAY ARCHIVO

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa); ///CARGA DESDE EL ARCHIVO DE MESA A LA LISTA

void mostrarMesa(nodoMesa * aux);

void mostrarMesasLibres(nodoMesa * listaMesa);


#endif /* Mesas_h */
