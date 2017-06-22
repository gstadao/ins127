/* Proyecto creado por Juan Catalan y Rodrigo Riveros
 */
#include "ArchivoNE.h"
#include "FuncionNE.h"
#include <stdio.h>
#include "FileNE.h"
#include "ArbolNE.h"
//#include "NE.h"

#define TAM 128

int main(){

    nodoA *raiz=NULL;
    int x,y,posicion;
    int *array=(int*)malloc(128*sizeof(int));
    int **matrizMain=crearMatriz(FIL,COL);

    crearArchivo();
    array=obtenerArchivo();
    raiz=crearArbol(raiz,array);
    cola *colaM=crearCola();
    colaM=recorrerNivel(raiz);
    matrizMain=llenarMatriz(FIL,COL,colaM);

    printf("\nLa imagen es: \n");
    imprimirMatrizImagen(matrizMain);

    printf("\nLa matriz es: \n");
    imprimirMatrizDato(matrizMain);

    return 0;
}

/*
int main(int argc, char **argv)
{
    FILE* f = abrirArchivo("datos.dat");
    QNodo* raiz = crearCuadrante(leerRaiz(f),0,0,TAM);
}


void llenar(QNodo* raiz, FILE* f){
    int i, j;
    QNodo* pivote;

    if(raiz->color != 2){
        return;
    }

    initHijos(raiz);
    int* hijos = leerHijos(f);
    int sub;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            pivote = crearCuadrante(
                    hijos[i],
                    (raiz->x + raiz->l/2)*j%2,
                    (raiz->y + raiz->l/2)*i%2,
                    raiz->l/2
            );
            sub = 2*i +j;
            raiz->hijos[sub] = pivote;
            llenar(pivote,f);
        }
    }
}*/

/*
void preorden(QNodo * raiz,FILE * f){
    if(raiz!=NULL){
        fprintf(f,"\"n%d\"[label=\"%d\"];\n",raiz->color);
        printf("%d. ",raiz->color);
        preorden((QNodo *) raiz->x, f);
        preorden((QNodo *) raiz->y, f);
    }
}

void drawQt(QNodo *raiz,FILE *f){
    if(raiz->x!=NULL){
        fprintf(f,"n%d->n%d;\n",raiz->color);
        drawQt((QNodo *) raiz->x, f);
    }
    if(raiz->y!=NULL){
        fprintf(f,"n%d->n%d;\n",raiz->color);
        drawQt((QNodo *) raiz->y, f);
    }
}*/



