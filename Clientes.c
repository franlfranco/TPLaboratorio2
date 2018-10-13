//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar
//Libreria clientes

#include "Clientes.h"

/*typedef struct{ // Lista doble de clientes
 char nombre[20];
 int atendido; // variable booleana
 } Cliente;*/



Cliente altaCliente(void){
    char nombre[20];
    Cliente cliente;
    
    system("cls");
    tituloPrincipal();
    printf("\n\t\t\tNombre: ");
    fflush(stdin);
    scanf("%s",nombre);
    
    strcpy(cliente.nombre, nombre);
    cliente.atendido=0;

    return cliente;
}
