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

void crearPartidaNueva(int contadorPartida, string nombre[], double patrimonioReal[])
{
    system("cls");
    int rondas=0;
    string entrada;
    int velocidad=50;
    cout<<"====================================="<<endl;
    cout<<"            NUEVA PARTIDA            "<<endl;
    cout<<"====================================="<<endl;
    Sleep(100);
    escribirLento(" Sistema: ¿Cómo es su nombre?", velocidad);
    cout<<endl;
    Sleep(100);
    escribirLento(" ???: Yo me llamo... ", velocidad);
    cin>>nombre[contadorPartida];
    Sleep(100);
    escribirLento(" Sistema: ¡Que lindo nombre! Bienvenido/a a mí juego, ", velocidad);
    escribirLento(nombre[contadorPartida], velocidad);
    cout<<"."<<endl;
    Sleep(100);
    escribirLento(" Sistema: ¿Cuantos meses desea jugar? Solo se puede de 1 a 12 rondas.", velocidad);
    cout<<endl;
    Sleep(100);
    cout<<" ";
    escribirLento(nombre[contadorPartida], velocidad);
    escribirLento(": ", velocidad);
    while(rondas<1||rondas>12)
    {
        cin>>entrada;
        try
        {
            rondas = stoi(entrada);
        }
        catch (...)
        {
            rondas = -1;
        }
        if (rondas<1||rondas>12){
        escribirLento(" Sistema: La cantidad de rondas es inválida. Por favor, ingresela nuevamente.", velocidad);
        cout<<endl;
        Sleep(100);
        cout<<" ";
        escribirLento(nombre[contadorPartida], velocidad);
        escribirLento(": ", velocidad);
        }else
        {
            escribirLento(" Sistema: Excelente. Comencemos...", velocidad);
            cout<<endl;
            Sleep(500);
        }
    }

    jugarPartida(contadorPartida, nombre, rondas, patrimonioReal);
}

void jugarPartida(int contadorPartida, string nombre[], int rondas, double patrimonioReal[])
{
    double datosPartida[21];
    int contadorRojo=0;
    bool gameOver=0;
    int velocidad=50;
    double saldoInicial;
    cargarDatos(datosPartida);
    system("cls");
    Sleep(400);
    cartelIntro(contadorPartida, nombre, rondas);
    for(int i=1; i<=rondas; i++)
    {

        if (datosPartida[index_SaldoPesos]<0)
        {
            contadorRojo++;
        }
        else
        {
            contadorRojo=0;
        }
        int tecla;
        do
        {
            system("cls");
            cartelJugador(contadorPartida, nombre, rondas, i);
            cout<<"EVENTOS FIJOS: "<<endl;
            eventosFijos(i, datosPartida);
            cout<<"-------------------------------------"<<endl;
            cout<<"IMPREVISTOS: "<<endl;
            imprevistos(datosPartida);
            cout<<"-------------------------------------"<<endl;
            cout<<"TENENCIAS ACTUALES: "<<endl;
            cout<<"Fondo de emergencias: "<<datosPartida[index_FondoEmergencia]<<endl;
            cout<<"Dolares: $"<<datosPartida[index_Dolares]<<endl;
            cout<<"Bitcoin: $"<<datosPartida[index_BTC]<<endl;
            cout<<"SP500: "<<datosPartida[index_SP500]<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"Saldo inicial: $"<<saldoInicial<<endl;
            cout<< "Sueldo: $"<<datosPartida[index_Sueldo]<<endl;
            cout<< "Gastos fijos: $"<<datosPartida[index_GastosFijos]<<endl;
            cout<< "Saldo final: $"<<datosPartida[index_SaldoPesos]<<endl;
            cout<<"====================================="<<endl;
            cout<<"[G] Glosario"<<endl;
            cout<<"Presione cualquier tecla para continuar."<<endl;

            tecla = getch();

            if (tecla=='g' || tecla=='G')
            {
                glosarioFinanciero();
            }

        } while (tecla=='g' || tecla=='G');
        if (contadorRojo>2)
        {
            gameOver=1;
        }
        if (gameOver==1)
        {
            break;
        }
        if(datosPartida[index_SaldoPesos]>0)
        {
            if(i!=rondas)
            {
                system("cls");
                inversiones(contadorPartida, datosPartida, nombre, rondas, i);
            }
        }
        aumentoPorInflacion(datosPartida, rondas);
    }
    mostrarResumen(contadorPartida, nombre, datosPartida, gameOver, patrimonioReal);
}


