#include <stdio.h>

int main () {
int a, b;
char cadena [8];
int c;

a = 7; b =14; c =128;
printf ("Asigne un valor a la cadena de caracteres ");
scanf (" %s", cadena );
printf ("La cadena es %s\n", cadena );
printf ("El valor asignado a las variables es :\n") ;
printf ("\ta: %d", a);
printf ("\tb: %d", b);
printf ("\tc: %d", c);

return 0;
}
/*
 * Obviamente el programa no funciona porque a la variable c = 128 le falta el ; y tambien el el 2do printf
 *
 * Corregido los 2 anterioes si ingreso un Nombre unico me lo muestra pero si ingreso un nombre con un espacio
 * solo muestra el primer nombre y no muestra lo que sigue del espacio
 */