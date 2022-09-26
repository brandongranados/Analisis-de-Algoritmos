#include <stdio.h> // Para printf
#include <math.h> // Para floor

// Prototipos de las funciones
int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha);
int busquedaBinariaConWhile(int arreglo[], int busqueda, int tamanioDelArreglo);

int main(){
    int numeros[] = {1, 2, 4, 8, 15, 16, 20, 50};
    int busqueda = 16;
    int longitudDelArreglo = sizeof(numeros) / sizeof(numeros[0]);
    int resultadoBusquedaRecursiva = busquedaBinariaRecursiva(numeros, busqueda, 0, longitudDelArreglo - 1);
    printf("Al buscar %d recursivamente, el resultado es %d\n", busqueda, resultadoBusquedaRecursiva);
    int resultadoBusquedaWhile = busquedaBinariaConWhile(numeros, busqueda, longitudDelArreglo);
    printf("Al buscar %d con while, el resultado es %d\n", busqueda, resultadoBusquedaWhile);
}

/**
 * 
 * Implementación del algoritmo de 
 * búsqueda binaria recursiva en un arreglo usando C
 * 
 * Funciona con arreglos de números
 * 
 * Autor: parzibyte
 * Web: parzibyte.me/blog
 */
int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha) return -1;

    int indiceDeLaMitad = floor((izquierda + derecha) / 2);

    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (busqueda == valorQueEstaEnElMedio){
        return indiceDeLaMitad;
    }
    
    if (busqueda < valorQueEstaEnElMedio){
        // Entonces está hacia la izquierda
        derecha = indiceDeLaMitad - 1;
    }else{
        // Está hacia la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

/**
 * 
 * Implementación del algoritmo de 
 * búsqueda binaria recursiva en un arreglo usando C
 * 
 * Funciona con arreglos de números
 * 
 * Autor: parzibyte
 * Web: parzibyte.me/blog
 */
int busquedaBinariaConWhile(int arreglo[], int busqueda, int tamanioDelArreglo){
    // Nota: el tamaño del arreglo es necesario porque cuando se recibe
    // como argumento no se puede calcular dentro de la función
    int izquierda = 0, derecha = tamanioDelArreglo - 1;
    while (izquierda <= derecha){
        int indiceDeLaMitad = floor((izquierda + derecha) / 2);

        int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];

        if (busqueda == valorQueEstaEnElMedio){
            // En caso de encontrar lo que buscamos, terminamos la función
            // y regresamos el índice
            return indiceDeLaMitad;
        }
        
        if (busqueda < valorQueEstaEnElMedio){
            // Entonces está hacia la izquierda
            derecha = indiceDeLaMitad - 1;
        }else{
            // Está hacia la derecha
            izquierda = indiceDeLaMitad + 1;
        }
    }
    // Termina el ciclo y no encontramos nada
    return -1;
}