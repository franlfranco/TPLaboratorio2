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
    struct Producto * sig;
} Producto;

typedef struct{ // Lista doble de clientes
    char nombre[20];
    int atendido; // variable booleana
} Cliente;

typedef struct{ // Fila de clientes
    Cliente cliente;
    struct Fila * cabecera;
    struct Fila * cola;
} Fila;

typedef struct{ // Arbol de mesas
    int numero;//Identificacion de la mesa
    Producto productos[20];
    Cliente cliente;
    int ocupada; // variable booleana
    struct Mesa * izq;
    struct Mesa * der;
} Mesa;

void tituloPrincipal(void);

#endif /* Funciones_h */
