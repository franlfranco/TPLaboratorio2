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

nodoMesa * buscarUltimaMesaLista(nodoMesa * listaMesa);//Retorna el ultimo nodo de la lista de mesas

nodoMesa * agregarFinalListaMesa(nodoMesa * listaMesa, nodoMesa * nuevo);//Agrega una mesa al final de la LISTA de mesas

void altaMesa(char archivoMesas[], nodoMesa * * listaMesas);//Llama a las funciones que agregan Mesa al archivo y a la lista, FUNCION AL MENU

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa); //Carga la LISTA mesa con los datos del archivo

void mostrarMesa(nodoMesa * aux);//Muestra los datos de un nodoMesa

void mostrarMesasLibres(nodoMesa * listaMesa);//Llama a mostrarMesa con todos los nodos de la lista de mesa

nodoMesa * bajaMesaLista(nodoMesa * listaMesa);

//void bajaArchivoMesa(char archivoMesa[], char archivoMesaTemporal[], int pos);

void bajaMesa(nodoMesa * * listaMesa, char archivoMesa[]);

int chequearDisponibilidadMesas(nodoMesa * listaMesa);//Retorna cantidad de mesas libres, 0 si estan todas ocupadas

///testeo
void bajaArchivoMesa(char archivoMesa[],nodoMesa * listaMesasActualizada);

void mostrarArchivoYFilaMesa (char nombreArchivo[],nodoMesa * lista);

#endif /* Mesas_h */
