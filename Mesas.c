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

nodoMesa * buscarUltimoNodoMesa(nodoMesa * listaMesa){
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

void nuevaMesa (char archivoMesas[],int ultimaMesa){ ///AGREGA UNA MESA AL ARCHIVO CON EL NUMERO ULTIMO+1
    Mesa nueva;
    nueva.numero=ultimaMesa+1;
    nueva.ocupada=0;
    FILE * archi=fopen(archivoMesas,"ab");
    fwrite(&nueva,sizeof(Mesa),1,archi);
    fclose(archi);
    printf("Carga de la mesa nro: %i fue exitosa\n",nueva.numero);
    system("pause");
    system("cls");
}

int buscarUltimaMesa (char archivoMesas[]){ ///RETORNA ULTIMO NUMERO DE MESA / 0 SI NO HAY ARCHIVO
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

nodoMesa * archivoToListaMesa (char archivoMesas[], nodoMesa * listaMesa){ ///CARGA DESDE EL ARCHIVO DE MESA AL ARREGLO, RETORNA VALIDOS
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

void mostrarMesasLibres(nodoMesa * listaMesa){
    if(listaMesa){
        if(listaMesa->mesa.ocupada==0){
            mostrarMesa(listaMesa);
            mostrarMesasLibres(listaMesa->sig);
        }
    }
}

