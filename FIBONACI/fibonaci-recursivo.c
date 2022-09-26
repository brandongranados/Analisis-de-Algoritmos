//Ejemplo de una implementación de fibonaci recursivo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fibonacci(int n)
{
  if (n>2)
    return fibonacci(n-1) + fibonacci(n-2);
  else if (n==2)
    return 1;
  else if (n==1)
    return 1;
  else if (n==0)
    return 0;
}
int main()
{
    clock_t tiempoInicio=clock(), tiempoFin;
    float termina;
    int num,limite;
    puts ("INGRESE LIMITE");
    scanf("%d",&limite);
    for (num=0; num<limite; num++)
    {
      printf("%d\n", fibonacci(num));
    }
    tiempoFin=clock();
    termina= (float)(((tiempoFin-tiempoInicio)/CLOCKS_PER_SEC)*1000);
	printf("%f milisegundos \n", termina);
  system("PAUSE");
  return 0;
}
