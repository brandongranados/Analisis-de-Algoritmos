/* Implementación de ejemplo para calculo de amortización de una persona
    Desarrollado por: Casiano Granados Brandon Antonio */
#include <iostream>
#include <cstdlib>
using namespace std;
class banco
{
    public:
        int hipotecaBanco();
        banco();
    private:
        float capitalPen, tasaInteres;
        float intereses, pagoMensual, capInicial;
        float amortizacion, finalPago;
        int meses, cont;
};
//Contructor donde inicializamos valores miembro de la clase
banco::banco()
{
    cout<<"CUANTO ES EL PRESTAMO QUE NECESITAS"<<endl;
    cin>>capInicial;
    cout<<"A CUENTOS MESES PAGAS"<<endl;
    cin>>meses;
    tasaInteres = 0.3;
    capitalPen = capInicial;
    cont=0;
    finalPago=0;
    hipotecaBanco();
    cout<<"PRESTAMO = "<<capInicial<<"\n PAGAS :"<<finalPago<<endl;
    system("PAUSE");
}
//Funció que calcula los pagos del usuario
int banco::hipotecaBanco()
{
    cont+=1;
    if(cont >= meses)
        return 0;
    intereses = capitalPen * tasaInteres;
    pagoMensual = (capInicial/meses)+intereses;
    amortizacion = pagoMensual-intereses;
    capitalPen -= (capInicial/meses);
    finalPago+=pagoMensual;
    if(amortizacion > capitalPen)
        amortizacion = capitalPen;
    return hipotecaBanco();
}
int main()
{
    banco calcula;
    return 0;
}