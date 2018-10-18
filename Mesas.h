//
//  Mesas.h
//  TPFinalLabo2
//
//  Created by Francisco Franco on 12/10/2018.
//  Copyright © 2018 Francisco Franco. All rights reserved.
//

#ifndef Mesas_h
#define Mesas_h

#include "Funciones.h"

nodoMesa * inicListaMesa(void);

Mesa crearMesa(int numero);

nodoMesa * crearNodoMesa(Mesa mesa);

nodoMesa * buscarUltimoNodoMesa(nodoMesa * listaMesa);

nodoMesa * agregarMesaFinal(nodoMesa * listaMesa, nodoMesa * nuevo);

int buscarUltimaMesa(nodoMesa * listaMesa);

void mostrarMesa(nodoMesa * aux);

void mostrarMesasLibres(nodoMesa * listaMesa);

#endif /* Mesas_h */
