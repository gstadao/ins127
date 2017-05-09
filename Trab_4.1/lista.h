
Lista *crearLista(){

    Lista *lis;
    if (lis = (Lista *) malloc(sizeof(Lista))){//Pide memoria para la lista
        nuevo -> tam = 0;//lista vacia
        nuevo -> ini = nuevo ->|fin = NULL;//inicia y fin apuntan a null
    }return nuevo;
}

Nodo *crearNodo(Info *dato, Nodo *puntero){

    Nodo *nuevo;
    if(nuevo = (Nodo *) malloc(sizeof(Nodo))){//pide memoria para el nodo
        nuevo -> dato = datos;
        nuevo -> sgte = puntero;

    }return nuevo;
}

bool insertarElemento(Lista *plist, int pval, char pnombre[30])
{
    Nodo *newNodo;
    if (newNodo = (Nodo *) malloc (sizeof(Nodo))){
        newNodo -> valor1 = pval;
        newNodo -> valor2 = pnombre;
        newNodo -> sgte = NULL;

        if (plis -> tam=0) {//Insertar Lista vacia
            plis -> ini = newNodo;
            plis -> fin = newNodo;
        }else{
            newNodo -> sgte = plis -> ini;
            plis -> ini = newNodo;
        }
        plis -> tam++;
    }else{
        printf("ERROR!!! Memoria nodo no asignada");
    }
}

void recorrerLista(Lista *plis){
    Nodo *aux;
    aux = plis -> ini;
    printf("La lista tiene = \n");
    while(aux != NULL)
    {
        printf("%d ", aux -> valor);
        aux = aux->siguiente;
    }
}

int eliminarNodo(Lista *plis, int pval){

    Nodo *aux = plis -> ini;
    Nodo *auxE;
    int eliminado = 0;

    if (pval == aux -> valor){
        auxE = aux;
        plis -> ini = aux -> sgte;
        plis -> tam--;
        auxE -> sgta = NULL;
        eliminado = 1;
        free(auxE);
    }else{
        while(aux -> sgte !=NULL && eliminado != 1){
            if (aux -> sgte -> valor !=pval){
                aux = aux -> sgte;
            }else{
                auxE = aux -> sgte;
                aux -> sgte = aux -> sgte -> sgte;
                plis -> tam--;
                auxE -> sgte = NULL;
                eliminado = 1;
                free(auxE);
            }
        }
    }
return eliminado;
}

//Liberar Memoria
void destruirLista(Lista *lis){
    Nodo *aux;
    while(lis ->ini != NULL){
        aux = lis -> ini;
        lis -> ini = lis -> ini -> sgte;
        free(aux);
    }
    free(lis);
}