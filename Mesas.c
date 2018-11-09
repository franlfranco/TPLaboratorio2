///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
#include "Mesas.h"

nodoMesa * inicListaMesa(void){
    return NULL;
}

nodoMesa * crearNodoMesa(Mesa mesa){
    nodoMesa * aux=(nodoMesa*)malloc(sizeof(nodoMesa));
    aux->mesa=mesa;
    aux->sig=NULL;
    return aux;
}

nodoMesa * buscarUltimoNodoMesa(nodoMesa * listaMesa){//Busca ultimo nodo de la LISTA mesa
    nodoMesa * aux=listaMesa;
    while(aux->sig){
        aux=aux->sig;
    }
    return aux;
}

nodoMesa * agregarMesaFinal(nodoMesa * listaMesa, nodoMesa * nuevo){
    if(!listaMesa){
        listaMesa=nuevo;
    }else{
        nodoMesa * aux=buscarUltimoNodoMesa(listaMesa);
        aux->sig=nuevo;
    }
    return listaMesa;
}

Mesa nuevaMesaArchivo (char archivoMesas[],int ultimaMesa){ ///AGREGA UNA MESA AL ARCHIVO CON EL NUMERO ULTIMO+1
    Mesa nueva;
    nueva.numero=ultimaMesa+1;
    nueva.ocupada=0;
    FILE * archi=fopen(archivoMesas,"ab");
    fwrite(&nueva,sizeof(Mesa),1,archi);
    fclose(archi);
    printf("Carga de la mesa nro: %i fue exitosa\n",nueva.numero);
    system("pause");
    system("cls");
    return nueva;
}

int buscarUltimaMesaArchivo (char archivoMesas[]){ ///RETORNA ULTIMO NUMERO DE MESA / 0 SI NO HAY ARCHIVO
    int rta=0;
    if(fopen(archivoMesas,"rb"))
    {
        Mesa aux;
        FILE * archi=fopen(archivoMesas,"rb");
        fseek(archi,sizeof(Mesa)*-1,SEEK_END);
        if(fread(&aux,sizeof(Mesa),1,archi)>0)
            rta=aux.numero;
        fclose(archi);
    }
    else
    {
        printf("Archivo - %s - no encontrado...\n",archivoMesas);
    }
    return rta;
}

nodoMesa * buscarUltimaMesaLista(nodoMesa * listaMesa){
    if(listaMesa){
        while(listaMesa->sig){
            listaMesa=listaMesa->sig;
        }
    }
    return listaMesa;
}

nodoMesa * agregarFinalListaMesa(nodoMesa * listaMesa, nodoMesa * nuevo){
    nodoMesa * ultimo=buscarUltimaMesaLista(listaMesa);
    if(listaMesa){
        ultimo->sig=nuevo;
    }else{
        listaMesa=nuevo;
    }
    return listaMesa;
}

void altaMesa(char archivoMesas[], nodoMesa * * listaMesas){
    Mesa nueva=nuevaMesaArchivo(archivoMesas, buscarUltimaMesaArchivo(archivoMesas));
    *listaMesas=agregarFinalListaMesa(*listaMesas, crearNodoMesa(nueva));
}

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa){ ///CARGA DESDE EL ARCHIVO DE MESA A LA LISTA, RETORNA VALIDOS
    listaMesa=inicListaMesa();
    if(fopen(archivoMesas,"rb"))
    {
        FILE * archi=fopen(archivoMesas,"rb");
        Mesa aux;
        while(fread(&aux,sizeof(Mesa),1,archi)>0)
        {
            listaMesa=agregarMesaFinal(listaMesa, crearNodoMesa(aux));
        }
        fclose(archi);
    }
    else
    {
        printf("No se encontro el archivo...Creando %s\n",archivoMesas); ///Si no encuentra el archivo, lo crea...
        fopen(archivoMesas,"wb");
    }
    return listaMesa;
}

void mostrarMesa(int nro, int ocupada, char nombreCliente[30]){
    printf("\nNumero mesa: %i",nro);
    if (ocupada) {
        printf("\nCliente: %s\n",nombreCliente);
    }else{
        printf("\nLIBRE\n");
    }
}

