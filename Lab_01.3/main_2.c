#include <stdio.h>

int main() {

    int dia,mes,anio,suma,fechavalida;

    printf("Ingrese su Fecha de Nacimiento\n");
    printf("Ingrese Dia\n");
    scanf("%d",&dia);
    printf("Ingrese Mes\n");
    scanf("%d",&mes);
    printf("Ingrese Año\n");
    scanf("%d",&anio);

    fechavalida = 0;suma = 0;

    if (mes >0 && mes <=12){
        switch (mes){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if (dia>0 && dia <=31)
                    fechavalida=1;
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if (dia>0 && dia <=30){
                    fechavalida=1;
                    break;
                }
            case 2: if (dia>0 && dia <=28){
                    fechavalida=1;
                    break;
                }
            default:break;
        }
    }

if (fechavalida == 0){
    printf("La Fecha Ingresada NO es Válida\n");
}else{
    int suma2=0;
    suma = anio+mes+dia;
    while (suma > 0) {
        int digito = suma % 10;
        // digito primero será 8, después 2, después 0, etc...
        suma /= 10;
        suma2 = suma2 + digito;
    }
    suma=suma2;
}



    printf("Número Mágico %d\n",suma);
    getchar();

    return 0;
}

