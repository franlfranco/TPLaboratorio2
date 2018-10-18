//
//  Funciones.h
//  TPFinalLabo2
//
//  Created by Francisco Franco on 12/10/2018.
//  Copyright © 2018 Francisco Franco. All rights reserved.
//

#ifndef Funciones_h
#define Funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//archivos
//char aClientes[]={"Clientes.dat"};
//char aMesas[]={"Mesas.dat"};
//char aProductos[]={"Productos.dat"};

//Estructuras
typedef struct{ // Lista de productos
    char nombre[20];
    int precio;
    int cantidad;
} Producto;

typedef struct{ // Lista doble de clientes
    char nombre[20];
    int atendido; // variable booleana
} Cliente;

typedef struct{ // Lista simple de mesas
    int numero;//Identificacion de la mesa
    int sucursal;
    int ocupada; // variable booleana
} Mesa;

typedef struct{
    Producto producto;
    struct nodoProducto * sig;
}nodoProducto;

typedef struct{
    Cliente cliente;
    struct nodoCliente * sig;
    struct nodoCliente * ante;
} nodoCliente;

typedef struct{ // Fila de clientes
    struct nodoCliente * cabecera;
    struct nodoCliente * cola;
} Fila;

typedef struct{
    Mesa mesa;
    struct nodoMesa * sig;
} nodoMesa;

typedef struct{
    Mesa mesa;
    Cliente cliente;
    Producto producto[20];
    struct arbolCuenta * der;
    struct arbolCuenta * izq;
}arbolCuenta;

typedef struct{
    arbolCuenta * arbol;
    struct sucursal * sig;
} sucursal;

void tituloPrincipal(void);

#endif /* Funciones_h */
