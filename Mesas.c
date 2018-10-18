//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar
//Libreria Mesas

#include "Mesas.h"

nodoMesa * inicListaMesa(void){
    return NULL;
}

Mesa crearMesa(int numero){
    Mesa nueva;
    
    nueva.ocupada=0;
    nueva.numero=numero;
    
    return nueva;
}

nodoMesa * crearNodoMesa(Mesa mesa){
    nodoMesa * aux=(nodoMesa*)malloc(sizeof(nodoMesa));
    aux->mesa=mesa;
    aux->sig=NULL;
    return aux;
}

nodoMesa * buscarUltimoNodoMesa(nodoMesa * listaMesa){
    nodoMesa * aux=listaMesa;
    while(aux->sig){
        aux=aux->sig;
    }
    return aux;
}

nodoMesa * agregarMesaFinal(nodoMesa * listaMesa, nodoMesa * nuevo){
    if(!listaMesa){
        listaMesa=nuevo;
    }else{
        nodoMesa * aux=buscarUltimoNodoMesa(listaMesa);
        aux->sig=nuevo;
    }
    return listaMesa;
}

int buscarUltimaMesa(nodoMesa * listaMesa){//Funcion que retorna la cantidad de mesas cargadas
    int rta=0;
    if(listaMesa){
        nodoMesa * cursor=listaMesa;
        while (cursor) {
            cursor=cursor->sig;
            rta++;
        }
    }
    return rta;
}

void mostrarMesa(nodoMesa * aux){
    printf("\nNumero mesa: %i",aux->mesa.numero);
    printf("\nOcupada: %i\n",aux->mesa.ocupada);
}

void mostrarMesasLibres(nodoMesa * listaMesa){
    if(listaMesa){
        if(listaMesa->mesa.ocupada==0){
            mostrarMesa(listaMesa);
            mostrarMesasLibres(listaMesa->sig);
        }
    }
}
