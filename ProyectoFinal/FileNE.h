#include <stdio.h>

//Lee el archivo
FILE* abrirArchivo(const char* nombre){
    return fopen(nombre, 'r');
}

//Transforma el archivo de char a numeros
int leerRaiz(FILE* f){
    int cero = (int) '0';
    return (int)fgetc(f) - cero;
}

//Toma el 1er numero como raiz y cuenta 4 mas como hijos
int* leerHijos(FILE* f){
    int* aux = (int*)malloc(sizeof(int)*4);
    int i;
    for(i = 0; i < 4; i++){
        aux[i] = leerRaiz(f);
    }
    
    return aux;
}