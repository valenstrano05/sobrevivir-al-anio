#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iomanip>

using namespace std;

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
    int dado;

    switch(mes)
    {
    case 1:
        datos[index_SaldoPesos]+=150000;
        cout<<"Deposito de garantia: -$180000"<<endl;
        datos[index_SaldoPesos]-=180000;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 2:
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 3:
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 4:
        cout<<"Aumento paritario: aumento del 15% al sueldo"<<endl;
        cout<<"(+$"<<datos[index_Sueldo]*0.15<<" al sueldo"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 5:
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 6:
        dado=rand()%2;
        if (dado==0)
        {
            cout<<"BTC se fue a la luna! (aumento del 60%)"<<endl;
            datos[index_PrecioBTC]*=1.60;
        }
        else
        {
            cout<<"BTC rompio el piso... (disminución del 50%)"<<endl;
            datos[index_PrecioBTC]*=0.50;
        }
        cout<<"¡Llego el aguinaldo!"<<endl;
        cout<<"(+$"<<datos[index_Sueldo]*0.50<<" este mes"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 7:
        cout<<"Aumento paritario: aumento del 15% al sueldo"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 8:
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 9:
        cout<<"Actualizacion de alquiler"<<endl;
        datos[index_GastosAlquiler]=datos[index_GastosAlquiler]*1.4;
        datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 10:
        cout<<"Aumento paritario: aumento del 15% al sueldo"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 11:
        dado=rand()%2;
        if (dado==0)
        {
            cout<<"BTC se fue a la luna! (aumento del 60%)"<<endl;
            datos[index_PrecioBTC]*=1.60;
        }
        else
        {
            cout<<"BTC rompio el piso... (disminución del 50%)"<<endl;
            datos[index_PrecioBTC]*=0.50;
        }
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 12:
        cout<<"Aguinaldo"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        cout<<"Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    default:
        break;
    }
    datos[index_SaldoPesos]+=datos[index_Sueldo];

}

void imprevistos(double datos[])
{
    int cantidadImprevistos=0;
    double totalImprevistos=0.0;
    string imprevistoNombre[12]=
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

    double imprevistoCosto[12]=
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
        cout<<imprevistoNombre[indice]<<endl;
        cout<<"Costo: -$"<<imprevistoCosto[indice]<<endl;
        totalImprevistos+=imprevistoCosto[indice];
        cantidadImprevistos++;
        aumentoAlquiler(indice, datos);

        dado[1]=rand()%100;
        if (dado[1]<15)
        {
            indice=rand()%12;
            cout<<imprevistoNombre[indice]<<endl;
            cout<<"Costo: -$"<<imprevistoCosto[indice]<<endl;
            totalImprevistos+=imprevistoCosto[indice];
            cantidadImprevistos++;
            aumentoAlquiler(indice, datos);

            dado[2]=rand()%100;
            if (dado[2]<10)
            {
                indice=rand()%12;
                cout<<imprevistoNombre[indice]<<endl;
                cout<<"Costo: -$"<<imprevistoCosto[indice]<<endl;
                totalImprevistos+=imprevistoCosto[indice];
                cantidadImprevistos++;
                aumentoAlquiler(indice, datos);
            }
        }
    }
    if (cantidadImprevistos==0)
    {
        cout<<"Sin imprevistos este mes."<<endl;
    }
    else if (datos[index_FondoEmergencia]>=totalImprevistos)
    {
        cout<<"(Tu fondo lo pudo cubrir...)"<<endl;
        datos[index_FondoEmergencia]-=totalImprevistos;
    }
    else
    {
        datos[index_SaldoPesos]-=totalImprevistos;
    }
}

void aumentoAlquiler(int indice, double datos[])
{
    if(indice==8)
    {
        datos[index_GastosAlquiler]+=20000;
        datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
    }
}

void aumentoPorInflacion(double datos[], int rondas)
{
    const float inflacion = 1.07;
    int dado;
    int contadorDisminucion=0;
    datos[index_SaldoPesos]/=inflacion;
    datos[index_FondoEmergencia]/=inflacion;
    datos[index_GastosComida]*=inflacion;
    datos[index_GastosServicios]*=inflacion;
    datos[index_GastosTransporte]*=inflacion;
    datos[index_GastosAlquiler]*=inflacion;
    datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
    datos[index_InflacionAcumulada]*=1.07;
    datos[index_PrecioSP500]*=1.01;
    dado=rand()%100;
    if (dado<=9)
    {
        if (contadorDisminucion<5)
        {
            datos[index_PrecioDolar]*=0.99;
            contadorDisminucion++;
        }
        else if (dado<=29)
        {
            datos[index_PrecioDolar]*=1.04;
        }
        else if (dado<=59)
        {
            datos[index_PrecioDolar]*=1.05;
        }
        else
        {
            datos[index_PrecioDolar]*=1.06;
        }
    }
    if (rondas%2==0)
    {
        datos[index_PrecioBTC]*=1.25;
    }
    else
    {
        datos[index_PrecioBTC]*=0.80;
    }
}
