#include <stdio.h>
#include <stdlib.h>

void crearArchivo(){
	FILE *newF;
	int i;
	int arrayArbol[]={2,1,0,2,1,2,2,1,2,2,0,2,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,1,0,1,1,0,1,0};
	newF=fopen("datos.dat","w");
	for (i=0;i<37;i++){
		fprintf(newF, "%d\n",arrayArbol[i]);
	}
	fclose(newF);
}
int *obtenerArchivo(){
	FILE *archivo;
	int i,a=0;
	archivo = fopen("datos.dat", "r");
	int *array=(int*)malloc(38*sizeof(int));
	fscanf (archivo, "%d", &i);
 	while ( !feof (archivo) ) {
		array[a]=i;

 		fscanf (archivo, "%d", &i);
 		a++;
 	}
	fclose(archivo);
	return array;
}