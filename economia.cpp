#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iomanip>
#include <conio.h>

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
const int index_ImprevistosAcumulados=21;
const int index_PorcentajeDolar=22;
const int index_PorcentajeBTC=23;
const int index_PorcentajeSP500=24;
const int index_SaldoInicioMes=25;

void cargarDatosPat(double datospat[])
{
    for (int a=0; a<5; a++)
    {
        switch (a)
        {
        case 0:
            datospat[a]=0.0;
            break;
        case 1:
            datospat[a]=0.0;
            break;
        case 2:
            datospat[a]=0.0;
            break;
        case 3:
            datospat[a]=0.0;
            break;
        case 4:
            datospat[a]=0.0;
            break;

        default:
            break;
        }

    };
}
void cargarDatos (double datos[])
{

    for(int a=0; a<26; a++)
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
            datos[a]=0.0;
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
        case 21:
            datos[a]=0.0;
            break;
        case 22:
            datos[a]=0.0;
            break;
        case 23:
            datos[a]=0.0;
            break;
        case 24:
            datos[a]=0.0;
            break;
        case 25:
            datos[a]=0.0;
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
        cout<<" Deposito de garantia: -$180000"<<endl;
        datos[index_SaldoPesos]-=180000;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 2:
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 3:
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 4:
        cout<<" Aumento paritario: aumento del 15% al sueldo"<<endl;
        cout<<" (+$"<<datos[index_Sueldo]*0.15<<" al sueldo)"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 5:
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 6:
        dado=rand()%2;
        if (dado==0)
        {
            cout<<" BTC se fue a la luna! (aumento del 70%)"<<endl;
            datos[index_PrecioBTC]*=1.70;
            datos[index_PorcentajeBTC]=70;
        }
        else
        {
            cout<<" BTC rompio el piso... (disminucion del 80%)"<<endl;
            datos[index_PrecioBTC]*=0.20;
            datos[index_PorcentajeBTC]=-80;
        }
        cout<<" ¡Llego el aguinaldo! (+$"<<datos[index_Sueldo]*0.50<<")"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 7:
        cout<<" Aumento paritario: aumento del 15% al sueldo"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 8:
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 9:
        cout<<" Actualizacion de alquiler"<<endl;
        datos[index_GastosAlquiler]=datos[index_GastosAlquiler]*1.4;
        datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 10:
        cout<<" Aumento paritario: aumento del 15% al sueldo"<<endl;
        datos[index_Sueldo]=datos[index_Sueldo]*1.15;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 11:
        dado=rand()%2;
        if (dado==0)
        {
            cout<<" BTC se fue a la luna! (aumento del 70%)"<<endl;
            datos[index_PrecioBTC]*=1.70;
            datos[index_PorcentajeBTC]=70;
        }
        else
        {
            cout<<" BTC rompio el piso... (disminución del 80%)"<<endl;
            datos[index_PrecioBTC]*=0.20;
            datos[index_PorcentajeBTC]=-80;
        }
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
        datos[index_SaldoPesos]-=datos[index_GastosFijos];
        break;
    case 12:
        cout<<" ¡Llego el aguinaldo! (+$"<<datos[index_Sueldo]*0.50<<")"<<endl;
        datos[index_SaldoPesos]+=datos[index_Sueldo]*0.50;
        cout<<" Gastos fijos: -$"<<datos[index_GastosFijos]<<endl;
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
        " Se rompio el lavarropas...",
        " Tuviste una visita medica inesperada",
        " Te comiste una multa de transito...",
        " Llamaste al tecnico de internet",
        " Regalo de cumpleaños obligado",
        " Rompiste un vidrio en el gimnasio...",
        " Salida con amigos ineludible",
        " Se rompio la pantalla del celular...",
        " Subio la expensa del edificio...",
        " Mini escapada de ultimo momento",
        " Black Friday - oferta irresistible",
        " Regalos de fin de año"
    };

    double imprevistoCosto[12]=
    {
        70000, 45000, 30000, 25000, 35000, 55000,
        50000, 80000, 20000, 90000, 60000, 55000
    };

    int dado[3];
    int indice;
    datos[index_ImprevistosAcumulados]=0.0;
    dado[0]=rand()%100;

    if (dado[0]<70)
    {
        indice=rand() % 12;
        cout<<imprevistoNombre[indice]<<endl;
        cout<<" Costo: -$"<<imprevistoCosto[indice]<<endl;
        totalImprevistos+=imprevistoCosto[indice];
        cantidadImprevistos++;
        aumentoAlquiler(indice, datos);

        dado[1]=rand()%100;
        if (dado[1]<15)
        {
            indice=rand()%12;
            cout<<imprevistoNombre[indice]<<endl;
            cout<<" Costo: -$"<<imprevistoCosto[indice]<<endl;
            totalImprevistos+=imprevistoCosto[indice];
            cantidadImprevistos++;
            aumentoAlquiler(indice, datos);

            dado[2]=rand()%100;
            if (dado[2]<10)
            {
                indice=rand()%12;
                cout<<imprevistoNombre[indice]<<endl;
                cout<<" Costo: -$"<<imprevistoCosto[indice]<<endl;
                totalImprevistos+=imprevistoCosto[indice];
                cantidadImprevistos++;
                aumentoAlquiler(indice, datos);
            }
        }
    }
    if (cantidadImprevistos==0)
    {
        cout<<" Sin imprevistos este mes."<<endl;
    }
    else if (datos[index_FondoEmergencia]>=totalImprevistos)
    {
        cout<<" (Tu fondo lo pudo cubrir...)"<<endl;
        datos[index_FondoEmergencia]-=totalImprevistos;
        datos[index_ImprevistosAcumulados]=totalImprevistos;
    }
    else if (datos[index_FondoEmergencia]>0)
    {
        cout<<" (Acabaste tu fondo en cubrir parte de esto...)"<<endl;
        datos[index_ImprevistosAcumulados]=totalImprevistos;
        totalImprevistos-=datos[index_FondoEmergencia];
        datos[index_FondoEmergencia]=0;
        datos[index_SaldoPesos]-=totalImprevistos;
    }
    else
    {
        datos[index_SaldoPesos]-=totalImprevistos;
        datos[index_ImprevistosAcumulados]=totalImprevistos;
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
    float dado2;
    int contadorDisminucion=0;
    datos[index_SaldoPesos]/=inflacion;
    datos[index_FondoEmergencia]/=inflacion;
    datos[index_GastosComida]*=inflacion;
    datos[index_GastosServicios]*=inflacion;
    datos[index_GastosTransporte]*=inflacion;
    datos[index_GastosAlquiler]*=inflacion;
    datos[index_GastosFijos]=datos[index_GastosAlquiler]+datos[index_GastosComida]+datos[index_GastosServicios]+datos[index_GastosTransporte];
    datos[index_InflacionAcumulada]*=1.07;
    datos[index_PrecioSP500]*=1.05;
    datos[index_PorcentajeSP500]=3;
    dado=rand()%100;
    if (dado<=9)
    {
        if (contadorDisminucion<3)
        {
            datos[index_PrecioDolar]*=0.97;
            datos[index_PorcentajeDolar]=-3;
            contadorDisminucion++;
        }
    }
    else if (dado<=29)
    {
        datos[index_PrecioDolar]*=1.09;
        datos[index_PorcentajeDolar]=9;
    }
    else if (dado<=59)
    {
        datos[index_PrecioDolar]*=1.10;
        datos[index_PorcentajeDolar]=10;
    }
    else
    {
        datos[index_PrecioDolar]*=1.11;
        datos[index_PorcentajeDolar]=11;
    }
    if(rondas!=6||rondas!=11)
    {
        dado=rand()%100;
        if (dado<=59)
        {
            dado2=rand()%21;
            float porcentaje=20+dado2;
            datos[index_PorcentajeBTC]=porcentaje;
            datos[index_PrecioBTC]*=(1+porcentaje/100.0);
        }
        else
        {
            dado2=rand()%16;
            float porcentaje=15+dado2;
            datos[index_PorcentajeBTC]=(-porcentaje);
            datos[index_PrecioBTC]*=(1-porcentaje/100.0);
        }
    }
}
