/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */
#include "lista.h"

/**
 * Función que permite crear una nueva lista vacía.
 *
 * @return nuevo: dirección del nodo inicio de la lista creada.
 *
 */

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

/**
 * Función que permite eliminar una Lista.
 *
 * @param plista: puntero a la lista
 *
 */

void destruirLista(Lista *plista)
{
  Nodo *aux;

  while(plista->inicio != NULL)
    {
      aux = plista->inicio;
      plista->inicio = plista->inicio->siguiente;
      free(aux->datos);
      free(aux);
    }
  free(plista);
}

/**
 * Función que crea un nodo y lo inicializa con sus datos y la dirección del
 * siguiente nodo.
 *
 * @param dato: puntero a los datos
 * @param ptro: puntero al siguiente nodo
 * @return nuevo: la dirección del nuevo nodo creado.
 *
 */

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

/**
 * Función que inserta un nodo al comienzo de la lista.
 *
 * @param dato: dato que se va guardar en la lista
 *
 * @return pdato: puntero de Info.
 */

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

/**
 * Función que ingresa la información
 *
 * @param plista: puntero a la Lista
 * @param info: información a guardar en la lista
 *
 * @return true: si la inserción tuvo éxito, false: en caso contrario.
 */

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

/**
 * Función que elimina al primer nodo de la lista.
 *
 * @param plista: puntero a la lista.
 * @return dato: retorna el dato de Info o -1 en caso que la lista esté vacía.
 *
 */

int eliminar(Lista *plista)
{
  if(plista->tamano != 0)
    {
      Nodo *aux;
      int dato;
      aux = plista->inicio; //se guarda el nodo a eliminar (el 1ero) en un aux
      dato = aux->datos->dato1; //sus datos también
      plista->inicio = aux->siguiente;
      plista->tamano--;
      if(plista->tamano == 0)
        plista->fin = 0;
      free(aux->datos); free(aux); //liberar Info y después nodo
      return dato;
    }
  else
    {
      printf("No se puede eliminar la lista está vacía\n");
      return -1;
    }
}

/**
 * Función que recorre la lista y la imprime
 *
 * @param plista: puntero a la lista.
 *
 */

void recorrer(Lista *plista)
{
  Nodo *i;
  i = plista->inicio;
  printf("La lista tiene = ");
  while(i != NULL)
    {
      printf("%d ", i->datos->dato1);
      i = i->siguiente;
    }
  printf("\n");
}

/**
 * Función Principal
 *
 */

int main(int argc, char *argv[])
{
  Lista *L;
  L = creaLista();
  insertar(L, 1);
  insertar(L, 2);
  insertar(L, 3);
  recorrer(L);
  int eliminado = eliminar(L);
  printf("Se elimina %d\n", eliminado);
  recorrer(L);
  destruirLista(L);
  /* se vuelve a crear una nueva lista */
  L = creaLista();
  insertar(L, 2);
  insertar(L, 3);
  recorrer(L);
  destruirLista(L);
  return 0;
}
