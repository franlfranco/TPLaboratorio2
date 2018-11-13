///////////////////////////////////////////////////
//Trabajo práctico final Laboratorio 2           //
//Matias Ceraño - Francisco Franco - Luca Ciriaco//
//              #LaVacaBar                       //
///////////////////////////////////////////////////
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
            system("cls");
            tituloPrincipal();
            printf("Ingrese nombre del producto nuevo: \n");
            fflush(stdin);
            scanf("%s",nuevo.nombre);
            if(chequearProducto(archivoProducto, nuevo.nombre))
            {
                lineaRoja();
                printf("El nombre del producto ya existe, elija otro\n\a");
                lineaRoja();
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
            printf("\nNo se encontro el producto buscado\n");
        }
    }else{
        printf("\nNo hay productos cargados\n");
    }
}

nodoProd * retornarNodoProductoDeLista (nodoProd * listaProducto,char nombre[]) ///Se supone que existe el producto, si no se rompe todo
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

int cambiarNombreProductoLista (nodoProd * * lista,char nombreAnterior[],char nombreNuevo[])
{
    int flag=0;
    if(*lista)
    {
        nodoProd * cursor=*lista;
        while(cursor && strcmp(cursor->prod.nombre,nombreAnterior)!=0)
        {
            cursor=cursor->sig;
        }
        if(cursor)
        {
            strcpy(cursor->prod.nombre,nombreNuevo);
            flag=1;
        }
    }
return flag;
}

int cambiarCantVendidosProductoLista (nodoProd * * lista,char nombreProd[],int nuevaCantidad)
{
    int flag=0;
    if(*lista)
    {
        nodoProd * cursor=*lista;
        while(cursor && strcmp(cursor->prod.nombre,nombreProd)!=0)
        {
            cursor=cursor->sig;
        }
        if(cursor)
        {
            cursor->prod.cantVendidos=nuevaCantidad;
            flag=1;
        }
    }
return flag;
}

int cambiarPrecioProductoLista (nodoProd * * lista,char nombreProd[],float nuevoPrecio)
{
    int flag=0;
    if(*lista)
    {
        nodoProd * cursor=*lista;
        while(cursor && strcmp(cursor->prod.nombre,nombreProd)!=0)
        {
            cursor=cursor->sig;
        }
        if(cursor)
        {
            cursor->prod.precio=nuevoPrecio;
            flag=1;
        }
    }
return flag;
}

void cambiarProductoArchivo (nodoProd * listaProductos,char nombreArchivoProductos[])
{
    FILE * archi=fopen(nombreArchivoProductos,"wb");
    if(listaProductos)
    {
        Producto aux;
        while(listaProductos)
        {
            aux=listaProductos->prod;
            fwrite(&aux,sizeof(Producto),1,archi);
            listaProductos=listaProductos->sig;
        }
    }
    fclose(archi);
}

void modificarProducto (char nombreArchivo[],nodoProd * * listaProductos)
{
    char nombreProducto[30];
    char nombreProductoNuevo[30];
    int opc;
    int cantVendidos;
    float precio;
    system("cls");
    tituloPrincipal();
    printf("Ingrese el nombre del producto a cambiar: \n");
    linea();
    scanf("%s",&nombreProducto);
    if(chequearProducto(nombreArchivo,nombreProducto))
    {
        printf("Seleccione que campo desea cambiar:\n");
        printf("[ 1 ] Nombre del producto\n");
        linea();
        printf("[ 2 ] Precio\n");
        linea();
        printf("[ 3 ] Cantidad vendidos\n");
        linea();
        printf("[ 0 ] Cancelar\n");
        linea();
        fflush(stdin);
        scanf("%i",&opc);
        switch(opc)
               {
               case 1:
                   printf("Ingrese el nombre nuevo del producto: ");
                   fflush(stdin);
                   scanf("%s",&nombreProductoNuevo);
                   if(chequearProducto(nombreArchivo,nombreProductoNuevo))
                    printf("El nombre ya existe, se debe elegir otro.\n");
                   else
                    if(cambiarNombreProductoLista(listaProductos,nombreProducto,nombreProductoNuevo))
                        cambiarProductoArchivo(*listaProductos,nombreArchivo);
                    else
                        printf("Error durante el cambio de nombre\n");
                break;
               case 2:
                   printf("Ingrese el precio nuevo: ");
                   fflush(stdin);
                   scanf("%f",&precio);
                   if(cambiarPrecioProductoLista(listaProductos,nombreProducto,precio))
                    cambiarProductoArchivo(*listaProductos,nombreArchivo);
                   else
                    printf("Error durante el cambio de precio\n");
                break;
               case 3:
                   printf("Ingrese la cantidad de ventas nuevo: ");
                   fflush(stdin);
                   scanf("%i",&cantVendidos);
                   if(cambiarCantVendidosProductoLista(listaProductos,nombreProducto,cantVendidos))
                    cambiarProductoArchivo(*listaProductos,nombreArchivo);
                   else
                    printf("Error durante el cambio de la cantidad de ventas\n");
                break;
               case 0:
                   printf("Cancelando modificacion de producto");
                break;
               default:
                printf("\nOpcion ingresada incorrecta\n");
               }
    }
}


