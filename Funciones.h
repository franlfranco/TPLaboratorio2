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

//void imprimir(void);

typedef struct{ // Arbol de productos
    char nombre[20];
    int precio;
    int cantidad;
    struct Producto * izq;
    struct Producto * der;
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

typedef struct{ // Lista simple de mesas
    Producto productos[20];
    Cliente cliente;
    int ocupada; // variable booleana
    struct Mesa * sig;
} Mesa;

void tituloPrincipal(void);

#endif /* Funciones_h */
