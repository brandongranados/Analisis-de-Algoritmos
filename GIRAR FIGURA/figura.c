/*  Implementación que es capaz de girar figuras de tamaño n * n, siendo n un numero entero
    Desarrollado por: Casiano Granados Brandon Antonio  */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define OK 0
char** defineFigura(int*);
void posicionFigura(char**, char**, int);
int mueveFigura(char**,char**, int, int, int);
void imprime(char**, int);
char** creaArreglo(int);
int main()
{
    int tam, i;
    char **matriz = defineFigura(&tam);
    char **aux = creaArreglo(tam);
    posicionFigura(matriz, aux, tam);
    return OK;
}
/* Esta función llena la figura deseada en el arreglo bidimensional */
char** defineFigura(int *medida)
{
    int i,j;
    char **figura, temp;
    puts("INGRESA LA LONGITUD DEL CUADRADO QUE ALMACENA LA FIGURA");
    fflush(stdin);
    scanf("%d",medida);
    figura = creaArreglo(*medida);
    if(figura == NULL)
        exit(1);
    for(i=0; i<*medida; i++)
        for(j=0; j<*medida; j++)
        {
            printf("DESEAS QUE LA POSICION [%d][%d] SEA PARTE DE LA FIGURA PRESIONA S \n DE LO CONTRARIO PRESIONA LO QUE SEA \n",i,j);
            __fpurge(stdin);
            scanf("%c",&temp);
            if(temp=='S' || temp=='s')
                figura[i][j]='*';
        }
    return figura;
}
/* Esta función de termina que tipo de giro realizara la figura y una vez terminada
la imprimira en la consola */
void posicionFigura(char **fig, char **res, int tamano)
{
    int vueltas, cent;
    imprime(fig, tamano);
    printf("\n PRESIONA LA OPCION DESEADA \n 1 GIRO DE 90 GRADOS \n 2 GIRO DE 180 GRADOS \n 3 GIRO DE 270 GRADOS \n");
    __fpurge(stdin);
    scanf("%d",&vueltas);
    switch (vueltas)
    {
    case 1:
    case 2:
    case 3:
        mueveFigura(fig, res, tamano, 0, vueltas);
        break;
    default:
        puts("OPCION NO VALIDA INTENTELO DE NUEVO");
        posicionFigura(fig, res, tamano);
        break;
    }
    puts("-------------");
    if(vueltas == 1 || vueltas == 3)
        imprime(res, tamano);
    else
        imprime(fig, tamano);
    printf("\n -------------");
    return;
}
/* Función generica que se encarga de realizar los giros de las figuras de manera
recursiva */
int mueveFigura(char **giraFigura, char **final, int taMax, int pos, int vuelta)
{
    int c, d;
    if(giraFigura==NULL)
    {
        puts("ERROR AL RECIBIR LA FIGURA EN UN PUNTO DE LA MATRIZ EN LA POS");
        exit(1);
    }
    if(pos >= vuelta)
        return OK;
    for(d=0; d<taMax; d++)
        for(c=0; c<taMax; c++)
            final[(taMax-1)-c][d] = giraFigura[d][c];
    free(giraFigura);
    giraFigura = creaArreglo(taMax);
    return mueveFigura(final, giraFigura, taMax, ++pos, vuelta);
}
/* Función encargada de imprimir los arrglos en consola */
void imprime(char **arreglo, int logitud)
{
    int p, q;
    if(arreglo==NULL)
        exit(1);
    for(p=0; p<logitud; p++)
    {
        printf("\n");
        for(q=0; q<logitud; q++)
            printf(" %c",arreglo[p][q]);
    }
    return;
}
/* Función encargada de solicitar la memoria dinámica al Sistema Operativo */
char** creaArreglo(int max)
{
    int a, b;
    char **arreglo = (char **) malloc (sizeof(char*)*max);
    for(a=0; a<max; a++)
        *(a+arreglo) = (char *) malloc (sizeof(char)*max);
    for(a=0; a<max; a++)
        for(b=0; b<max; b++)
            *( *(arreglo+a) + b) ='.';
    return arreglo;
}