void mostrarMesasLibres (nodoMesa * lista) ///MUESTRA MESAS LIBRES, RETORNA CANTIDAD / 0 SI NO HAY
{
    printf("\n--Mesas libres--\n");
    while(lista)
    {
        if(lista->mesa.ocupada==0)
        {
            printf("Mesa: %i\n",lista->mesa.numero);
        }
        lista=lista->sig;
    }
}

nodoMesa * bajaMesaLista(nodoMesa * listaMesa){
    if(listaMesa){
        if(!listaMesa->sig){
            free(listaMesa);
            listaMesa=inicListaMesa();
        }else{
            nodoMesa * cursor=listaMesa->sig;
            nodoMesa * ante=listaMesa;
            while (cursor->sig) {
                ante=cursor;
                cursor=cursor->sig;
            }
            ante->sig=NULL;
            free(cursor);
        }
    }
    return listaMesa;
}

void bajaArchivoMesa(char archivoMesa[],nodoMesa * listaMesasActualizada)
{
    if(listaMesasActualizada)
    {
        FILE * archivo=fopen(archivoMesa,"wb");
        Mesa aux;
        while(listaMesasActualizada)
        {
            aux=listaMesasActualizada->mesa;
            if(aux.ocupada==1)
                aux.ocupada=0;
            fwrite(&aux,sizeof(Mesa),1,archivo);
            listaMesasActualizada=listaMesasActualizada->sig;
        }
        fclose(archivo);
    }
    else
    {
        FILE * archivo=fopen(archivoMesa,"wb");
        fclose(archivo);
    }
}

void bajaMesa(nodoMesa * * listaMesa, char archivoMesa[]){
    if(*listaMesa)
    {
        nodoMesa * ultimo=buscarUltimoNodoMesa(*listaMesa);
        if(ultimo->mesa.ocupada==0){
                *listaMesa=bajaMesaLista(*listaMesa);
                bajaArchivoMesa(archivoMesa,*listaMesa);
            printf("Se elimino la mesa correctamente\n");
        }else{
            printf("La mesa numero %i esta ocupada\n",ultimo->mesa.numero);

        }
    }
    else
    {
        printf("No hay mesas para dar de baja...\n");
    }
system("pause");
}

int chequearDisponibilidadMesas(nodoMesa * listaMesa){
    int rta=0;
    while(listaMesa){
        if(!listaMesa->mesa.ocupada){
            rta++;
        }
        listaMesa=listaMesa->sig;
    }
    return rta;
}

void mostrarArchivoYFilaMesa (char nombreArchivo[],nodoMesa * lista)
{
    FILE * archi=fopen(nombreArchivo,"rb");
    Mesa aux;
    printf("\nArchivo:\n");
    while(fread(&aux,sizeof(Mesa),1,archi)>0)
    {
        printf("| [%.2i] |",aux.numero);
    }
    printf("\nLista:\n");
    while(lista)
    {
        printf("| [%.2i] |",lista->mesa.numero);
        lista=lista->sig;
    }
    printf("\n");
}

int chequearExistenciaMesa(nodoMesa * listaMesa, int nro){
    int flag=0;
    while (listaMesa&&!flag) {
        if(listaMesa->mesa.numero==nro){
            flag=1;
        }else{
            listaMesa=listaMesa->sig;
        }
    }
    return flag;
}

void mostrarMesaIndividualXNumero(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    int nro;

    printf("\nIngrese el numero de mesa a mostrar: ");
    fflush(stdin);
    scanf("%i",&nro);
    if (chequearExistenciaMesa(listaMesa, nro)) {
        arbolCuenta * aux=inicArbol();
        aux=buscarComandaPorNroMesa(arbolCuentas, nro);
        if(aux){
            mostrarMesa(nro, 1, aux->cliente.nombre);
        }else{
            mostrarMesa(nro, 0, " ");
        }
    }else{
        printf("La mesa no existe.\n");
    }
}

void mostrarMesaIndividualXNombre(nodoMesa * listaMesa, arbolCuenta * arbolCuentas){
    //int nro;
    char nombre[30];
    //printf("\nIngrese el numero de mesa a mostrar: ");
    printf("\nIngrese el nombre del cliente a mostrar: ");
    fflush(stdin);
    //scanf("%i",&nro);
    scanf("%s",nombre);
    arbolCuenta * aux=inicArbol();
    aux=buscarComandaPorCliente(arbolCuentas,nombre);
    if(aux)
    {
        mostrarMesa(aux->mesa.numero,1,aux->cliente.nombre);
    }
    else
    {
        printf("\nEl cliente ingresado no se encuentra ocupando una mesa.\n");
    }
}

