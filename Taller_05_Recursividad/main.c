//** Desarrollado por Sebastian Salgado y Rodrigo Riveros para INS 127**/

#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

//Funcion 01
int calcularFactorial(int n)
{
    int r;
    if (n==1)
    {
        return 1;
    }
    r=n*calcularFactorial(n-1) ;
    return (r) ;
}

//Funcion 02
int multiplicarConSuma(int n1,int n2)
{
    int r;
    if (n2==1)
    {
        return n1;
    }
    r=n1+multiplicarConSuma(n1,n2-1) ;
    return (r);
}

//Funcion 03
int sumarArreglo(int t[],int n)
{
    int r = 0;
    if(n==0){
        r += t[0];
    }else{
        r = t[n] + sumarArreglo(t,n-1);
    }
    return (r);
}

//Funcion 04
bool buscarX(int a[],int t, int x)
{
    int r = 0;
    if (a[t]==x){
        return true;
    }else{
        r = a[t] + buscarX(a,t-1,x);
    }
    return false;
}

//Funcion 05
void imprimirArreglo(int arreglo[], int n) {
    if(n<=0) return;
    imprimirArreglo(arreglo,n-1);
    printf("%d ",arreglo[n-1]);
}

Lista *creaLista()
{
    Lista *nuevo;

    if(nuevo = (Lista *) malloc(sizeof(Lista))) // Pide memoria para la lista
    {
        nuevo->tamano = 0; // Lista vacía
        nuevo->inicio = nuevo->fin = NULL; // Inicio y Fin apuntan a NULL
    }
    return nuevo;
}

Nodo *crearNodo(Info *dato, Nodo *ptro)
{
    Nodo *nuevo;
    if(nuevo = (Nodo *) malloc(sizeof(Nodo))) // Pide memoria para el nodo
    {
        nuevo->datos = dato;
        nuevo->siguiente = ptro;
    }
    return nuevo;
}

Info *agregar(int dato1)
{
    Info *pdato;
    if(pdato = (Info *) malloc(sizeof(Info)))
    {
        /* Se almacena la información en Info */
        pdato->dato1 = dato1;
        /* pdato->dato2 = dato2; */
        return pdato;
    }
    else
    {
        printf("problemas en la inserción\n");
        free(pdato);
        exit(0);
    }
}

bool insertar(Lista *plista, int info)
{
    Nodo *aux;
    Info *dato = agregar(info);
    // Se crea un nodo con datos y apunta al siguiente nodo
    if(aux = crearNodo(dato, plista->inicio)) //además, se almacena en aux
    {
        plista->inicio = aux;
        if(plista->tamano == 0)
            plista->fin = aux;
        plista->tamano++;
        printf("Se inserta %d\n", plista->inicio->datos->dato1);

        return true;
    }
    else
        return false;
}

//Funcion 06
int calcularOcurrencia(Nodo *i,int x){

    if(i == NULL){
        return 0;
    } else {
        if (i->datos->dato1 == x) {
            return 1 +calcularOcurrencia(i->siguiente,x);
        }
            return calcularOcurrencia(i->siguiente,x);
        }
}

//Funcion 07
int sumaLista (Nodo *i){

    if(i == NULL){
        return 0;
    } else {
            return i->datos->dato1 +sumaLista (i->siguiente);
    }
}

//Funcion 08
void listarLista (Nodo *i){

    if(i == NULL){
    } else {
        printf("%d - ",i->datos->dato1);
        return listarLista (i->siguiente);
    }
}

//Funcion 10
bool existeElemento (Nodo *i,int x){

    if(i == NULL){
        return false;
    } else {
        if (i->datos->dato1 == x) {
            return true;
        }
        return existeElemento(i->siguiente,x);
    }
}

//Funcion 12
int calcularMaximo (Nodo *i){

    if(i == NULL){
        return 0;
    } else {
        if (i->datos->dato1 > calcularMaximo (i->siguiente)) {
            return i->datos->dato1;
        }
        //return calcularMaximo (i->siguiente);
    }
}

//Funcion 16
/*void invertirLista (Nodo *i){

    if(i == NULL){
    } else {
        if (i->siguiente != NULL){
            return invertirLista (i->siguiente);
//            return i->datos->dato1;
        }
        //return calcularMaximo (i->siguiente);
    }
}*/


