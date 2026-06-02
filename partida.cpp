#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iomanip>

const int index_Sueldo=0;
const int index_SaldoPesos=1;
const int index_FondoEmergencia=2;
const int index_Dolares=3;
const int index_BTC=4;
const int index_SP500=5;
const int index_PrecioDolar=6;
const int index_PrecioBTC=7;
const int index_PrecioSP500=8;
const int index_GastosAlquiler=9;
const int index_GastosServicios=10;
const int index_GastosTransporte=11;
const int index_GastosComida=12;
const int index_GastosFijos=13;
const int index_MesesRojo=14;
const int index_MesesSinFondo=15;
const int index_AhorroMaximo=16;
const int index_AhorroMinimo=17;
const int index_MejorMes=18;
const int index_PeorMes=19;
const int index_InflacionAcumulada=20;

using namespace std;

void jugarPartida(string nombre, int rondas)
{
    double datosPartida[21];
    cargarDatos(datosPartida);
    for(int i=1; i<=rondas; i++)
    {
        system("cls");
        cout<<"====================================="<<endl;
        cout<<"  MES "<<i<<"/"<<rondas<<"       Jugador: "<<nombre<<endl;
        imprevistos(datosPartida);
        eventosFijos(i, datosPartida);
        cout<<"TENENCIAS ACTUALES: "<<endl;
        cout<<"Fondo de emergencias: "<<datosPartida[index_FondoEmergencia]<<endl;
        cout<<"Dolares: "<<datosPartida[index_Dolares]<<endl;
        cout<<"Bitcoin: "<<datosPartida[index_BTC]<<endl;
        cout<<"SP500: "<<datosPartida[index_SP500]<<endl;
        cout<<""<<endl;
        cout << "Sueldo: $" << datosPartida[index_Sueldo] << endl;
        cout << "Gastos fijos: $" << datosPartida[index_GastosFijos] << endl;
        cout << "Saldo final: $" << datosPartida[index_SaldoPesos] << endl;
        cout<<"====================================="<<endl;
        aumentoPorInflacion(datosPartida);
        system("pause");
    }
    mostrarResumen(datosPartida);
}

void cargarDatos (double datos[])
{

    for(int a=0; a<21; a++)
    {
        switch(a)
        {
        case 0:
            datos[a]=500000.0;
            break;
        case 1:
            datos[a]=0.0;
            break;
        case 2:
            datos[a]=0.0;
            break;
        case 3:
            datos[a]=0;
            break;
        case 4:
            datos[a]=0.0;
            break;
        case 5:
            datos[a]=0.0;
            break;
        case 6:
            datos[a]=1100.0;
            break;
        case 7:
            datos[a]=65000.0;
            break;
        case 8:
            datos[a]=500.0;
            break;
        case 9:
            datos[a]=180000.0;
            break;
        case 10:
            datos[a]=45000.0;
            break;
        case 11:
            datos[a]=30000.0;
            break;
        case 12:
            datos[a]=80000.0;
            break;
        case 13:
            datos[a]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
            break;
        case 14:
            datos[a]=0;
            break;
        case 15:
            datos[a]=0;
            break;
        case 16:
            datos[a]=-9999999.0;
            break;
        case 17:
            datos[a]=9999999.0;
            break;
        case 18:
            datos[a]=0;
            break;
        case 19:
            datos[a]=0;
            break;
        case 20:
            datos[a]=1.0;
            break;
        default:
            break;
        }
    }
}

void eventosFijos(int mes, double datos[])
{

    switch(mes)
    {
    case 1:
        cout<<"Deposito de garantia"<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosAlquiler];
        break;
    case 4:
        cout<<"Aumento paritario"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        break;
    case 6:
        cout<<"Aguinaldo"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        break;
    case 7:
        cout<<"Aumento paritario"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        break;
    case 9:
        cout<<"Actualizacion de alquiler"<<endl;
        datos[index_GastosAlquiler]=datos[index_GastosAlquiler]*1.4;
        datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
        break;
    case 10:
        cout<<"Aumento paritario"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        break;
    case 12:
        cout<<"Aguinaldo"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        break;
    default:
        break;
    }
    datos[index_SaldoPesos]+=datos[index_Sueldo];
    datos[index_SaldoPesos]-=datos[index_GastosFijos];
}


