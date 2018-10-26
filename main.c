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
    
    nodoProd * listaProd;
    
    listaMesa=archivoToListaMesa(aMesas, listaMesa);
    listaProd=archivoToListaProducto(aProductos, listaProd);
    
    altaProducto(aProductos, listaProd);
    altaProducto(aProductos, listaProd);
    altaProducto(aProductos, listaProd);
    bajaProducto(listaProd, aProductos);
    
    mostrarListProductos(listaProd);
    ///testFila();
    
    //mostrarMesasLibres(listaMesa);
    
    return 0;
}
