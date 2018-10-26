//Trabajo práctico final Laboratorio 2
//Matias Ceraño - Francisco Franco - Luca Ciriaco
//#LaVacaBar
//Libreria Productos

#include "Productos.h"

nodoProd * inicListaProd (void){
    return NULL;
}

nodoProd * crearNodoProd (Producto nuevo){
    nodoProd * aux=(nodoProd*)malloc(sizeof(nodoProd));
    aux->prod=nuevo;
    aux->sig=NULL;
    return aux;
}

nodoProd * agregarProductoLista (nodoProd * lista,nodoProd * nuevo){ ///EN EJECUCION
    if(!lista)
        lista=nuevo;
    else
    {
        nodoProd * cursor=lista;
        while(cursor->sig)
            cursor=cursor->sig;
        cursor->sig=nuevo;
    }
    return lista;
}

int chequearProducto(char archivoProd[], char nombre[30]){
    int flag=0;
    FILE * archivo= fopen(archivoProd, "rb");
    if(archivo){
        Producto aux;
        while (fread(&aux,sizeof(Producto),1,archivo)>0) {
            if (strcmp(aux.nombre, nombre)==0) {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

Producto altaProductoArchivo(char archivoProducto[]){ ///AGREGA UN PRODUCTO AL ARCHIVO
    Producto nuevo;
    char control='s';
    do
    {
        do {
            printf("Ingrese nombre del producto nuevo... \n");
            fflush(stdin);
            gets(nuevo.nombre);
        } while (chequearProducto(archivoProducto, nuevo.nombre));
        printf("Ingrese el valor... \n");
        fflush(stdin);
        scanf("%f",&nuevo.precio);
        printf("Nombre del producto: %s\nPrecio: %.2f\n\nEs correcta la informacion? ingrese s   ",nuevo.nombre,nuevo.precio);
        fflush(stdin);
        scanf(" %c",&control);
        control=tolower(control);
        system("cls");
    }while(control!='s');
    nuevo.cantVendidos=0;
    FILE * archi=fopen(archivoProducto,"ab");
    fwrite(&nuevo,sizeof(Producto),1,archi);
    fclose(archi);
    printf("Carga del producto: %s fue exitosa\n",nuevo.nombre);
    system("pause");
    system("cls");
    return nuevo;
}

nodoProd * archivoToListaProducto (char archivoProducto[],nodoProd * listaProd){ ///CARGA DESDE EL ARCHIVO DE PRODUCTO AL ARREGLO
    listaProd=inicListaProd();
    if(fopen(archivoProducto,"rb"))
    {
        FILE * archi=fopen(archivoProducto,"rb");
        Producto aux;
        while(fread(&aux,sizeof(Producto),1,archi)>0)
        {
            listaProd=agregarProductoLista(listaProd,crearNodoProd(aux));
        }
    }
    else
    {
        printf("No se encontro el archivo...");
        listaProd=inicListaProd();
    }
    return listaProd;
}

void altaProducto(char archivoProd[], nodoProd * listaProd){
    Producto nuevo;
    nuevo=altaProductoArchivo(archivoProd);
    listaProd=agregarProductoLista(listaProd,crearNodoProd(nuevo));
}

void mostrarListProductos(nodoProd * listaProd){
    if(listaProd)
    {
        printf("\nProducto: %s |Precio: $ %.2f |Cant. Vendidos: %i\n",listaProd->prod.nombre,listaProd->prod.precio,listaProd->prod.cantVendidos);
        mostrarListProductos(listaProd->sig);
    }
}

nodoProd * bajaListaProd(nodoProd * listaProd, char nombre[30]){
    if(listaProd){
        nodoProd * aux;
        if(strcmp(listaProd->prod.nombre,nombre)==0){
            aux=listaProd;
            listaProd=listaProd->sig;
            free(aux);
        }else{
            nodoProd * cursor=listaProd->sig;
            nodoProd * ante=listaProd;
            while (cursor && strcmp(cursor->prod.nombre,nombre)!=0) {
                ante=cursor;
                cursor=cursor->sig;
            }
            ante->sig=cursor->sig;
            free(cursor);
        }
    }
    return listaProd;
}

void bajaArchivoProducto(char archivoProducto[], char nombre[30]){//Elimina definitivo un producto del archivo.
    Producto p;
    char aProductoTemp[]={"aProdTemp.dat"};
    FILE *archivo;
    FILE *temporal;
    archivo = fopen(archivoProducto, "rb");
    temporal = fopen(aProductoTemp, "ab");
    if (archivo == NULL || temporal == NULL) {
        printf("No pudo abrir el archivo bbla bla bla\n");
        if(archivo==NULL){
            printf("PRODUCTO\n");
        }
        if(temporal==NULL){
            printf("TEMPORAL\n");
        }
    } else {
        // Se copia en el archivo temporal los registros válidos
        fread(&p, sizeof(Producto), 1, archivo);
        while (!feof(archivo)) {
            if (strcmp(p.nombre, nombre)!=0) {
                fwrite(&p, sizeof(Producto), 1, temporal);
            }
            fread(&p, sizeof(Producto), 1, archivo);
        }
        // Se cierran los archivos antes de borrar y renombrar
        fclose(archivo);
        fclose(temporal);
        remove(archivoProducto);
        rename(aProductoTemp, archivoProducto);
    }
}

void bajaProducto(nodoProd * listaProd,char archivoProducto[]){
    if (listaProd) {
        char nombre[30];
        printf("\nIngrese el producto a borrar: ");
        fflush(stdin);
        gets(nombre);
        if (chequearProducto(archivoProducto, nombre)) {
            listaProd=bajaListaProd(listaProd, nombre);
            bajaArchivoProducto(archivoProducto, nombre);
        }else{
            printf("\nNo se encontro el producto buscado");
        }
    }else{
        printf("\nNo hay productos cargados");
    }
}
