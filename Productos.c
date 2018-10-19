//
//  Productos.c
//  TPFinalLabo2
//
//  Created by Francisco Franco on 12/10/2018.
//  Copyright © 2018 Francisco Franco. All rights reserved.
//

#include "Productos.h"

nodoProd * inicListaProd ()
{
    return NULL;
}

nodoProd * crearNodoProd (Producto nuevo)
{
    nodoProd * aux=(nodoProd*)malloc(sizeof(nodoProd));
    aux->prod=nuevo;
    aux->sig=NULL;
    return aux;
}

nodoProd * agregarProductoLista (nodoProd * lista,nodoProd * nuevo) ///EN EJECUCION
{
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

/*  IDEA DE MUESTRA DE CUENTA
void mostrarListaCuenta (nodoProd * lista)
{
    printf("\n----------------Productos--------------------\n");
    float total=0;
    while(lista)
    {
        printf("%30s   ||$ %.2f\n",lista->prod.nombre,lista->prod.precio);
        total=total+lista->prod.precio;
        lista=lista->sig;
    }
    printf("\n\nTotal: $ %.2f\n",total);
    printf("\n---------------------------------------------\n");
}*/

void nuevoProducto (char archivoProducto[]) ///AGREGA UN PRODUCTO AL ARCHIVO
{
    Producto nuevo;
    char control='s';
    do
    {
        printf("Ingrese nombre del producto nuevo... \n");
        fflush(stdin);
        gets(nuevo.nombre);
        printf("Ingrese el valor... \n");
        fflush(stdin);
        scanf("%f",&nuevo.precio);
        printf("Nombre del producto: %s\nPrecio: %.2f\n\nEs correcta la informacion? ingrese s   ",nuevo.nombre,nuevo.precio);
        fflush(stdin);
        scanf("%c",&control);
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
}

nodoProd * archivoToListaProducto (char archivoProducto[],nodoProd * listaProd) ///CARGA DESDE EL ARCHIVO DE MESA AL ARREGLO, RETORNA VALIDOS
{
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
