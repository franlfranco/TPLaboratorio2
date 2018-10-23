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
    
    //for (int i=0; i<10; i++) {
      //  nuevaMesaArchivo(aMesas, buscarUltimaMesaArchivo(aMesas));
    //}
    
    listaMesa=archivoToListaMesa(aMesas, listaMesa);
    
    /*
    mostrarMesasLibres(listaMesa);
    
    bajaArchivoMesa(aMesas, aMesasTemp, 10);
    
    printf("\nDespues de borrar\n");
    
    mostrarMesasLibres(listaMesa);
    
    //menuPrincipal();
     */
    printf("Antes\n");
    mostrarMesasLibres(listaMesa);
    
    altaMesa(aMesas, listaMesa);
    
    printf("Despues\n");
    mostrarMesasLibres(listaMesa);
    
    bajaMesa(listaMesa, aMesas, aMesasTemp);
    
    printf("Despues de borrar\n");
    mostrarMesasLibres(listaMesa);
    
    return 0;
}
