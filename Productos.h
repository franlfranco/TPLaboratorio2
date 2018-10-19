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

nodoProd * archivoToListaProducto (char archivoProducto[],nodoProd * listaProd){ ///CARGA DESDE EL ARCHIVO DE PRODUCTO AL ARREGLO
    if(fopen(archivoProducto,"rb"))
    {
        FILE * archi=fopen(archivoProducto,"rb");
        Producto aux;
        while(fread(&aux,sizeof(Producto),1,archi)>0)
        {
            listaProd=agregarProductoLista(listaProd,crearNodoProd(aux));
        }
    }
    else
    {
        printf("No se encontro el archivo...");
        listaProd=inicListaProd();
    }
    return listaProd;
}


#endif /* Productos_h */
