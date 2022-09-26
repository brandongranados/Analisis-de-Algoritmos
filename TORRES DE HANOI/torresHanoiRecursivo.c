/* Implementación de las torres de Hanoi de manera recursiva */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int move_torre (int n ,int from ,int to);
int move_torre (int n, int from, int to)
{
	int aux, n_moves;
	if (n==1)
	{
		printf ("Mueva el disco [1] de la torre no. %d a la torre no.%d \n",from, to);
		return (1);
	}
	aux = 6 - from - to;
	n_moves= move_torre (n-1,from, aux);
	printf ("Mueva el disco [%d] de la torre no. %d a la torre no.%d \n",n, from, to);
	n_moves++;
	n_moves += move_torre(n-1,aux,to);
	return(n_moves);
}
int main ()
{
	clock_t start_t=clock(), end_t;
	int n, n_moves;
do
{
printf("Introduzca el numero de Discos en la Torre: ");
scanf ("%d",&n);
} while (n<=0);
n_moves=move_torre(n,1,3);
if (n_moves<=1)
	printf("La solución requiere %d movimiento.n \n",n_moves);
else
	printf("La solución requiere %d movimientos.n \n",n_moves);
end_t=clock();
float final = (float)(((end_t-start_t)/CLOCKS_PER_SEC)*1000);
printf("%f milisegundos\n", final);
system("PAUSE");
return(0);
}