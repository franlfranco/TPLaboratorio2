//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar

#include "Menu.h"






int main() {
    //ejecutarMain();
    menuPrincipal();
    arbolCuenta * comanda=inicArbol();
    arbolCuenta * test=inicArbol();
    Mesa testMesa;
    testMesa.numero=1;
    testMesa.ocupada=1;
    Cliente testCl;
    strcpy(testCl.nombre,"Matias");
    testCl.atendido=1;

    test=crearHojaComanda(testMesa,testCl);
    comanda=agregarHojaArbolCuentas(comanda,test);


    if(buscarComandaPorNroMesa(comanda,1))
    {
        mostrarComanda(buscarComandaPorNroMesa(comanda,1));
    }
    else
    {
        puts("No se encontro por numero");
    }

    /*
    if(!mostrarComandaPorNroMesa(comanda,1))
    {
        printf("No se encuentra la mesa por el numero\n");
    }
    if(!mostrarComandaPorCliente(comanda,"Matias"))
    {
        printf("No se encuentra la mesa por el nombre\n");
    }*/
    return 0;
}
