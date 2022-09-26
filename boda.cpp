/* Implementación que resuelve el problema de la boda por medio de nodos y grafos
    Desarrollado por: Casiano Granados Brandon Antonio */
#include <iostream>
#include <string>
using namespace std;
typedef struct grafo
{
    int maxAristas;
    string valorNodo;
    struct grafo *aristas;
    struct grafo *siguiente;
    struct grafo *anterior;
}nodo;
typedef struct numMesas
{
    struct numMesas *siguienteMesa;
    struct numMesas *agregaSilla;
    struct grafo *agregaPersona;
}mesas;
class boda
{
    private:
        nodo *comienzaNodos;
        nodo *terminaNodos;
        nodo *direccionMasGrande;
        mesas *comienzaMesa;
        int cantNodos, maxMesas;
    public:
        nodo* creaNodos(int cant)
        {
            nodo *auxiliar = new nodo[cant];
            if(auxiliar == NULL)
                exit(1);
            auxiliar->siguiente = NULL;
            auxiliar->aristas = NULL;
            auxiliar->anterior = NULL;
            return auxiliar;
        }
        mesas* creaMesa()
        {
            mesas *temp = new mesas[1];
            if(temp == NULL)
                exit(1);
            temp->agregaPersona = NULL;
            temp->agregaSilla = NULL;
            temp->siguienteMesa = NULL;
            return temp;
        }
        int creaListaNodos();
        int creaAristasGrafo();
        int imprimeGrafo();
        void buscaDondeSentar();
        int mayorNumAristas();
        boda()
        {
            cout<<"cuantos nodos vas a necesitar"<<endl;
            cin>>cantNodos;
            creaListaNodos();
            creaAristasGrafo();
            buscaDondeSentar();
            imprimeGrafo();
        }
};
int main()
{
    boda organizaBoda;
    return 0;
}
/* Función que crea una lista de los nodos */
int boda::creaListaNodos()
{
    nodo *aux = creaNodos(1);
    comienzaNodos = creaNodos(1);
    if(comienzaNodos == NULL)
        exit(1);
    if(aux == NULL)
        exit(1);
    cout<<"que valor deseas para el nodo 1"<<endl;
    cin.ignore();
    getline(cin, comienzaNodos->valorNodo);
    comienzaNodos->siguiente = aux;
    for (int i=2; i<cantNodos; i++)
    {
        cout<<"que valor deseas para el nodo :"<<i<<endl;
        fflush(stdin);
        getline(cin, aux->valorNodo);
        aux->siguiente = creaNodos(1);
        if(aux->siguiente == NULL)
            exit(1);
        aux = aux->siguiente;
    }
    if(cantNodos == 1)
    {
        delete(aux);
        comienzaNodos->siguiente = NULL;
    }
    else
    {
        cout<<"que valor deseas para el nodo :"<<cantNodos<<endl;
        fflush(stdin);
        getline(cin, aux->valorNodo);
    }
    return 0;   
}
/* Función que crea las uniones de las personas que si pueden o quieren sentarse juntos */
int boda::creaAristasGrafo()
{
    nodo *auxi = comienzaNodos;
    nodo *auxi2;
    nodo *aristaAux;
    char temp;
    do
    {
        cout<<"CUANTAS ARISTAS VA A TENER EL NODO :"<<auxi->valorNodo<<endl;
        cin>>auxi->maxAristas;
        aristaAux = auxi;
        for(int i=0; i<auxi->maxAristas; i++)
        {
            aristaAux->aristas = creaNodos(1);
            if(aristaAux == NULL)
                exit(1);
            aristaAux->aristas->anterior = aristaAux;
            aristaAux = aristaAux->aristas;
        }
        auxi = auxi->siguiente;
    }while(auxi != NULL);
    auxi = comienzaNodos;
    do
    {
        aristaAux = auxi;
        auxi2 = comienzaNodos;
        do
        {
            if(auxi2 != auxi)
            {
                cout<<"DESEAS UNA CONEXION DE :"<<auxi->valorNodo<<", CON :"<<auxi2->valorNodo<<", [S/N]"<<endl;
                fflush(stdin);
                cin>>temp;
                if(temp == 's' || temp=='S')
                {
                    aristaAux = aristaAux->aristas;
                    aristaAux->siguiente = auxi2;
                }
            }
            auxi2 = auxi2->siguiente;
        }while(auxi2 != NULL);
        auxi = auxi->siguiente;
    }while(auxi != NULL);
    return 0;
}
/* Función que encarga de imprimir el mapa de grafos en consola */
int boda::imprimeGrafo()
{
    int i = 1;
    nodo *imprime = comienzaNodos;
    nodo *imprime2;
    mesas *imprimeMesa = comienzaMesa;
    mesas *imprimeMesa2;
    cout<<"\n"<<endl;
    while(imprime != NULL)
    {
        imprime2 = imprime->aristas;
        while(imprime2 != NULL)
        {
            cout<<"EL NODO :"<<imprime->valorNodo<<", TIENE CONEXIONES A :"<<imprime2->siguiente->valorNodo<<endl;
            imprime2 = imprime2->aristas;
        }
        cout<<endl;
        imprime = imprime->siguiente;
    }
    cout<<"\n"<<endl;
    while(imprimeMesa->siguienteMesa != NULL)
    {
        imprimeMesa2 = imprimeMesa->agregaSilla;
        while(imprimeMesa2->agregaSilla != NULL)
        {
            cout<<"LA MESA :"<<i<<", TIENE A LA PERSONA :"<<imprimeMesa2->agregaPersona->valorNodo<<endl;
            imprimeMesa2 = imprimeMesa2->agregaSilla;
        }
        i++;
        imprimeMesa = imprimeMesa->siguienteMesa;
        cout<<"\n";
    }
    return 0;
}
/* Función que busca en la lista de nodos quien tiene el mayor numero de uniones con otros
    nodos */
