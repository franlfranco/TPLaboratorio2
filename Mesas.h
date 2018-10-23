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

Mesa nuevaMesaArchivo (char archivoMesas[],int ultimaMesa); ///AGREGA UNA MESA AL ARCHIVO CON EL NUMERO ULTIMO+1

int buscarUltimaMesaArchivo (char archivoMesas[]); ///RETORNA ULTIMO NUMERO DE MESA / 0 SI NO HAY ARCHIVO

nodoMesa * buscarUltimaMesaLista(nodoMesa * listaMesa);

nodoMesa * nuevaMesaLista(nodoMesa * listaMesa, nodoMesa * nuevo);

void altaMesa(char archivoMesas[], nodoMesa * listaMesas);

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa); ///CARGA DESDE EL ARCHIVO DE MESA A LA LISTA

void mostrarMesa(nodoMesa * aux);

void mostrarMesasLibres(nodoMesa * listaMesa);

nodoMesa * bajaMesaLista(nodoMesa * listaMesa);

void bajaArchivoMesa(char archivoMesa[], char archivoMesaTemporal[], int pos);

void bajaMesa(nodoMesa * listaMesa, char archivoMesa[], char archivoMesaTemporal[]);

#endif /* Mesas_h */
