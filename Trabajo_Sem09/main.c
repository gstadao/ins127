#include <stdio.h>
#include "abb.h"

int Total_hojas2(Nodo *a)
;

Nodo *crearNodo(Info dato)
{
    Nodo *nodo;
    nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->izq = nodo->der = NULL;
    return nodo;
}

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

void preorden(Nodo *a)
{
    if(a != NULL)
    {
        printf("% d ", a->dato);
        preorden(a->izq);
        preorden(a->der);
    }
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

void promedioabb(Nodo *ptr,int suma)
{
    if(ptr==NULL) return;

    int k = ptr->dato;

    suma=suma+k;

    if(ptr->izq) promedioabb(ptr->izq,suma);
    if(ptr->der) promedioabb(ptr->der,suma);
    printf("%d",suma);
}

void auxContador(Nodo *nodo, int *c) {
    (*c)++; /* Acción: incrementar número de nodos. (Preorden) */
    if(nodo->izq) auxContador(nodo->izq, c); /* Rama izquierda */
    if(nodo->der)   auxContador(nodo->der, c);   /* Rama derecha */
}

int NumeroNodos(Nodo *a, int *contador) {/*Cuenta los nodos del arbol*/
    *contador = 0;

    auxContador(a, contador);
    return *contador;
}

void impmayorpromedio(Nodo *a)
{
    if(a != NULL)
    {
        if (a->dato<='40'){
            printf("% d ", a->dato);
        }
        preorden(a->izq);
        preorden(a->der);
    }
}

int Vacio(Nodo *r) {
    return r==NULL;
}

int AlturaNodo(Nodo *a, int dat) {
    int altura = 0;
    Nodo *actual = a; /* (1) */

    while(a != NULL) {
        if(dat == a->dato) return altura; /* dato encontrado. (2) */
        else {
            altura++; /* (3) */
            if(dat < a->dato) actual = a->izq; /* (4) */
            else if(dat > a->dato) actual = a->der; /* (5) */
        }
    }
    return -1; /* No está en árbol */
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
        printf( "\n 1. (a) Insertar un árbol binario básico (que vaya insertando de izquierda derecha).");
        printf( "\n 2. (b) Que indique si un valor dado se encuentra en el árbol dado");
        printf( "\n 3. (c) Que calcule el peso de un árbol dado.");
        printf( "\n 4. (d) Que calcule la cantidad de hojas de un árbol dado.");
        printf( "\n 5. (e) Implemente una función que imprima todos los valores mayores al valor promedio de un árbol binario.");
        printf( "\n 6. (f) Implemente una función que devuelva la menor diferencia, en valor absoluto, entre el valor del nodo raíz de un árbol y otro valor contenido en algún otro nodo.");
        printf( "\n 7. (g) Implemente una función que, para un árbol y dos números enteros, n1 y n2, indique si la suma de los valores que se encuentran a nivel n1 es igual a la suma de los valores que se encuentran a nivel n2.");
        printf( "\n 8. (h) Implemente una función que indique si un árbol dado es completo o no.");
        printf( "\n 9. (i) Implemente una función que indique si un árbol dado es lleno o no.");
        printf( "\n 10. (j) Implemente una función que indique si dos árboles binarios dados son espejo o no. Dos árboles binarios son espejo si poseen la misma estructura e igual valor en cada nodo de la estructura.");
        printf( "\n 11. (k) Implemente una función que indique si un determinado valor, recibido como parámetro, se encuentra o no en una hoja.");
        printf( "\n 12. (l) Que calcule la altura de un nodo.");
        printf( "\n 13. (m) Que calcule la profundidad de un nodo");
        printf( "\n 14. (n) Implemente una función que, recibiendo como parámetro un árbol binario, determine si la anchura de dicho árbol es igual a su altura. La ancha de un árbol es la máxima cantidad de nodos que se encuentran en cada nivel del árbol");
        printf( "\n 15. Salir." );
        printf( "\n\n Introduzca opcion (1-15): \n");

        scanf( "%d", &opcion );
        /* Inicio del anidamiento */
        switch (opcion)
        {
            case 1:printf("Se Insertan elementos en ABB \n");
                printf("\n Se muestra ABB en PreOrden : ");
                preorden(raiz);
                printf("\n");
                break;

            case 2: printf( "\n Introduzca un numero a buscar en el Arbol: ");
                scanf("%d", &n);
                buscardato(raiz,n);
                printf("\n");
                break;

            case 3:printf("El peso del arbol es : %d\n", PesoArbol(raiz));
                break;

            case 4:printf("La cantidad de nodos hoja : %d\n",Total_hojas(raiz));
                break;

            case 5:printf("los Nodos mayores al promedio son : \n");
//                int suma=0;
//                promedioabb(raiz,suma);
                impmayorpromedio(raiz);
                printf("\n");
                break;

            case 6:printf("Funcionaliad no implementada \n");
                break;

            case 7:printf("Funcionaliad no implementada \n");
                break;

            case 8:printf("Funcionaliad no implementada \n");
                break;

            case 9:printf("Funcionaliad no implementada \n");
                break;

            case 10:printf("Funcionaliad no implementada \n");
                break;

            case 11:printf("Funcionaliad no implementada \n");
                break;

            case 12:printf( "\n Introduzca el Nodo del que desea buscar la altura : ");
                scanf("%d", &n);
                int dat=0;
                AlturaNodo(n,dat);
                printf("\n");
                break;

            case 13:printf("Funcionaliad no implementada \n");
                break;

            case 14:printf("Funcionaliad no implementada \n");
                break;

            default:break;
        }
        /* Fin del anidamiento */
    } while ( opcion != 15 );

    return 0;
}