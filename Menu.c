//Libreria con menu
#include "Menu.h"

/*
void menuAltaHabitacion(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU ALTA POR HABITACION\n");
        printf("\n\t\t[1]. Dar alta por numero de habitacion\n");
        printf("\t\t[2]. Dar alta por DNI\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                altaTodasOcupadasHabitacion();
                system("pause");
                break;
                
            case 2:
                altaTodasOcupadasDni();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuAltaEspecialidad(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU ALTA POR ESPECIALIDAD\n");
        printf("\n\t\t[1]. Dar alta por numero de habitacion\n");
        printf("\t\t[2]. Dar alta por DNI\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                altaEspecialidadHabitacion();
                system("pause");
                break;
                
            case 2:
                altaEspecialidadDni();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuAlta(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU ALTA PACIENTE\n");
        printf("\n\t\t[1]. Habitaciones ocupadas por Especialidad\n");
        printf("\t\t[2]. Todas las habitaciones ocupadas\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuAltaEspecialidad();
                break;
                
            case 2:
                menuAltaHabitacion();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuSemanaListTurnos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO TURNOS\n");
        printf("\n\t\t[1]. Libres\n");
        printf("\t\t[2]. Ocupados\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                listadoEspecialidadSemanaDisponible();
                system("pause");
                break;
                
            case 2:
                listadoEspecialidadSemanaOcupados();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuDiaListTurnos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO TURNOS\n");
        printf("\n\t\t[1]. Libres\n");
        printf("\t\t[2]. Ocupados\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                listadoEspecialidadDiaDisponible();
                system("pause");
                break;
                
            case 2:
                listadoEspecialidadDiaOcupado();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListTurnos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO TURNOS\n");
        printf("\n\t\t[1]. Por dia\n");
        printf("\t\t[2]. Por semana\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuDiaListTurnos();
                break;
                
            case 2:
                menuSemanaListTurnos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuTurnos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU TURNOS\n");
        printf("\n\t\t[1]. Dar turno\n");
        printf("\t\t[2]. Atender paciente\n");
        printf("\t\t[3]. Listados turnos por especialidad\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                system("cls");
                tituloPrincipal();
                darTurno();
                system("pause");
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                atenderPaciente();
                system("pause");
                break;
                
            case 3:
                menuListTurnos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuHabitaciones(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU HABITACIONES\n");
        printf("\n\t\t[1]. Todas las habitaciones\n");
        printf("\t\t[2]. Ocupadas por piso\n");
        printf("\t\t[3]. Desocupadas por piso\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                system("cls");
                mostrarHabitaciones();
                system("pause");
                break;
                
            case 2:
                system("cls");
                mostrarOcupado();
                system("pause");
                break;
                
            case 3:
                system("cls");
                mostrarDisponible();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuConsuListMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU CONSULTA MEDICOS\n");
        printf("\n\t\t[1]. Por matricula\n");
        printf("\t\t[2]. Por especialidad\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                consultaMatricula();
                system("pause");
                break;
                
            case 2:
                consultaEspecialidad();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuTodosListMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADOS MEDICOS\n");
        printf("\n\t\t[1]. Por matricula\n");
        printf("\t\t[2]. Por especialidad\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                listadoMedicoMatricula();
                system("pause");
                break;
                
            case 2:
                listadoMedicoEspecialidad();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADOS MEDICOS\n");
        printf("\n\t\t[1]. Todos\n");
        printf("\t\t[2]. Consulta\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuTodosListMedicos();
                break;
                
            case 2:
                menuConsuListMedicos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuModifParcialMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MODIFICACION MEDICOS\n");
        printf("\n\t\t[1]. Nombre y apellido\n");
        printf("\t\t[2]. Especialidad\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION MEDICO\n");
                modificarMedicoNombre(pedirMatricula());
                system("pause");
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION MEDICO\n");
                modificarMedicoEspecialidad(pedirMatricula());
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuModifMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MODIFICACION MEDICOS\n");
        printf("\n\t\t[1]. Parcial\n");
        printf("\t\t[2]. Total\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuModifParcialMedicos();
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION MEDICO\n");
                modificarMedico();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuMedicos(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MEDICOS\n");
        printf("\n\t\t[1]. Alta\n");
        printf("\t\t[2]. Baja\n");
        printf("\t\t[3]. Modificacion\n");
        printf("\t\t[4]. Listados\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                system("cls");
                cargaMedico();
                system("pause");
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                bajaMedico();
                system("pause");
                break;
                
            case 3:
                menuModifMedicos();
                break;
                
            case 4:
                menuListMedicos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuConsuListPaciente(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU CONSULTA LISTADO PACIENTE\n");
        printf("\n\t\t[1]. Por DNI\n");
        printf("\t\t[2]. Por nombre\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                consultaDni();
                system("pause");
                break;
                
            case 2:
                consultaNombre();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuTodosListPaciente(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU TODOS LISTADO PACIENTE\n");
        printf("\n\t\t[1]. Ordenado por nombre\n");
        printf("\t\t[2]. Ordenado por veces atendido\n");
        printf("\t\t[3]. Ordenado por veces internado\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                listadoPacienteNombre();
                system("pause");
                break;
                
            case 2:
                listadoPacienteAtendido();
                system("pause");
                break;
                
            case 3:
                listadoPacienteInternado();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuListPaciente(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU LISTADO PACIENTE\n");
        printf("\n\t\t[1]. Todos\n");
        printf("\t\t[2]. Consulta\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuTodosListPaciente();
                break;
                
            case 2:
                menuConsuListPaciente();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

void menuModifParcialPaciente(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MODIFICACION PARCIAL PACIENTE\n");
        printf("\n\t\t[1]. Nombre y apellido\n");
        printf("\t\t[2]. Edad\n");
        printf("\t\t[3]. Cantidad de veces atendido\n");
        printf("\t\t[4]. Cantidad de veces internado\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION PACIENTE\n");
                modificarPacienteNombre(pedirDni());
                system("pause");
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION PACIENTE\n");
                modificarPacienteEdad(pedirDni());
                system("pause");
                break;
                
            case 3:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION PACIENTE\n");
                modificarPacienteCantAtendido(pedirDni());
                system("pause");
                break;
                
            case 4:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION PACIENTE\n");
                modificarPacienteCantInternado(pedirDni());
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
    } while (repite);
}

void menuModifPaciente(){
    char repite = 1;
    int opcion = -1;
    
    do {
        system("cls");//NO FUNCIONA EN MAC, SOLO EN WINDOWS
        tituloPrincipal();
        
        printf("\n\t\t\t\tSUBMENU MODIFICACION PACIENTE\n");
        printf("\n\t\t[1]. Parcial\n");
        printf("\t\t[2]. Total\n");
        printf("\t\t[0]. Volver\n");
        printf("\n\t\tIngrese su opcion: ");
        fflush(stdin);
        scanf(" %i",&opcion );
        
        switch (opcion) {
                
            case 1:
                menuModifParcialPaciente();
                break;
                
            case 2:
                system("cls");
                tituloPrincipal();
                printf("\n\t\t\t\tMODIFICACION PACIENTE\n");
                modificarPaciente();
                system("pause");
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}*/

void menuListadoClientes(){
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
                //altaCliente;
                break;
                
            case 2:
                //atencionCliente
                break;
                
            case 3:
                //bajaCliente
                break;
            
            case 4:
                //menuListadoClientes();
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
    
    //generarHabitacion();
    
    
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
                //menuClientes();
                break;
            case 2:
                //menuMesas();
                break;
                
            case 3:
                //menuProductos();
                break;
                
            case 0:
                repite = 0;
                break;
        }
        
    } while (repite);
}

