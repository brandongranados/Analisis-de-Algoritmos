/* Implementación de Algoritmo de burbuja */
#include <stdio.h>
#include <stdlib.h>
int iniciar();
int ordenarConBurbuja(int *, int);
int llenarArreglo(int *, int);
int mostrarArreglo(int *, int);
int main()
{
    iniciar();
    return 0;
}
int iniciar ()
{
    int tamBurbuja=0, inicio, fin;
    int *arreglo;
    puts("QUE TAMA�O DESEA EL ARREGLO");
    scanf("%d",&tamBurbuja);
    system("CLS");
    arreglo=(int *)malloc(sizeof(int)*tamBurbuja);
    llenarArreglo(arreglo, tamBurbuja);
    mostrarArreglo(arreglo, tamBurbuja);
    for(inicio=0;inicio<tamBurbuja;inicio++)
        for(fin=tamBurbuja-1;fin>0;fin--)
            if(arreglo[fin]<arreglo[fin-1])
                ordenarConBurbuja(arreglo, fin);
    mostrarArreglo(arreglo, tamBurbuja);
    free(arreglo);
    return 0;
}
int llenarArreglo(int *llenaArreglo, int limite)
{
    int cent;
    for(cent=0; cent<limite; cent++)
    {
        puts("INGRESA TU VALOR");
        scanf("%d",&llenaArreglo[cent]);
        system("CLS");
    }
    return 0;
}
int ordenarConBurbuja(int *arFinal, int lugar)
{
    int aux=arFinal[lugar];
    arFinal[lugar]=arFinal[lugar-1];
    arFinal[lugar-1]=aux;
    return 0;
}
int mostrarArreglo(int *muestraARR, int limite)
{
    int imprime;
    printf("\n");
    for(imprime=0;imprime<limite;imprime++)
        printf("%d \n",muestraARR[imprime]);
    return 0;
}
