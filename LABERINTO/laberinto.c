/* Implementación desarrollada para resolver laberintos e imprimirlos en pantalla
    Falta revisar al dirección dinámica en donde se desborda
    Desarrollado por: Casiano Granados Brandon Antonio */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
/*p = PARED
-= ESPACIOS CERRADOS
+ = CAMINO CREADO
.= ESPACIO NO EVALUADo O VACIO
F = Final de laberinto*/
char** creaLaberinto(int*, int*);
int caminoLaberinto(char **, int*, int*, int*, int*);
void avanza(char*);
void retrocede(char*);
int main ()
{
    int renglon, columna, j=0, k=0;
    char **laberinto=creaLaberinto(&renglon, &columna);
    if(laberinto==NULL)
    {
        printf("ERROR AL CREAR LABERINTO");
        exit(1);
    }
    caminoLaberinto(laberinto, &renglon, &columna, &j, &k);
    system("CLS");
    puts("IMPRIMIENDO CAMINO DE LABERINTO");
    printf("p = PARED \n -= ESPACIOS CERRADOS \n + = CAMINO CREADO \n .= ESPACIO NO EVALUADo O VACIO  \n F = Final de laberinto \n");
    for(j=0; j<renglon; j++)
    {
        printf("\n");
        for(k=0; k<columna; k++)
            printf("|%c",laberinto[j][k]);
    }
    free(laberinto);
    printf("\n");
    system("PAUSE");
    return 0;
}
char**  creaLaberinto(int *r, int *c)
{
    int p,q;
    char **creaLaber=NULL, temp;
    puts("Dimension del laberinto");
    puts("numero de renglones");
    scanf("%d",r);
    puts("numero de columnas");
    scanf("%d",c);
    creaLaber = (char **) malloc ((*r)*sizeof(char));
    for (p=0; p<*r; p++)
        creaLaber[p] = (char *) malloc ((*c)*sizeof(char));
    puts("ingresaremos las posiciones que son pared");
    for (p=0; p<*r; p++)
        for (q=0; q<*c; q++)
            {
                //system("CLS");
                printf("PRESIONA ---S----ES PARED \n PRESIONA ----LO QUE SEA---- NO ES PARED\n ¿deseas que la posicion [%d][%d] sea pared? \n",p,q);
                fflush(stdin);
                __fpurge(stdin);
                scanf("%c",&temp);
                if (temp=='S' || temp=='s')
                    creaLaber[p][q]= 'p';
                else
                    creaLaber[p][q]= '.';
            }
    creaLaber[0][0]='c';
    creaLaber[*r-1][*c-1]='F';
    return creaLaber;
}
int caminoLaberinto(char **camLaberinto, int *re, int *co, int *posR, int *posC)
{
    char posDer, posAbajo, posIzq, posArriba;
    if(camLaberinto==NULL)
    {
        printf("ERROR AL RECIBIR LA MEMORIA DEL LABERINTO");
        exit(1);
    }
    //CALCULA FRONTERAS, CUADROS SUPERIORES E INFERIORES EN RENGLONES
    if(*posR == 0)
    {
        posArriba = 'p';
        posAbajo = camLaberinto[*posR+1][*posC];
    }
    else if(*posR == *re-1)
    {
        posArriba = camLaberinto[*posR-1][*posC];
        posAbajo = 'p';
    }
    else
    {
        posArriba = camLaberinto[*posR-1][*posC];
        posAbajo = camLaberinto[*posR+1][*posC];
    }
    //CALCULA FRONTERAS, CUADROS IZQUIERDOS Y DERECHOS EN COLUMNAS
    if(*posC == 0)
    {
        posIzq = 'p';
        posDer = camLaberinto[*posR][*posC+1];
    }
    else if(*posC == *co-1)
    {
        posIzq = camLaberinto[*posR][*posC-1];
        posDer = 'p';
    }
    else
    {
        posIzq = camLaberinto[*posR][*posC-1];
        posDer = camLaberinto[*posR][*posC+1];
    }
    //EVALUA SI EL BOT LLEGO AL FINAL DEL LABERINTO
    if(posAbajo == 'F' || posDer =='F')
    {
        avanza(&camLaberinto[*posR][*posC]);
        return 0;
    }
    //CALCULA LOS PASOS PARA AVANZAR EN EL LABERINTO
    if(posAbajo == '.')
    {
        avanza(&camLaberinto[*posR][*posC]);
        *posR+=1;
    }
    else if (posDer == '.')
    {
        avanza(&camLaberinto[*posR][*posC]);
        *posC+=1;
    }
    else if(posIzq == '.')
    {
        avanza(&camLaberinto[*posR][*posC]);
        *posC-=1;
    }
    else if(posArriba == '.')
    {
        avanza(&camLaberinto[*posR][*posC]);
        *posR-=1;
    }
    //CALCULA Y MARCA LOS CAMINOS CERRADOS
    else if(posAbajo == '+')
    {
        retrocede(&camLaberinto[*posR][*posC]);
        *posR+=1;
    }
    else if (posDer == '+')
    {
        retrocede(&camLaberinto[*posR][*posC]);
        *posC+=1;
    }
    else if(posIzq == '+')
    {
        retrocede(&camLaberinto[*posR][*posC]);
        *posC-=1;
    }
    else if(posArriba == '+')
    {
        retrocede(&camLaberinto[*posR][*posC]);
        *posR-=1;
    }
    //EVALUA RECURSIVIDAD
    return caminoLaberinto(camLaberinto, re, co, posR, posC);
}
void avanza(char *sig)
{
    if(sig==NULL)
    {
        printf("ERROR AL RECIBIR LA MEMMORIA PARA AVANZAR");
        exit(1);
    }
    *sig = '+';
    return;
}
void retrocede(char *ant)
{
    if(ant==NULL)
    {
        printf("ERROR AL RECIBIR LA MEMMORIA PARA RETROCEDER");
        exit(1);
    }
    *ant = '-';
    return;
}