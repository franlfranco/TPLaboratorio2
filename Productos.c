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

int chequearProducto(char archivoProd[], char nombre[30]){ ///Retorna 0 si no encuentra. 1 en caso verdadero
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
            printf("Ingrese nombre del producto nuevo: \n");
            fflush(stdin);
            scanf("%s",nuevo.nombre);
            if(chequearProducto(archivoProducto, nuevo.nombre))
            {
                printf("El nombre del producto ya existe, elija otro\n");
                system("pause");
            }
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
        printf("No se encontro el archivo. Creando %s\n",archivoProducto); ///Si no se encuentra el archivo, que lo cree
        fopen(archivoProducto,"wb");
        listaProd=inicListaProd();
    }
    return listaProd;
}

void altaProducto(char archivoProd[], nodoProd * * listaProd){
    if(fopen(archivoProd,"rb"))
    {
        Producto nuevo;
        nuevo=altaProductoArchivo(archivoProd);
        *listaProd=agregarProductoLista(*listaProd,crearNodoProd(nuevo));
    }
    else
    {
        printf("\nNo se encontro el archivo. Creando uno nuevo\n");
        fopen(archivoProd,"wb");
        altaProducto(archivoProd,*listaProd);
    }

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
            printf("\nSe elimino el producto de manera correcta\n");
        }else{
            nodoProd * cursor=listaProd->sig;
            nodoProd * ante=listaProd;
            while (cursor && strcmp(cursor->prod.nombre,nombre)!=0) {
                ante=cursor;
                cursor=cursor->sig;
            }
            if(cursor)
            {
            ante->sig=cursor->sig;
            free(cursor);
            printf("\nSe elimino el producto de manera correcta\n");
            }
            else
            {
                printf("\nNo se encuentra el producto a eliminar\n");
            }

        }
    }
    return listaProd;
}

void bajaArchivoProducto(char archivoProducto[], nodoProd * listaActualizada)
{
    FILE * archivo=fopen(archivoProducto,"wb");
    if(listaActualizada)
    {
        Producto aux;
        while(listaActualizada)
        {
            aux=listaActualizada->prod;
            fwrite(&aux,sizeof(Producto),1,archivo);
            listaActualizada=listaActualizada->sig;
        }
    }
    fclose(archivo);
}

void bajaProducto(nodoProd * * listaProd,char archivoProducto[]){ ///DE LISTA A ARCHIVO
    if (*listaProd) {
        char nombre[30];
        printf("\nIngrese el producto a borrar: ");
        fflush(stdin);
        scanf("%s",nombre);
        if (chequearProducto(archivoProducto, nombre)) {
            *listaProd=bajaListaProd(*listaProd, nombre);
            bajaArchivoProducto(aProductos,*listaProd);
        }else{
            printf("\nNo se encontro el producto buscado");
        }
    }else{
        printf("\nNo hay productos cargados");
    }
}

nodoProd * retornarNodoProductoDeLista (nodoProd * listaProducto,char nombre[]) ///xxx ///Se supone que existe el producto, si no se rompe todo
{
    nodoProd * rta=inicListaProd();
    if(listaProducto)
    {
        while(listaProducto && strcmp(listaProducto->prod.nombre,nombre)!=0)
        {
            listaProducto=listaProducto->sig;
        }
        if(listaProducto)
        {
            rta=crearNodoProd(listaProducto->prod);
        }
    }
    return rta;
}

void mostrarArchivoYFilaProd (char nombreArchivo[],nodoProd * lista)
{
    FILE * archi=fopen(nombreArchivo,"rb");
    Producto aux;
    printf("\nArchivo:\n");
    while(fread(&aux,sizeof(Producto),1,archi)>0)
    {
        printf("| Nombre: %s |",aux.nombre);
    }
    printf("\nLista:\n");
    while(lista)
    {
        printf("| Nombre: %s |",lista->prod.nombre);
        lista=lista->sig;
    }
    printf("\n");
}