void inversiones(int contadorPartida, double datos[], string nombre[], int rondas, int i)
{
    int opcion;
    string entrada;
    int aFondo;
    cartelJugador(contadorPartida, nombre, rondas, i);
    cout<<"como preferis distribuir tu saldo restante?"<<endl;
    cout<<"saldo: "<<datos[index_SaldoPesos]<<endl;
    cout<<""<<endl;
    cout<<"1. 0% inversion - 100% fondo emergencia"<<endl;
    cout<<"2. 25% inversion - 75% fondo emergencia"<<endl;
    cout<<"3. 50% inversion - 50% fondo emergencia"<<endl;
    cout<<"4. 75% inversion - 25% fondo emergencia"<<endl;
    cout<<"5. 100% inversion - 0% fondo emergencia"<<endl;
    cout<<"0. no invertir"<<endl;
    cout<<""<<endl;
    cout<<">> ";
    cin>>entrada;
    try
    {
        opcion = stoi(entrada);
    }
    catch (...)
    {
        opcion = -1;
    }
    switch (opcion)
    {
    case 1:
        aFondo=datos[index_SaldoPesos];
        datos[index_SaldoPesos]-=datos[index_SaldoPesos];
        datos[index_FondoEmergencia]+=aFondo;
        break;
    case 2:
        aFondo=(datos[index_SaldoPesos]*75)/100;
        datos[index_SaldoPesos]-=aFondo;
        datos[index_FondoEmergencia]+=aFondo;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i);
        break;
    case 3:
        aFondo=(datos[index_SaldoPesos]*50)/100;
        datos[index_SaldoPesos]-=aFondo;
        datos[index_FondoEmergencia]+=aFondo;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i);
        break;
    case 4:
        aFondo=(datos[index_SaldoPesos]*25)/100;
        datos[index_SaldoPesos]-=aFondo;
        datos[index_FondoEmergencia]+=aFondo;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i);
        break;
    case 5:
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i);
        break;
    case 0:

        break;

    case -1:
        system("cls");
        inversiones(contadorPartida, datos, nombre, rondas, i);
        break;

    default:
        break;
    }
}


void opcionesDeInversion(int contadorPartida, double datos[], string nombre[], int rondas, int i)
{
    int opcion=67;
    string entrada;

    while (opcion!=0)
    {
        system("cls");
        if(datos[index_SaldoPesos]<=0)
        {
            break;
        }
        cartelJugador(contadorPartida, nombre, rondas, i);
        cout<<"usted tiene $"<<datos[index_SaldoPesos]<<" para invertir"<<endl;
        cout<<"elegir opcion:"<<endl;
        cout<<"1. dolares"<<endl;
        cout<<"2. btc"<<endl;
        cout<<"3. S&P 500"<<endl;
        cout<<"0. salir"<<endl;
        cout<<">> ";
        cin>>entrada;
        try
        {
            opcion = stoi(entrada);
        }
        catch (...)
        {
            opcion = -1;
        }
        switch (opcion)
        {
        case 1:
            comprarInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
            break;
        case 2:
            comprarInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
            break;
        case 3:
            comprarInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
            break;
        default:
            break;
        }
    }
}