int main()
{
    int n,opcion,res,n1,n2;
    do
    {
        printf( "\n 1. Funcion Recursiva calcularFactorial .");
        printf( "\n 2. Funcion Recursiva multiplicarConSuma .");
        printf( "\n 3. Funcion Recursiva sumarArreglo .");
        printf( "\n 4. Funcion Recursiva buscarX .");
        printf( "\n 5. Funcion Recursiva imprimirArreglo .");
        printf( "\n 6. Funcion Recursiva calcularOcurrencia .");
        printf( "\n 7. Funcion Recursiva sumaLista .");
        printf( "\n 8. Funcion Recursiva listarLista  .");
        printf( "\n 9. Funcion Recursiva sonIguales   .");
        printf( "\n 10. Funcion Recursiva existeElemento   .");
        printf( "\n 11. Funcion Recursiva eliminarX    .");
        printf( "\n 12. Funcion Recursiva calcularMaximo     .");
        printf( "\n 13. Salir." );
        printf( "\n\n Introduzca opcion (1-13): \n");

        scanf( "%d", &opcion );
        /* Inicio del anidamiento */
        switch (opcion)
        {
            case 1: printf("\n Introduzca un numero entero: ");
                scanf("%d", &n);
                res=calcularFactorial(n);
                printf("\n El factorial de %d es: %d\n\n",n,res);
                break;

            case 2: printf( "\n Introduzca un numero entero A: ");
                scanf("%d", &n1);
                printf( "\n Introduzca un numero entero B: ");
                scanf("%d", &n2);
                res=multiplicarConSuma(n1,n2);
                printf("\n El resultado de %d y %d es: %d\n\n",n1,n2,res);
                break;

            case 3:
            {
                int t;
                printf("Ingresar tamaño : ");
                scanf("%d",&t);
                printf("ingresamos valor \n");
                int arreglo[t];
                for (int i=0;i<t;i++){
                    scanf("%d",&arreglo[i]);
                }
/*                printf("imprimimos arreglo \n");
                for (int i=0;i<t;i++){
                    printf("arreglo[%d] = %d \n",i,arreglo[i]);
                };*/
                res=sumarArreglo(arreglo,t);
                printf("\n El resultado de la suma del arreglo es es: %d\n\n",res);
                break;
            }

            case 4:
            {
                int t,x;
                printf("Ingresar tamaño : ");
                scanf("%d",&t);
                printf("ingresamos valor \n");
                int arreglo[t];
                for (int i=0;i<t;i++){
                    scanf("%d",&arreglo[i]);
                }
                printf("Ingresar dato a buscar en arreglo : ");
                scanf("%d",&x);
/*                printf("imprimimos arreglo \n");
                for (int i=0;i<t;i++){
                    printf("arreglo[%d] = %d \n",i,arreglo[i]);
                };*/
                res=buscarX(arreglo,t,x);
                printf("\n El resultado de la busqueda es: %d\n\n",res);
                break;
            }

            case 5:
            {
                int t;
                printf("Ingresar tamaño : ");
                scanf("%d",&t);
                printf("ingresamos valor \n");
                int arreglo[t];
                for (int i=0;i<t;i++){
                    scanf("%d",&arreglo[i]);
                }
                imprimirArreglo(arreglo,t);
                break;
            }

            case 6:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,2);
                insertar(L,2);
                insertar(L,3);
                int x;
                printf("Ingrese valor a buscar en la lista : ");
                scanf("%d",&x);
                res=calcularOcurrencia(L->inicio,x);
                printf("\n La cantidad de ocurrencias en la lista es: %d\n\n",res);
                break;
            }

            case 7:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,2);
                insertar(L,2);
                insertar(L,3);
                res=sumaLista(L->inicio);
                printf("\n La suma de los elementos de ls lista L es: %d\n\n",res);
                break;
            }

            case 8:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,2);
                insertar(L,2);
                insertar(L,3);
                listarLista(L->inicio);
                break;
            }

            case 9:
            {
                printf("\n Funcion no implementada\n\n");
                break;
            }

            case 10:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,2);
                insertar(L,2);
                insertar(L,3);
                int x;
                printf("Ingrese valor a buscar en la lista : ");
                scanf("%d",&x);
                res=existeElemento (L->inicio,x);
                printf("\n El elemento buscado  en la lista es: %d\n\n",res);
                break;
            }

            case 11:
            {
                printf("\n Funcion no implementada\n\n");
                break;
            }

            case 12:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,6);
                insertar(L,2);
                insertar(L,3);
                res=calcularMaximo (L->inicio);
                printf("\n El elemento maximos es: %d\n\n",res);
                break;
            }

/*            case 16:
            {
                Lista *L;
                L = creaLista();
                insertar(L,1);
                insertar(L,2);
                insertar(L,3);
                insertar(L,6);
                insertar(L,2);
                insertar(L,3);
                invertirLista   (L->inicio);
                break;
            }*/

            default:break;
        }
        /* Fin del anidamiento */
    } while ( opcion != 13 );

    return 0;
}