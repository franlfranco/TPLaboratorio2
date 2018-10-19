//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar

#include "Menu.h"

int main() {
    char aClientes[]={"Clientes.dat"};
    char aMesas[]={"Mesas.dat"};
    char aProductos[]={"Productos.dat"};
    
    nodoMesa * listaMesa;
    listaMesa=inicListaMesa();
    
    for (int i=0; i<10; i++) {
        nuevaMesa(aMesas, buscarUltimaMesa(aMesas));
    }
    
    
    listaMesa=archivoToListaMesa(aMesas, listaMesa);
    
    mostrarMesasLibres(listaMesa);
    
    
    //menuPrincipal();
    return 0;
}
