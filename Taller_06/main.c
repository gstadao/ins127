#include <stdio.h>
#include "abb.h"

/*Creamos el nodo que tendra los elementos
 * */

Nodo *crearNodo(Info dato)
{
    Nodo *nodo;
    nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->izq = nodo->der = NULL;
    return nodo;
}

/*Insertamos los elementos que nos fueron indicados en un ABB
 * */
Nodo *insertar(Nodo *a, Info dato)
{
    /* insertar en árbol vacío o en hoja */
    if(a == NULL)
        return crearNodo(dato);
        /* insertar en subárbol izquierdo */
    else if(dato < a->dato)
        a->izq = insertar(a->izq, dato);
        /* insertar en subárbol derecho */
    else if(dato > a->dato)
        a->der = insertar(a->der, dato);
    /* else: Ya está, no se hace nada */
    return a;
}

/*Funcion 1 que busca el elemento mas pequeño en el ABB
 * */
Nodo* buscarMin(Nodo *a)
{
    if(a == NULL)
        return NULL;
    /* Si no tiene hijo izquierdo */
    if(a->izq == NULL)
        return a; /* lo encontró. */
    else
        return buscarMin(a->izq);
}

/*Funcion 2 que busca el elemento mas grande en el ABB
 * */
Nodo* buscarMax(Nodo *a)
{
    if(a == NULL)
        return NULL;
    /* Si no tiene hijo derecho*/
    if(a->der == NULL)
        return a; /* lo encontró. */
    else
        return buscarMax(a->der);
}

/*
 * Funcion 3 que calcula la cantidad de niveles
 */
int nivel(Nodo *a) {
    int x, y;
    if (a->izq == NULL && a->der == NULL)
        return 1;
    else {
        x = nivel(a->izq);
        y = nivel(a->der);
        if (x < y) return y + 1;
        else return x + 1;
    }
}


/*Funcion 4 que elimina el elemento elegido en el ABB
 * */
Nodo *eliminar(Nodo *a, Info dato)
{
    if(a == NULL)
        printf("El elemento no se encontró.\n");
        /* seguir por la izquierda */
    else if(dato < a->dato)
        a->izq = eliminar(a->izq, dato);
        /* seguir por la derecha */
    else if(dato > a->dato)
        a->der = eliminar(a->der, dato);
    else /* Se encontró */
    {
        Nodo *temp;
        /* Si es un nodo interno con dos hijos */
        if(a->der != NULL && a->izq != NULL)
        {
            /* nodo más a la izquierda del subárbol derecho */
            temp = buscarMin(a->der);
            a->dato = temp->dato; /* copia el nodo */
            a->der = eliminar(a->der, temp->dato);
        }
        else /* con un hijo o es una hoja */
        {
            temp = a;
            /* solo un hijo derecho o sin hijos */
            if(a->izq == NULL)
                a = a->der;
                /* solo un hijo izquierdo */
            else if(a->der == NULL)
                a = a->izq;
            free(temp);
        }
    }
    return a;
}

/*Funcion 5 que imprime el ABB en INOrden
 * */
void inorden(Nodo *a)
{
    if(a != NULL)
    {
        inorden(a->izq);
        printf("% d ", a->dato);
        inorden(a->der);
    }
}

int main()
{
    int i,n;
    Nodo *tmp = NULL;
    Nodo *raiz = NULL;
    Info datos[] = {9, 78, 6, 3, 7, 9, 5, 88, 10, 0, 1, 34, 22, 4, 2, 8, 45, 32, 65, 42};
    for(i = 0; i <= 19; i++) {
        raiz = insertar(raiz, datos[i]);
    }
    int opcion;
    do
    {
        printf( "\n 1. Buscar el elemento más pequeño .");
        printf( "\n 2. Buscar el elemento más grande .");
        printf( "\n 3. Determinar la cantidad de niveles del Arbol .");
        printf( "\n 4. Eliminar un elemento del Arbol.");
        printf( "\n 5. Imprimir INOrden el Arbol .");
        printf( "\n 6. Salir." );
        printf( "\n\n Introduzca opcion (1-6): \n");

        scanf( "%d", &opcion );
        /* Inicio del anidamiento */
        switch (opcion)
        {
            case 1:printf("El elemento màs pequeño es : \n");
                tmp=buscarMin(raiz);
                printf("%d",tmp->dato);
                break;

            case 2:printf("El elemento màs grande es : %p\n");
                tmp=buscarMax(raiz);
                printf("%d",tmp->dato);
                break;

            case 3:printf("El nivel del arbol es %d\n",nivel(raiz));
                break;

            case 4:printf("Ingrese elemento que desea eliminar\n");
                scanf("%d",&n);
                eliminar(raiz,n);
                break;

            case 5:printf("\n InOrden : ");
                inorden(raiz);
                printf("\n");
                break;

            default:break;
        }
        /* Fin del anidamiento */
    } while ( opcion != 6 );



    return 0;
}