void ventaEnBarra (nodoProd * * cartaProductos,char archivoProductos[])
{
    char control='s';
    char nombreProducto[30];
    do
    {
        system("cls");
        printf("\n----------------Venta en barra---------------\n");
        printf("\n--------------------Carta--------------------\n");
        mostrarListProductos(*cartaProductos);
        printf("\n--------------------Carta--------------------\n");

        if(*cartaProductos)
        {
            printf("Ingrese nombre del producto que desea agregar a las ventas en la barra: ");
            fflush(stdin);
            scanf("%s",&nombreProducto);
            if(chequearProducto(archivoProductos,nombreProducto))
            {
                nodoProd * aux=retornarNodoProductoDeLista(*cartaProductos,nombreProducto);
                int nuevaCant=aux->prod.cantVendidos;
                nuevaCant++;
                if(cambiarCantVendidosProductoLista(cartaProductos,nombreProducto,nuevaCant))
                {
                    cambiarProductoArchivo(*cartaProductos,archivoProductos);
                    printf("\nProducto agregado con exito.\n");
                }
                else
                    printf("\nError\n");
            }
            else
            {
                printf("\nNo se encuentra el nombre del producto ingresado...\n");
            }
            printf("\nDesea agregar otro producto? ingrese s:  ");
            fflush(stdin);
            scanf(" %c",&control);
        }
        else
            control='n';
        system("pause");

    }
    while(control=='s');

}

int contarCantVendidosTodaLista (nodoProd * lista)
{
    int total=0;
    while(lista)
    {
        total+=lista->prod.cantVendidos;
        lista=lista->sig;
    }
return total;
}

void mostrarEstadisticasProductos (nodoProd * listaProductos)
{
    system("cls");
    if(listaProductos)
    {
        int n=contarCantVendidosTodaLista(listaProductos);
        float ganancia;
        float porcentaje;
        Producto aux;
        printf("\nPorcentaje de venta de productos\n");
        linea();
        printf("Producto            | Cant. Vendida | Ingresos generados | Porcentaje \n");
        linea();
        while(listaProductos)
        {
            if(n>0)
            {
                aux=listaProductos->prod;
                ganancia=(float)aux.cantVendidos*aux.precio;
                porcentaje=(float)(aux.cantVendidos*100)/n;
                printf("%s | %i | $ %.2f | %.2f %% \n",aux.nombre,aux.cantVendidos,ganancia,porcentaje);
                linea();

            }
                listaProductos=listaProductos->sig;
        }
    }
    else
    {
        lineaRoja();
        printf("No hay productos cargados\n");
        lineaRoja();
    }
    system("pause");
}

void cierreListaProductos (nodoProd * listaProductos,nodoProd * * carta,char archivoProductos[])
{
    if(listaProductos) ///1 ER PASO, AGREGAR LO VENDIDO DE LA CUENTA EN LA LISTA Y EL ARCHIVO
    {
        nodoProd * aux;
        Producto actual;
        int nuevaCant;
        while(listaProductos)
        {
            actual=listaProductos->prod;
            aux=retornarNodoProductoDeLista(*carta,actual.nombre);
            nuevaCant=aux->prod.cantVendidos;
            nuevaCant++;
            cambiarCantVendidosProductoLista(carta,actual.nombre,nuevaCant);
            listaProductos=listaProductos->sig;
        }
        cambiarProductoArchivo(*carta,archivoProductos);
    }
}

