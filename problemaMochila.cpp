/* Implementación sobre la solución al problema de la mochila
    Desarrollado por: Casiano Granados Brandon Antonio */
#include <iostream>
using namespace std;
class mochila
{
        int numArticulos, capMochila, valMax;
        int artAlmEnMochila [10000], pesoArt[10000], artTemp[10000], artSelec [10000];
        void calcArtAdecCamp(int, int, int);
    public:
        mochila();
};
int main()
{
    mochila mejores;
    return 0;
}
//Constructor con el que se inicializan los valores miembro de la clase
mochila::mochila()
{
    int i;
    valMax=0; 
    cout<<"Ingrese la capacidad máxima de la mochila:"<<endl;;
    cin>>capMochila;
    cout<<"Ingrese el número de elementos:"<<endl;
    cin>>numArticulos;
    cout<<"Ingrese el peso de los elementos en orden:"<<endl;
    for(i=1;i<=numArticulos;i++) 
       cin>>pesoArt [i];
    cout<<"Ingrese el valor de los elementos en orden:"<<endl;
    for(i=1;i<=numArticulos;i++) 
       cin>>artAlmEnMochila[i];
    calcArtAdecCamp(1,0,0);
    cout<<"El valor máximo es:"<<endl;
    cout<<"\n"<<valMax<<endl;
    cout<<"Los elementos seleccionados están en orden (0 significa no seleccionado, 1 significa seleccionado)"<<endl;
    for(i=1;i<=numArticulos;i++) 
        cout<<artSelec[i]<<endl;
    cout<<endl;
}
//Función donde resuelve el problema de la mochila
void mochila::calcArtAdecCamp(int i,int valActArt,int pesoActArt)
 {
    int j;
    if (i> numArticulos)
    {
        if(valActArt>valMax)
        {
            valMax=valActArt;
            for(i=0;i<=numArticulos;i++) artSelec[i]=artTemp[i];
        }
    }
    else 
        for(j=0;j<=1;j++)  
        {
            artTemp[i]=j;
            if(pesoActArt+artTemp[i]*pesoArt[i]<=capMochila)  
            {
                pesoActArt+=pesoArt[i]*artTemp[i];
                valActArt+=artAlmEnMochila[i]*artTemp[i];
                calcArtAdecCamp(i+1,valActArt,pesoActArt);
                pesoActArt-=pesoArt[i]*artTemp[i];
                valActArt-=artAlmEnMochila[i]*artTemp[i];
            }
        }
}