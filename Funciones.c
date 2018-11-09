///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////

#include "Funciones.h"
#include "windows.h"

//archivos
//char aClientes[]={"Clientes.dat"};
//char aMesas[]={"Mesas.dat"};
//char aProductos[]={"Productos.dat"};

void tituloPrincipal()
{
    //system("cls");
    linea();
    printf("\t\t\t\t\tTrabajo practico final Laboratorio 2\n");
    printf("\t\t\t\tMatias Cerano - Francisco Franco - Luca Ciriaco\n");
    printf("\t\t\t\t\t\t#LaVacaBar\n");
    linea();
}






void linea()
{
    int color=9;
    for(int i=0; i<120 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        printf("%c", 196);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    }
    printf("\n");
}

void lineaRoja()
{
    int color=12;
    for(int i=0; i<120 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        printf("%c", 196);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    }
    printf("\n");
}

void lineaVerde()
{
    int color=10;
    for(int i=0; i<120 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        printf("%c", 196);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    }
    printf("\n");
}

void mediaLinea()
{
    int color=9;
    for(int i=0; i<43 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        printf("%c", 196);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    }
}
