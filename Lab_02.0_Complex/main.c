# include <stdio.h>

typedef struct {
    int r;
    int i;
} Complex;

Complex suma (Complex z ,Complex w );
Complex multiplicacion (Complex z ,Complex w);
int iguales (Complex z ,Complex w );
int main () {
    Complex x,y;
    x.r = 10;
    x.i = 5;
    y.r = 7;
    y.i = 8;
    printf("(%i,%i)\n",x.r,x.i);
    printf("(%i,%i)\n",y.r,y.i);
    Complex aux ;
    aux = suma(x,y);
    printf("(%i,%i) + (%i,%i) = (%i,%i)\n",x.r,x.i,y.r,y.i,aux.r,aux.i);
    aux = multiplicacion(x,y);
    printf("(%i,%i) * (%i,%i) = (%i,%i)\n",x.r,x.i,y.r,y.i,aux.r,aux.i);
    printf("(%i,%i) == (%i,%i)?%i\n",x.r,x.i,y.r,y.i,iguales(x,y));
    return 0;
}
Complex suma(Complex z ,Complex w) {
    Complex aux ;
    aux.r = z.r+ w.r;
    aux.i = z.i + w.i;
    return aux ;
}
Complex multiplicacion(Complex z,Complex w) {
    Complex aux ;
    aux.r = z.r * w.r - z.i * w.i;
    aux.i = z.r * w.i + z.i * w.r;
    return aux ;
}
int iguales(Complex z,Complex w) {
    if (z.r == w.r && z.i == w.i) return 1;
    return 0;
}