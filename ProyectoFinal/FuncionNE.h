#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define altura 4
#define WH 219
#define BL 0
#define FIL 8
#define COL 8
typedef struct nodeA{
    int color;
    struct nodeA *a,*b,*c,*d;
}nodoA;
typedef struct Nodo{
    int valor;
    struct Nodo *sgte;
}nodo;
typedef struct Cola{
    nodo *inicio;
    nodo *fin;
    int tam;
}cola;

cola *crearCola(){
    cola *newCola;
    newCola=(cola*)malloc(sizeof(cola));
    newCola->inicio=NULL;
    newCola->fin=NULL;
    newCola->tam=0;
    return newCola;
}
void agregarNodo(cola *colaN,int val){
    nodo *newNodoC;
    newNodoC=(nodo*)malloc(sizeof(nodo));
    newNodoC->valor=val;
    newNodoC->sgte=NULL;
    if(colaN->tam==0){
        colaN->inicio=newNodoC;
    }else{
        colaN->fin->sgte=newNodoC;
        }
    colaN->fin=newNodoC;
    colaN->tam++;
}
cola *color(nodoA* raiz, int level,cola *cola){
    if (raiz == NULL)
        return cola;
    if (level == 1){
        agregarNodo(cola,raiz->color); 
    } else if (level > 1){
        cola=color(raiz->a, level-1,cola);
        cola=color(raiz->b, level-1,cola);
        cola=color(raiz->c, level-1,cola);
        cola=color(raiz->d, level-1,cola);
    }
    return cola;
}
cola *recorrerNivel(nodoA* raiz){
    int i;
    cola *colaN=crearCola();
    for (i=1; i<=altura; i++){
        colaN=color(raiz, i,colaN);
    }
    return colaN;
}
bool NoEsVacia(cola *colaA){
    if(colaA->inicio!=NULL){
        return true;
    }else{
        return false;
    }
}
int popCola(cola *colaP){
    nodo *aux,*auxE;
    aux=colaP->inicio;
    if(NoEsVacia(colaP)){
        colaP->inicio=aux->sgte;
        aux->sgte=NULL;
        colaP->tam--;
        auxE=aux;
    }
    return auxE->valor;
    free(aux);
}
void recorrerCola(cola *colaR){
    
    nodo *aux;
    aux=colaR->inicio;
    printf("\nLos valores de la cola son");
    while(aux!=NULL){
        printf("\n%d",aux->valor);
        aux=aux->sgte;
    }
}
nodoA* newNode(int data){
    nodoA* node = (nodoA*)malloc(sizeof(nodoA));
    node->color = data;
    node->a = NULL;
    node->b = NULL;
    node->c = NULL;
    node->d = NULL;
    return node;
}
nodoA *crearArbol(nodoA *raiz, int *array){
    raiz = newNode(array[0]);
    raiz->a = newNode(array[1]);
    raiz->b = newNode(array[2]);
    raiz->c = newNode(array[3]);
    raiz->d = newNode(array[4]);
    raiz->a->a= newNode(array[5]);
    raiz->a->b= newNode(array[6]);
    raiz->a->c= newNode(array[7]);
    raiz->a->d= newNode(array[8]);
    raiz->c->a= newNode(array[9]);
    raiz->c->b= newNode(array[10]);
    raiz->c->c= newNode(array[11]);
    raiz->c->d= newNode(array[12]);
    raiz->a->a->a=newNode(array[13]);
    raiz->a->a->b=newNode(array[14]);
    raiz->a->a->c=newNode(array[15]);
    raiz->a->a->d=newNode(array[16]);
    raiz->a->b->a=newNode(array[17]);
    raiz->a->b->b=newNode(array[18]);
    raiz->a->b->c=newNode(array[19]);
    raiz->a->b->d=newNode(array[20]);
    raiz->a->d->a=newNode(array[21]);
    raiz->a->d->b=newNode(array[22]);
    raiz->a->d->c=newNode(array[23]);
    raiz->a->d->d=newNode(array[24]);
    raiz->c->a->a=newNode(array[25]);
    raiz->c->a->b=newNode(array[26]);
    raiz->c->a->c=newNode(array[27]);
    raiz->c->a->d=newNode(array[28]);
    raiz->c->c->a=newNode(array[29]);
    raiz->c->c->b=newNode(array[30]);
    raiz->c->c->c=newNode(array[31]);
    raiz->c->c->d=newNode(array[32]);
    raiz->c->d->a=newNode(array[33]);
    raiz->c->d->b=newNode(array[34]);
    raiz->c->d->c=newNode(array[35]);
    raiz->c->d->d=newNode(array[36]);
    return raiz;
}


