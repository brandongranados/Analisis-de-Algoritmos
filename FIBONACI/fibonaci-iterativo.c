//Ejemplo de una implementación de fibonaci de forma iterativa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    clock_t start_t=clock(), end_t;
  int x=0,y=1,z=0,cont,lim;
  float fina;
  puts ("Limite que quieres");
  scanf("%d",&lim);
  for (cont=0;cont<lim;cont++)
  {
      z=x+y;
      printf("%d\n",z);
      x=y;
      y=z;
  }
    end_t=clock();
    fina = (float)(((end_t-start_t)/CLOCKS_PER_SEC)*1000);
	printf("%f milisegundos\n", fina);
  system("PAUSE");
  return 0;
}