void imprevistos(double datos[])
{
    int cantidad_imprevistos = 0;
    double total_imprevistos=0.0;
    string imprevisto_nombre[12]=
    {
        "Se rompio el lavarropas",
        "Visita medica inesperada",
        "Multa de transito",
        "Tecnico de internet",
        "Regalo de cumpleaños obligado",
        "Rompiste un vidrio en el gimnasio",
        "Cena o salida social ineludible",
        "Se rompio la pantalla del celular",
        "Subio la expensa del edificio",
        "Mini escapada de ultimo momento",
        "Black Friday - oferta irresistible",
        "Regalos de fin de año"
    };

    double imprevisto_costo[12]=
    {
        70000, 45000, 30000, 25000, 35000, 55000,
        50000, 80000, 20000, 90000, 60000, 55000
    };

    int dado[3];
    int indice;
    dado[0]=rand()%100;

    if (dado[0]<70)
    {
        indice=rand() % 12;
        cout<<imprevisto_nombre[indice]<<endl;
        cout<<"Costo: -$"<<imprevisto_costo[indice]<<endl;
        total_imprevistos+=imprevisto_costo[indice];
        cantidad_imprevistos++;
        aumentoAlquiler(indice, datos);

        dado[1]=rand()%100;
        if (dado[1]<15)
        {
            indice=rand()%12;
            cout<<imprevisto_nombre[indice]<<endl;
            cout<<"Costo: -$"<<imprevisto_costo[indice]<<endl;
            total_imprevistos+=imprevisto_costo[indice];
            cantidad_imprevistos++;
            aumentoAlquiler(indice, datos);

            dado[2]=rand()%100;
            if (dado[2]<10)
            {
                indice=rand()%12;
                cout<<imprevisto_nombre[indice]<<endl;
                cout<<"Costo: -$"<<imprevisto_costo[indice]<<endl;
                total_imprevistos+=imprevisto_costo[indice];
                cantidad_imprevistos++;
                aumentoAlquiler(indice, datos);
            }
        }
    }
    if (cantidad_imprevistos==0)
    {
        cout<<"Sin imprevistos este mes."<<endl;
    }

    datos[index_SaldoPesos]-=total_imprevistos;
}

void aumentoAlquiler(int indice, double datos[])
{
    if(indice==8)
    {
        datos[index_GastosAlquiler]+=20000;
        datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
    }
}

void aumentoPorInflacion(double datos[])
{
    const float inflacion = 1.07;
    datos[index_SaldoPesos]/=inflacion;
    datos[index_FondoEmergencia]/=inflacion;
    datos[index_GastosComida]*=inflacion;
    datos[index_GastosServicios]*=inflacion;
    datos[index_GastosTransporte]*=inflacion;
    datos[index_GastosAlquiler]*=inflacion;
    datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
    datos[index_InflacionAcumulada]*=1.07;
}

void mostrarResumen(double datos[]){
    int resultado;
    double patrimonio=datos[index_SaldoPesos]+datos[index_FondoEmergencia];
    double patrimonioReal=patrimonio/datos[index_InflacionAcumulada];
    system("cls");
    cout<<"====================================="<<endl;
    cout<<"           RESUMEN FINAL             "<<endl;
    cout<<"Patrimonio nominal: $"<<patrimonio<<endl;
    cout<<"Patrimonio real: $"<<patrimonioReal<<endl;
    cout<<""<<endl;
    if(patrimonioReal>500000*1.10){
        resultado=0;
    }else if(patrimonioReal>=500000*0.90){
        resultado=1;
    }else{
        resultado=2;
    }
    switch (resultado)
    {
    case 0:
        cout<<"¡Le ganaste a la inflacion!";
        break;
    case 1:
        cout<<"Le empataste a la inflacion...Podría haber sido peor.";
        break;
    case 2:
        cout<<"Que desastre... Te comió la inflación..."<<endl;
        break;
    default:
        break;
    }
    cout<<"====================================="<<endl;
    system("pause");
}
