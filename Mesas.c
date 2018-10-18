//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar
//Libreria Mesas

#include "Mesas.h"

nodoMesa * inicListaMesa(void){
    return NULL;
}

Mesa crearMesa(int sucursal, int ultimaMesa){
    Mesa nueva;
    nueva.ocupada=0;
    nueva.numero=ultimaMesa+1;
    
    return nueva;
}

nodoMesa * crearNodoMesa(Mesa mesa){
    nodoMesa * aux=(nodoMesa*)malloc(sizeof(nodoMesa));
    aux->mesa=mesa;
    aux->sig=NULL;
    return aux;
}



int buscarUltimaMesa(nodoMesa * listaMesa){
    int rta=0;
    
}

nodoMesa * altaMesa(nodoMesa * listaMesa, n){
    int sucursal;
    
    printf("\n\t\t\t------- CARGA MESA -------\n");
    printf("\t\tSucursal: ");
    fflush(stdin);
    scanf("%i",&sucursal);
    
    crearNodoMesa(crearMesa(sucursal,buscarUltimaMesa()))
}
