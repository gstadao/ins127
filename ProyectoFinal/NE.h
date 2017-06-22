#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef int Info;
typedef struct NE{
    Info dato;
    Info nivel;
    int id;
    struct NE * izq;
    struct NE * centroizq;
    struct NE * centroder;
    struct NE * der;
}NE;

NE * insertar(NE * nodo, Info dato, Info nivel);
NE * crearNE(Info dato, Info nivel);
void ingresar(int Fi,int Ci,int Ff,int Cf,int **matriz, int p, int nivel);
int valorPixel(bool hayNegros, bool hayBlancos);
int comparar(int Fi,int Ci,int Ff,int Cf,int **matriz);