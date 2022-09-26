/* Implementación de Algoritmo Quicksort
 * Desarrollado por: Casiano Granados Brandon Antonio
  */
public class quicksort{
    public static void main (String args[])
    {
        int arreglo[] = {10,8,5,7,1,3,6,2,9,4};
        int tam = arreglo.length-1;
        imprime(arreglo);
        qs(arreglo, 0, tam);
        imprime(arreglo);
        return;
    }
    /* Función encargada de imprimir los arreglos */
    private static void imprime(int imp[])
    {
        for(int i=0; i<imp.length; i++)
            System.out.println(imp[i]);
        return;
    }
    /* Función que ordena los arreglos con el algoritmo */
    private static void qs(int vector[], int inf, int sup)
    {
        int izq, der, pivote, aux;
        izq = inf;
        der = sup;
        pivote = vector[(izq + der)/2];
        do
        {
            while((vector[izq] < pivote) && (izq < sup))//Aquí se revisa si el vector es menor al pivote
                izq++;
            while((vector[der] > pivote) && (der > inf))//Aquí se revisa si el vector es maqyor al pivote
                der--;
            if(izq <= der)//Aquí cambiamos los valores para ordenar
            {
                aux = vector[izq];
                vector[izq] = vector[der];
                vector[der] = aux;
                izq++;
                der++;
            }
        }while(izq <= der);
        //Con los arreglos de valores menores y mayores se envían a la misma función para ordenar
        if(inf < der)
            qs(vector, inf, der);
        if(izq < sup)
            qs(vector, izq, sup);
        return;
    }
}