void comprarInstrumento(int contadorPartida, double datos[], int opcion, string nombre[], int rondas, int i)
{
    double plata=0;
    double instrumento=0;
    string nombre_instrumento[3]=
    {
        "USD",
        "BTC",
        "S&P 500"
    };
    while (datos[index_SaldoPesos]>0)
    {
        system ("cls");
        plata=0;
        rlutil::hidecursor();
        cartelJugador(contadorPartida, nombre, rondas, i);
        cout<<"cuanto quiere invertir en "<<nombre_instrumento[opcion-1]<<"?"<<endl;
        cout<<"(saldo: "<<datos[index_SaldoPesos]<<")"<<endl;
        cout<<""<<endl;
        cout<<nombre_instrumento[opcion-1]<<": $"<<datos[opcion+5]<<endl;
        cout<<">> "<<endl;
        cout<<"Presione [Enter] para escribir..."<<endl;
        cout<<"[Esc] volver"<<endl;
        int tecla;
        do
        {
            tecla = rlutil::getkey();
        }
        while (tecla != rlutil::KEY_ESCAPE && tecla != rlutil::KEY_ENTER);

        if (tecla == rlutil::KEY_ESCAPE)
        {
            rlutil::showcursor();
            break;
        }
        else if (tecla == rlutil::KEY_ENTER)
        {
            rlutil::locate(1, 9);
            cout<<"                                     "<<endl;
            rlutil::locate(1, 10);
            cout<<"                                     "<<endl;
            rlutil::locate(4, 8);
            rlutil::showcursor();
            cin >> plata;
        }
        if (plata<=0||plata>datos[index_SaldoPesos])
        {
            rlutil::hidecursor();
            cout<<"Valor no valido."<<endl;
            rlutil::msleep(2000);
            rlutil::showcursor();
        }
        else if (plata>0)
        {
            datos[index_SaldoPesos]-=plata;
            instrumento=(plata/datos[opcion+5]);
            datos[opcion+2]+=instrumento;
            rlutil::hidecursor();
            cout<<"se ha comprado $"<<instrumento<<" "<<nombre_instrumento[opcion-1]<<endl;
            rlutil::msleep(2000);
            rlutil::showcursor();
            break;
        }


    }
}


void mostrarResumen(int contadorPartida, string nombre[], double datos[], bool gameOver, double patrimonioReal[])
{
    int resultado;
    double patrimonio=datos[index_SaldoPesos]+datos[index_FondoEmergencia]+(datos[index_Dolares]*datos[index_PrecioDolar])+(datos[index_BTC]*datos[index_PrecioBTC])+(datos[index_SP500]*datos[index_PrecioSP500]);
    patrimonioReal[contadorPartida]=patrimonio/datos[index_InflacionAcumulada];

    system("cls");
    cout<<"====================================="<<endl;
    cout<<"           RESUMEN FINAL             "<<endl;
    cout<<"Patrimonio nominal: $"<<patrimonio<<endl;
    cout<<"Patrimonio real: $"<<patrimonioReal[contadorPartida]<<endl;
    cout<<""<<endl;

    if(gameOver==1)
    {
        resultado=3;
    }
    else if(patrimonioReal[contadorPartida]>650000*1.10)
    {
        resultado=0;
    }
    else if(patrimonioReal[contadorPartida]>=650000*0.90&&patrimonioReal[contadorPartida]<=650000*1.10)
    {
        resultado=1;
    }
    else
    {
        resultado=2;
    }
    switch (resultado)
    {
    case 0:
        cout<<"¡Felicidades, le ganaste a la inflacion!";
        break;
    case 1:
        cout<<"Le empataste a la inflacion. Podría haber sido peor...";
        break;
    case 2:
        cout<<"Que desastre... Te comió la inflación..."<<endl;
        break;
    case 3:
        cout<<"Todavía no estás listo para el mundo... Te volviste a lo de tus viejos."<<endl;
    default:
        break;
    }
    cout<<"====================================="<<endl;
    system("pause");
}