int boda::mayorNumAristas()
{
    int temp = cantNodos;
    direccionMasGrande = NULL;
    nodo *listaNodo = comienzaNodos;
    do
    {
        if(listaNodo->maxAristas <= temp && listaNodo->maxAristas != -1)
        {
            temp = listaNodo->maxAristas;
            direccionMasGrande = listaNodo;
        }
        listaNodo = listaNodo->siguiente;
    }while(listaNodo != NULL);
    if(direccionMasGrande != NULL)
    {
        terminaNodos = direccionMasGrande;
        do
        {
            terminaNodos = terminaNodos->aristas;
        }while(terminaNodos->aristas != NULL);
    }
    if(temp == cantNodos)
        temp = -1;
    return temp;
}
/* Función que busca donde sentar a todos los usuarios de los nodos contemplando 
    con quien si se pueden sentar y con quien no, utilizando el algoritmo gloton */
void boda::buscaDondeSentar()
{
    int retorno;
    bool evalua, truena;
    nodo *analizaNodo, *revisaNodos, *consideraNodo;
    mesas *recorreMesa, *recorreSilla, *revisaSilla, *temp;
    comienzaMesa = creaMesa();
    if(comienzaMesa == NULL)
        exit(1);
    recorreMesa = comienzaMesa;
    cout<<"SE CREA UNA MESA"<<endl;
    while (mayorNumAristas() != -1)
    {
        direccionMasGrande->maxAristas = -1;
        recorreMesa->agregaSilla = creaMesa();
        if(recorreMesa->agregaSilla == NULL)
            exit(1);
        cout<<"SE CREA UNA SILLA"<<endl;
        recorreSilla = recorreMesa->agregaSilla;
        recorreSilla->agregaPersona = direccionMasGrande;
        analizaNodo = terminaNodos;
        recorreSilla->agregaSilla = creaMesa();
        if(recorreSilla->agregaSilla == NULL)
            exit(1);
        cout<<"SE CREA UNA SILLA"<<endl;
        do
        {
            revisaSilla = recorreSilla;
            do
            {
                revisaNodos = analizaNodo->siguiente->aristas;
                do
                {
                    if(revisaSilla->agregaPersona == revisaNodos->siguiente)
                        evalua = true;
                    else
                        evalua = false;
                    revisaNodos = revisaNodos->aristas;
                }while(revisaNodos != NULL && !evalua);
                consideraNodo = analizaNodo->siguiente;
                if(revisaNodos == NULL && !evalua)
                    truena = false;
                else
                    truena = true;
                temp = revisaSilla;
                revisaSilla = revisaSilla->agregaSilla;
            }while(revisaSilla->agregaSilla != NULL && truena);
            if(evalua && consideraNodo->maxAristas > -1)
            {
                revisaSilla->agregaPersona = consideraNodo;
                consideraNodo->maxAristas = -1;
                revisaSilla->agregaSilla = creaMesa();
                if(revisaSilla->agregaSilla == NULL)
                    exit(1);
                cout<<"SE CREA UNA SILLA"<<endl;
            }
            analizaNodo = analizaNodo->anterior;
        }while(analizaNodo != direccionMasGrande);
        recorreMesa->siguienteMesa = creaMesa();
        if(recorreMesa->siguienteMesa == NULL)
            exit(1);
        cout<<"SE CREA UNA MESA"<<endl;
        temp = recorreMesa;
        recorreMesa = recorreMesa->siguienteMesa;
    }
    return;
}