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
    int rta;
    if(fopen(archivoMesas,"rb"))
    {
        Mesa aux;
        FILE * archi=fopen(archivoMesas,"rb");
        fseek(archi,sizeof(Mesa)*-1,SEEK_END);
        fread(&aux,sizeof(Mesa),1,archi);
        rta=aux.numero;
        fclose(archi);
    }
    else
    {
        printf("Archivo - %s - no encontrado...\n",archivoMesas);
        rta=0;
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

void altaMesa(char archivoMesas[], nodoMesa * listaMesas){
    Mesa nueva=nuevaMesaArchivo(archivoMesas, buscarUltimaMesaArchivo(archivoMesas));
    listaMesas=agregarFinalListaMesa(listaMesas, crearNodoMesa(nueva));
}

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa){ ///CARGA DESDE EL ARCHIVO DE MESA A LA LISTA, RETORNA VALIDOS
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
        printf("No se encontro el archivo...");
    }
    return listaMesa;
}

void mostrarMesa(nodoMesa * aux){
    printf("\nNumero mesa: %i",aux->mesa.numero);
    printf("\nOcupada: %i\n",aux->mesa.ocupada);
}

int mostrarMesasLibres (nodoMesa * lista) ///MUESTRA MESAS LIBRES, RETORNA CANTIDAD / 0 SI NO HAY
{
    int rta=0;
    printf("\n--Mesas libres--\n");
    while(lista)
    {
        if(lista->mesa.ocupada==0)
        {
            printf("Mesa: %i\n",lista->mesa.numero);
            rta++;
        }
        lista=lista->sig;
    }
    return rta;
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

//ARMAR UNA FUNCION QUE LLAME A ESTA DE ACA ABAJO, EN ESA FUNCION BORRAR EL NODOMESA DE LA LISTAMESA
void bajaArchivoMesa(char archivoMesa[], char archivoMesaTemporal[], int pos){//Elimina definitivo una mesa del archivo.
    //pasar buscarUltimaMesaArchivo como argumento en pos
    //Crear direccion de archivo temporal dentro de la funcion
    pos--;
    Mesa m;
    FILE *archivo;
    FILE *temporal;
    int i=0;
    archivo = fopen(archivoMesa, "rb");
    temporal = fopen(archivoMesaTemporal, "ab");
    if (archivo == NULL || temporal == NULL) {
        printf("No pudo abrir el archivo bbla bla bla\n");
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

void bajaMesa(nodoMesa * listaMesa, char archivoMesa[], char archivoMesaTemporal[]){
    nodoMesa * ultimo=buscarUltimoNodoMesa(listaMesa);
    if(ultimo->mesa.ocupada==0){
        listaMesa=bajaMesaLista(listaMesa);
        bajaArchivoMesa(archivoMesa, archivoMesaTemporal, buscarUltimaMesaArchivo(archivoMesa));
        printf("Se elimino la mesa correctamente\n");
    }else{
        printf("La mesa numero %i esta ocupada\n",ultimo->mesa.numero);
    }
}
