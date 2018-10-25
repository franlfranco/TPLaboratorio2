//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar

#include "Menu.h"

int main() {
    char aClientes[]={"Clientes.dat"};
    char aMesas[]={"Mesas.dat"};
    char aProductos[]={"Productos.dat"};
    char aMesasTemp[]={"MesasTemp.dat"};
    
    nodoMesa * listaMesa;
    listaMesa=inicListaMesa();
    
    listaMesa=archivoToListaMesa(aMesas, listaMesa);
    
    testFila();
    
    return 0;
}
