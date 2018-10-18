//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar

#include "Menu.h"

int main() {
    nodoMesa * listaMesa;
    listaMesa=inicListaMesa();
    listaMesa=agregarMesaFinal(listaMesa,crearNodoMesa(crearMesa(buscarUltimaMesa(listaMesa)+1)));
    listaMesa=agregarMesaFinal(listaMesa,crearNodoMesa(crearMesa(buscarUltimaMesa(listaMesa)+1)));
    listaMesa=agregarMesaFinal(listaMesa,crearNodoMesa(crearMesa(buscarUltimaMesa(listaMesa)+1)));
    
    mostrarMesasLibres(listaMesa);
    //menuPrincipal();
    return 0;
}
