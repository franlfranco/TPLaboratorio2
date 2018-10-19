//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Menu

#include "Menu.h"

void menuListadoProductos(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO PRODUCTOS\n");
        printf("\n\t\t[1]. Por Producto\n");
        printf("\t\t[2]. Por tipo\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //mostrarProducto();
                break;
                
            case 2:
                //mostrarProductoTipo();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuProductos(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU TODOS LISTADO PACIENTE\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. Modificacion\n");
        printf("\t\t[4]. Listado\n");
        printf("\t\t[5]. Venta en barra\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //altaProducto();
                break;
                
            case 2:
                //bajaProducto();
                break;
                
            case 3:
                //modificacionProducto();
                break;
                
            case 4:
                menuListadoProductos();
                break;
                
            case 5:
                //ventaBarra();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuMesasIndividual(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MESAS INDIVIDUAL\n");
        printf("\n\t\t[1]. Por numero mesa\n");
        printf("\t\t[2]. Por nombre cliente\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //mostrarMesaIndividualNumero();
                break;
                
            case 2:
                //mostrarMesaIndividualNombre();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListadoMesas(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADOS MESAS\n");
        printf("\n\t\t[1]. Individual\n");
        printf("\t\t[2]. Todas\n");
        printf("\t\t[3]. Ocupadas\n");
        printf("\t\t[4]. Libres\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuMesasIndividual();
                break;
                
            case 2:
                //mostrarMesasTodas();
                break;
                
            case 3:
                //mostrarMesasOcupadas();
                break;
                
            case 4:
                //mostrarMesasLibres();
                break;
                
            case 0:
                repite = 0;
                break;
        }
    } while (repite);
}

void menuMesas(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MESAS\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. Listado\n");
        printf("\t\t[4]. Modificar\n");
        printf("\t\t[5]. Cerrar\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //altaMesa();
                break;
                
            case 2:
                //bajaMesa();
                break;
            
            case 3:
                menuListadoMesas();
                break;
                
            case 4:
                //modificarMesa();//agregar y sacar productos al array Productos en el struct Mesa
                break;
                
            case 5:
                //cerrarMesa();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListadoClientes(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO CLIENTES\n");
        printf("\n\t\t[1]. Todos\n");
        printf("\t\t[2]. Atendidos\n");
        printf("\t\t[3]. En espera\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //mostrarTodosClientes
                break;
                
            case 2:
                //mostrarClientesAtendidos
                break;
                
            case 3:
                //mostrarClientesEspera
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuClientes(void){
    char repite = 1;
    int opcion = -1;
    //Cliente aux;
    
    do {
        system("cls");
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU CLIENTES\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Atención\n");
        printf("\t\t[3]. Baja\n");
        printf("\t\t[4]. Listado\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                //aux=altaCliente();
                break;
                
            case 2:
                //atencionCliente
                break;
                
            case 3:
                //bajaCliente
                break;
            
            case 4:
                menuListadoClientes();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuPrincipal(void){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");
        tituloPrincipal();
        
        printf("\n\t\t\t\tMENU PRINCIPAL\n");
        printf("\n\t\t[1]. Clientes\n");
        printf("\t\t[2]. Mesas\n");
        printf("\t\t[3]. Productos\n");
        printf("\t\t[0]. Salir\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuClientes();
                break;
            case 2:
                menuMesas();
                break;
                
            case 3:
                menuProductos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

