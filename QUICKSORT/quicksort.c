/* Implementación de ALgoritmo Quicksort
    Desarrollado por: Casiano Granados Brandon Antonio */
#include <stdlib.h>
#include <stdio.h>
#define MAX 20
 
 void intercambio(int [],int, int);
 void quicksort(int [],int, int); 
 void imprimeVector(int [],int);
 
 int main()
 {
    int vector[MAX]={0};
    int numElem,i;
    clrscr();
    printf("\nCuantos elementos quieres en el arreglo? ");
    scanf("%d",&numElem);
    for(i=0;i<numElem;i++)
    { 
        printf("\nDato: ");
        scanf("%d",&vector[i]);
    }
 
    quicksort(vector,0,numElem-1);
    imprimeVector(vector,numElem);
    getch();
    return 0;
 }
 
 //Función que se encarga de cambiar los valores
 void intercambio(int vector[],int i, int j)
 {
     int aux;
    aux=vector[i];
    vector[i]=vector[j];
    vector[j]=aux;
    return;
 }
//Función que se encarga de ordenar los valores con el Algoritmo de
//manera iterativa
 void quicksort(int vector[],int inf, int sup)
 {
    int i=inf, j=sup, x;
    x=vector[(i+j)/2]; //obteniendo el pivote
    while(i<=j)
    { 
        while(vector[i]<x)    //obteniendo elemento mayor de lado izquierdo del  pivote para intercambiar
            i++;
        while(vector[j]>x)   // obteniendo elemento menor de lado derecho del pivote a intercambiar
            j--;
        if(i<=j)             //intercambiando cuando se sigan presentando valores menores ala derecha y mayores ala izquierda
        {
            intercambio(vector,i,j);
            i++;
            j--;
         }
    }
    //Llamamos a la función quicksort para ordenar los elementos menores al pivote
    if(inf<j)
        quicksort(vector,inf,j);
    //Llamamos a la función quicksort para ordenar los elementos mayores al pivote
    if(i<sup)
        quicksort(vector,i,sup);
        return;
 }
 /* Función que se encarga de imprimir el los arreglos */
 void imprimeVector(int vector[],int elem)
 {
    int i;
    printf("\nVector ordenado con quicksort\n");
    for(i=0;i<elem;i++)
        printf("[%d] ",vector[i]);
    return;
 }