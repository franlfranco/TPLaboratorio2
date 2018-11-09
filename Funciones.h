///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////

#ifndef Funciones_h
#define Funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define aMesas "mesas.dat"
#define aProductos "productos.dat"

//Estructuras
typedef struct{ // Lista de productos
    char nombre[30];
    float precio;
    int cantVendidos;
}Producto;

typedef struct{ // Lista doble de clientes
    char nombre[20];
    int atendido; // variable booleana
}Cliente;

typedef struct{ // Lista simple de mesas
    int numero;//Identificacion de la mesa
    int ocupada; // variable booleana
}Mesa;

typedef struct{
    Producto prod;
    struct nodoProd * sig;
}nodoProd;

typedef struct{
    Cliente cliente;
    struct nodoCliente * sig;
    struct nodoCliente * ante;
}nodoCliente;

typedef struct{ // Fila de clientes
    struct nodoCliente * cabecera;
    struct nodoCliente * ultimo;
}Fila;

typedef struct{
    Mesa mesa;
    struct nodoMesa * sig;
}nodoMesa;

typedef struct{
    Mesa mesa;
    Cliente cliente;
    nodoProd * listaProd;
    struct arbolCuenta * der;
    struct arbolCuenta * izq;
}arbolCuenta;

void tituloPrincipal(void);

#endif /* Funciones_h */