int **crearMatriz(int filas,int columnas){
    int **newMatriz;
    int i;
    newMatriz=(int**)malloc(filas*sizeof(int*));
    for (i=0;i<filas;i++){
        newMatriz[i]=(int*)malloc(columnas*sizeof(int));
    }
    return newMatriz;
}
int *crearArreglo(int largo){
    int *newArray;
    newArray=(int*)malloc(largo*sizeof(int));
    return newArray;
}
int asccii(int i,int j){
    if (j%2==0){
        return 0;
    }else{
        return 1;
    }
}
int *cuadrantes(int pos,int *arrayN){
    if(pos==2){
        arrayN[0]=0;
        arrayN[1]=4;
        arrayN[2]=4;
        arrayN[3]=8;
    }
    if (pos==4){
        arrayN[0]=4;
        arrayN[1]=4;
        arrayN[2]=8;
        arrayN[3]=8;
    }
    if (pos==7){
        arrayN[0]=2;
        arrayN[1]=0;
        arrayN[2]=4;
        arrayN[3]=2;
    }
    if (pos==10){
        arrayN[0]=4;
        arrayN[1]=2;
        arrayN[2]=6;
        arrayN[3]=4;
    }
    if (pos==13){
        arrayN[0]=0;
        arrayN[1]=0;
        arrayN[2]=1;
        arrayN[3]=2;
    }
    if (pos==15){
        arrayN[0]=1;
        arrayN[1]=0;
        arrayN[2]=2;
        arrayN[3]=2;
    }
    if (pos==17){
        arrayN[0]=0;
        arrayN[1]=2;
        arrayN[2]=1;
        arrayN[3]=4;
    }

    if (pos==19){
        arrayN[0]=1;
        arrayN[1]=2;
        arrayN[2]=2;
        arrayN[3]=4;
    }
    if (pos==21){
        arrayN[0]=2;
        arrayN[1]=2;
        arrayN[2]=3;
        arrayN[3]=4;
    }
    if (pos==23){
        arrayN[0]=5;
        arrayN[1]=0;
        arrayN[2]=6;
        arrayN[3]=1;
    }
    if (pos==25){
        arrayN[0]=4;
        arrayN[1]=0;
        arrayN[2]=8;
        arrayN[3]=2;
    }
    if (pos==27){
        arrayN[0]=5;
        arrayN[1]=0;
        arrayN[2]=6;
        arrayN[3]=1;        
    }
    if (pos==28){
        arrayN[0]=5;
        arrayN[1]=1;
        arrayN[2]=6;
        arrayN[3]=2;
    }
    if (pos==29){
        arrayN[0]=6;
        arrayN[1]=0;
        arrayN[2]=7;
        arrayN[3]=1;        
    }
    if (pos==30){
        arrayN[0]=5;
        arrayN[1]=1;
        arrayN[2]=6;
        arrayN[3]=2;        
    }
    if (pos==31){
        arrayN[0]=7;
        arrayN[1]=0;
        arrayN[2]=8;
        arrayN[3]=1;
    }
    if (pos==32){
        arrayN[0]=7;
        arrayN[1]=1;
        arrayN[2]=8;
        arrayN[3]=2;
    }
    if (pos==33){
        arrayN[0]=6;
        arrayN[1]=2;
        arrayN[2]=7;
        arrayN[3]=3;
    }
    if (pos==34){
        arrayN[0]=6;
        arrayN[1]=3;
        arrayN[2]=7;
        arrayN[3]=4;
    }
    if (pos==35){
        arrayN[0]=7;
        arrayN[1]=2;
        arrayN[2]=8;
        arrayN[3]=3;
    }    
    if (pos==36){
        arrayN[0]=7;
        arrayN[1]=3;
        arrayN[2]=8;
        arrayN[3]=4;
    }

    return arrayN;
}
int **llenarMatriz(int filas, int columnas,cola *colaM){
    int **matrizN=crearMatriz(filas,columnas);
    int *arrayN=crearArreglo(4);
    int i,j,color;
    int cont=0;
    while (NoEsVacia(colaM)){
        color=popCola(colaM);
        if (color!=2){
            arrayN=cuadrantes(cont,arrayN);
            for (i=arrayN[0];i<arrayN[2];i++){
                for (j=arrayN[1];j<arrayN[3];j++){
                    matrizN[i][j]=color;
                }
            }
        }
        cont++;
    }
    return matrizN;
}
void imprimirMatrizImagen(int **matriz){
    int i,j;
    for (i=0;i<FIL;i++){
        for (j=0;j<COL;j++){

            if (matriz[i][j]==1){
                printf("%c%c",BL,BL);
            }else{
                printf("%c%c",WH,WH);
            }
        }
        printf("\n");
    }
}
void imprimirMatrizDato(int **matriz){
    int i,j;
    for (i=0;i<FIL;i++){
        for (j=0;j<COL;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}
int detCuadrante(int x, int y){
    if (x<=4 && y<=4){
        return 1;
    }
    if (x>=5 && y>=5){
        return 4;
    }
    if (x<=4 && y>=5){
        return 2;
    }
    if (x>=5 && y<=4){
        return 3;
    }
}