void mostrarTodasLasMesas (nodoMesa * listaMesas,arbolCuenta * arbolCuentas)
{
    arbolCuenta * aux;
    while(listaMesas)
    {
        if(listaMesas->mesa.ocupada==0)
        {
            mostrarMesa(listaMesas->mesa.numero,0,"");
        }
        else
        {
            aux=buscarComandaPorNroMesa(arbolCuentas,listaMesas->mesa.numero);
            mostrarMesa(aux->mesa.numero,1,aux->cliente.nombre);
        }
        listaMesas=listaMesas->sig;
    }
}

void mostrarMesasOcupadas (nodoMesa * lista) ///MUESTRA MESAS OCUPADAS
{
    printf("\n--Mesas ocupadas--\n");
    while(lista)
    {
        if(lista->mesa.ocupada==1)
        {
            printf("Mesa: %i\n",lista->mesa.numero);
        }
        lista=lista->sig;
    }
}

void mostrarEstadisticasMesas(nodoMesa * listaMesas, arbolCuenta * arbolCuentas){
    if(listaMesas){
        nodoMesa * cursor=listaMesas;
        float gastosTotales=sumarGastosMesas(arbolCuentas);
        printf("\nMontos por mesas\n");
        printf("Numero | Total | Frecuencia relativa\n");
        printf("-------------------------------\n");
        while (cursor) {
            if (cursor->mesa.ocupada) {
                arbolCuenta * cuenta=buscarComandaPorNroMesa(arbolCuentas, cursor->mesa.numero);
                int numero=cuenta->mesa.numero;
                float total=sumarPreciosProd(cuenta->listaProd);
                float fr=0;
                if(total>0)
                    fr=(total*100)/gastosTotales;
                printf("\n     %i| $%.2f | %.2f %% \n",numero,total,fr);
                printf("-------------------------------\n");
            }else{
                printf("\n     %i|  $-   |  -   %%\n",cursor->mesa.numero);
                printf("-------------------------------\n");
            }
            cursor=cursor->sig;
        }
        if(gastosTotales){
            float promedio=calcularPromedioGastoMesas(listaMesas,arbolCuentas);
            printf("\nEl promedio de venta por mesa es: %.2f \n",promedio);
        }else{
            printf("\nNo se registran ventas\n");
        }
    }else{
        printf("No hay mesas cargadas.\n");
    }
}

int contarMesasOcupadas (nodoMesa * listaMesas)
{
    int rta=0;
    while(listaMesas)
    {
        if(listaMesas->mesa.ocupada==1)
        {
            rta++;
        }
        listaMesas=listaMesas->sig;
    }
return rta;
}

float calcularPromedioGastoMesas(nodoMesa * listaMesas, arbolCuenta * arbolCuentas){ ///RETORNA PROMEDIO DE GASTO DE MESAS (-1 SI NO HAY MESAS OCUPADAS)
    float rta;
    if(arbolCuentas)
    {
        int n=contarMesasOcupadas(listaMesas); ///OK
        float promedio;
        promedio=sumarGastosMesas(arbolCuentas)/(float)n;
        rta=promedio;
    }
    else
        rta=-1;
return rta;
}

void desocuparMesa(nodoMesa ** listaMesas, int numMesa){
    int flag=0;
    if(*listaMesas){
        nodoMesa * cursor=*listaMesas;
        while (cursor && flag==0) {
            if(cursor->mesa.numero==numMesa){
                cursor->mesa.ocupada=0;
                flag=1;
            }else{
                cursor=cursor->sig;
            }
        }
    }
}

int chequearMesaOcupada(nodoMesa * listaMesa, int numMesa){
    int flag=0;
    if(listaMesa){
        while (listaMesa&&!flag) {
            if(listaMesa->mesa.numero==numMesa && listaMesa->mesa.ocupada){
                flag=1;
            }else{
                listaMesa=listaMesa->sig;
            }
        }
    }
    return flag;
}
