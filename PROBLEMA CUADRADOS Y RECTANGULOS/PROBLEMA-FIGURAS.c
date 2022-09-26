#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define excluir 1
int main ()
{
    int entrada, caso=0,caso2=0, i, f;
    puts("Ingresa el valor");
    scanf("%d",&entrada);
    f=entrada/2;
    for (i=2; (2*i-1)<=f; i++)
        if((entrada%(2*i-1))==0 && (2*i-1)!=sqrt(entrada))
            caso2=1;
    if((sqrt(entrada)/(int)sqrt(entrada))==1)
        caso=1;
    if((entrada%2)==0)
        caso2=1;
    if (caso==1 && caso2==1)
        puts("AMBOS");
    else if(caso==0 && caso2==1)
        puts("RECTANGULO");
    else if (caso==1 && caso2==0)
        puts("CUADRADO");
    else
        puts("NINGUNO");
    return 0;
}