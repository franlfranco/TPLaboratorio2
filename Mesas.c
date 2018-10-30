//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco
//#LaVacaBar
//Libreria Mesas

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

void mostrarMesa(nodoMesa * aux){
    printf("\nNumero mesa: %i",aux->mesa.numero);
    printf("\nOcupada: %i\n",aux->mesa.ocupada);
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

/*
void bajaArchivoMesa(char archivoMesa[], char archivoMesaTemporal[], int pos){//Elimina definitivo una mesa del archivo.
    //pasar buscarUltimaMesaArchivo como argumento en pos
    //Crear direccion de archivo temporal dentro de la funcion
    pos--;
    printf("\n--%i\n",pos);
    if(pos>0)
    {
    puts("pos > 0");
    Mesa m;
    FILE *archivo;
    FILE *temporal;
    archivo = fopen(archivoMesa, "rb");
    temporal = fopen(archivoMesaTemporal, "ab");
    int i=0;
    if (archivo == NULL || temporal == NULL) {
        printf("Archivo - %s - no encontrado...\n",archivoMesa);
        if(archivo==NULL){
            printf("MESA\n");
        }
        if(temporal==NULL){
            printf("TEMPORAL\n");
        }
    } else {
        // Se copia en el archivo temporal los registros válidos
        fread(&m, sizeof(Mesa), 1, archivo);
        while (!feof(archivo)) {
            if (i != pos) {
                fwrite(&m, sizeof(Mesa), 1, temporal);
            }
            fread(&m, sizeof(Mesa), 1, archivo);
            i++;
        }
        // Se cierran los archivos antes de borrar y renombrar
        fclose(archivo);
        fclose(temporal);
        remove(archivoMesa);
        rename(archivoMesaTemporal, archivoMesa);
    }
    }
    else
    {
        printf("No hay mesas para borrar...\n");
    }

}
*/

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
