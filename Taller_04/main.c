/* Sebastian Salgado y Rodrigo Riveros INS 127
 * */

#include <stdio.h>
#include "abb.h"

/**
 * Función que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: dirección del nuevo nodo creado.
 *
 */

Nodo *crearNodo(Info dato)
{
    Nodo *nodo;
    nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->izq = nodo->der = NULL;
    return nodo;
}

/**
 * Función que ingresa un nodo al árbol.
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de la raíz.
 */

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

/**
 * Función que recorre el árbol en preorden
 *
 * @param a: puntero a la raíz.
 */

void preorden(Nodo *a)
{
    if(a != NULL)
    {
        printf("% d ", a->dato);
        preorden(a->izq);
        preorden(a->der);
    }
}

/**
 * Función que recorre el árbol en inorden
 *
 * @param a: puntero a la raíz.
 */

void inorden(Nodo *a)
{
    if(a != NULL)
    {
        inorden(a->izq);
        printf("% d ", a->dato);
        inorden(a->der);
    }
}

/**
 * Función que recorre el árbol en postorden
 *
 * @param a: puntero a la raíz.
 */

void postorden(Nodo *a) {
    if(a != NULL) {
        postorden(a->izq);
        postorden(a->der);
        printf("% d ", a->dato);
    }
}

/**
 * Función que busca un nodo dado en el árbol
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de nodo buscado.
 */


Nodo *buscardato(Nodo *a, Info dato)
{
    /* No se encontró */
    if(a == NULL)
        printf("No se encuentra en el Arbol");
        /* seguir por la izquierda */
    else if(dato < a->dato)
        return buscardato(a->izq, dato);
        /* seguir por la derecha */
    else if(dato > a->dato)
        return buscardato(a->der, dato);
    else	/* Si se encontró */
        printf("\nSi se encuentra en el Arbol \n\n");
//        return a;
}

int sumarnodos(Nodo *a)
{
    if(a == NULL)
        return 0;

    return a->dato + sumarnodos(a->der) + sumarnodos(a->izq);

}

int PesoArbol (Nodo * a)
{
    if(a ==NULL)
        return 0;

    else
        return 1+PesoArbol(a ->izq)+PesoArbol(a->der);
}

int Total_hojas(Nodo *a)
{
    if(a==NULL)
        return 0;
    if(a->der==NULL && a->izq==NULL)
        return 0;

    return Total_hojas2(a);
}

int Total_hojas2(Nodo *a)
{
    if(a==NULL)
        return 0;

    if(a->der==NULL&&a->izq==NULL)
        return 1;

    return Total_hojas(a->der) + Total_hojas(a->izq);
}


int main()
{
    int i,n;
    Nodo *raiz = NULL;
    Info datos[] = {40, 20, 30, 10, 60, 70, 50, 45, 55, 54, 65, 63, 75, 64};
    for(i = 0; i <= 13; i++) {
        raiz = insertar(raiz, datos[i]);
    }
    int opcion;
    do
    {
        printf( "\n 1. Funcion 1 ya esta implementada .");
        printf( "\n 2. Funcion Recursiva para recorrer un Arbol .");
        printf( "\n 3. Funcion Buscar en Arbol .");
        printf( "\n 4. Funcion Calcular el peso del arbol.");
        printf( "\n 5. Funcion Cantidad de Nodos Hoja .");
        printf( "\n 6. Funcion Arbol LLeno .");
        printf( "\n 7. La suma de los elemento del Arbol .");
        printf( "\n 8. Funcion Altura del Arbol .");
        printf( "\n 9. Funcion Profundidad del Arbol .");
        printf( "\n 10. Salir." );
        printf( "\n\n Introduzca opcion (2-10): \n");

        scanf( "%d", &opcion );
        /* Inicio del anidamiento */
        switch (opcion)
        {
            case 2:
                printf("\n PreOrden : ");
                preorden(raiz);
                printf("\n");
                printf("\n InOrden : ");
                inorden(raiz);
                printf("\n");
                printf("\n PostOrden : ");
                postorden(raiz);
                printf("\n");
                break;

            case 3: printf( "\n Introduzca un numero a buscar en el Arbol: ");
                scanf("%d", &n);
                buscardato(raiz,n);
                break;

            case 4:printf("El peso del arbol es : %d\n", PesoArbol(raiz));
                break;

            case 5:printf("La cantidad de nodos hoja : %d\n",Total_hojas(raiz));
                break;

            case 6:printf("Funcionaliad no implementada %d\n");
                break;

            case 7:
                printf("La suma es %d\n", sumarnodos(raiz));
                break;

            case 8:printf("Funcionaliad no implementada %d\n");
                break;

            case 9:printf("Funcionaliad no implementada %d\n");
                break;

            default:break;
        }
        /* Fin del anidamiento */
    } while ( opcion != 10 );



    return 0;
}