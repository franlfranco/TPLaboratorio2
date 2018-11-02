//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Productos

#ifndef Productos_h
#define Productos_h

#include "Funciones.h"

nodoProd * inicListaProd (void);

nodoProd * crearNodoProd (Producto nuevo);

nodoProd * agregarProductoLista (nodoProd * lista,nodoProd * nuevo); ///Agrega un producto a la LISTA simple de productos

int chequearProducto(char archivoProducto[],char nombre[30]);///Retorna 1 si el nombre ya esta en el archivo

Producto altaProductoArchivo(char archivoProducto[]); ///AGREGA UN PRODUCTO AL ARCHIVO

nodoProd * archivoToListaProducto (char archivoProducto[],nodoProd * listaProd); ///CARGA DESDE EL ARCHIVO DE PRODUCTO AL ARREGLO

void altaProducto(char archivoProd[], nodoProd * * listaProd);///Funcion que llama a altaLista y altaArchivo, va en el menu

void mostrarListProductos(nodoProd * listaProd);

nodoProd * bajaListaProd(nodoProd * listaProd, char nombre[30]);///Da de baja un nodo de la lista de Productos

//void bajaArchivoProducto(char archivoProducto[], char nombre[30]);///Da de baja un producto del archivo
void bajaArchivoProducto(char archivoProducto[], nodoProd * listaActualizada);

void bajaProducto(nodoProd * * listaProd,char archivoProducto[]);///Funcion que llama a bajarLista y bajarArchivo, va al menu

nodoProd * retornarNodoProductoDeLista (nodoProd * listaProducto, char nombre[]);//Busca un nodo con el nombre pasado por parametro y lo retorna

void mostrarArchivoYFilaProd (char nombreArchivo[],nodoProd * lista);// Muestra datos en el archivo productos.dat y en la lista simple de productos para verificar que los datos coincidan

int cambiarNombreProductoLista (nodoProd * * lista,char nombreAnterior[],char nombreNuevo[]);

int cambiarCantVendidosProductoLista (nodoProd * * lista,char nombreProd[],int nuevaCantidad);

int cambiarPrecioProductoLista (nodoProd * * lista,char nombreProd[],float nuevoPrecio);

void cambiarProductoArchivo (nodoProd * listaProductos,char nombreArchivoProductos[]);

void modificarProducto (char nombreArchivo[],nodoProd * * listaProductos);



#endif /* Productos_h */
