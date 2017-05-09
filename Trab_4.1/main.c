#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "lista.h"

typedef struct info{
    int num;
    char nombre[30];
}Info;

typedef struct nodo{
    Info *dato;
    struct nodo *sgte;
}Nodo;

typedef struct lista{
    Nodo *ini;
    Nodo *fin;
    int tam;
}Lista;

int main()
{
    Lista *L;
    L = crearLista();
    insertarElemento(L,15,"pepe");
    insertarElemento(L,5,"javi");
    insertarElemento(L,30,"fran");
    insertarElemento(L,10,"peter");
    insertarElemento(L,8,"scott");
    recorrerLista(L);
    if (eliminarNodo(L, 15))
        printf("Eliminado");
    else
    printf("No se encontró");
    if (eliminarNodo(L, 30))
        printf("Eliminado");
    else
    printf("No se encontró");
    if (eliminarNodo(L, 30))
        printf("Eliminado");
    else
    printf("No se encontró");
    destruirLista(L);
}
