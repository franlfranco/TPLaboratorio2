//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Productos

#ifndef Productos_h
#define Productos_h

#include "Funciones.h"

nodoProd * inicListaProd (void);

nodoProd * crearNodoProd (Producto nuevo);

nodoProd * agregarProductoLista (nodoProd * lista,nodoProd * nuevo); ///EN EJECUCION

void nuevoProducto (char archivoProducto[]); ///AGREGA UN PRODUCTO AL ARCHIVO

nodoProd * archivoToListaProducto (char archivoProducto[],nodoProd * listaProd); ///CARGA DESDE EL ARCHIVO DE PRODUCTO AL ARREGLO

#endif /* Productos_h */
