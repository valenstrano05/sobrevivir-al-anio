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

using namespace std;

void crearPartidaNueva(int contadorPartida, string nombre[], double patrimonioReal[])
{
    system("cls");
    int rondas=0;
    string entrada;
    char salida;
    int velocidad=15;
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
    escribirLento(" Sistema: ¿Cuantos meses desea jugar? (de 1 a 12 meses, recomendado 12)", velocidad);
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
        if (rondas<1||rondas>12)
        {
            escribirLento(" Sistema: La cantidad de rondas es inválida. Por favor, ingresela nuevamente.", velocidad);
            cout<<endl;
            Sleep(100);
            cout<<" ";
            escribirLento(nombre[contadorPartida], velocidad);
            escribirLento(": ", velocidad);
        }
        else
        {
            escribirLento(" Sistema: Excelente.", velocidad);
            cout<<endl;
            bool verdadero=true;
            while(verdadero)
            {
                escribirLento(" Sistema: Desea ver un tutorial antes de comenzar? (s/n)", velocidad);
                cout<<endl;
                cout<<" ";
                escribirLento(nombre[contadorPartida], velocidad);
                escribirLento(": ", velocidad);
                cin>>salida;
                switch (salida)
                {
                case 's':
                    escribirLento(" Sistema: Muy bien. Será llevado al tutorial.", velocidad);
                    Sleep(300);
                    tutorial();
                    verdadero=false;
                    break;
                case 'n':
                    escribirLento(" Sistema: Muy bien. Comencemos...", velocidad);
                    verdadero=false;
                    break;

                default:
                    break;
                }
            }
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
    int deposito=0.0;
    cargarDatos(datosPartida);
    system("cls");
    Sleep(400);
    cartelIntro(contadorPartida, nombre, rondas);
    for(int i=1; i<=rondas; i++)
    {
        rlutil::hidecursor();
        if (datosPartida[index_SaldoPesos]<0)
        {
            contadorRojo++;
        }
        else
        {
            contadorRojo=0;
        }
        if(contadorRojo>2)
        {
            if(datosPartida[index_Dolares]>0||datosPartida[index_BTC]>0||datosPartida[index_SP500]>0)
            {
                datosPartida[index_SaldoPesos]+=datosPartida[index_Dolares]*datosPartida[index_PrecioDolar];
                datosPartida[index_SaldoPesos]+=datosPartida[index_BTC]*datosPartida[index_PrecioBTC];
                datosPartida[index_SaldoPesos]+=datosPartida[index_SP500]*datosPartida[index_PrecioSP500];
                datosPartida[index_Dolares]-=datosPartida[index_Dolares];
                datosPartida[index_BTC]-=datosPartida[index_BTC];
                datosPartida[index_SP500]-=datosPartida[index_SP500];


                if(datosPartida[index_SaldoPesos]>0)
                {
                    system("cls");
                    cartelJugador(contadorPartida, nombre, rondas, i);
                    cout<<" Se vendieron tus inversiones para "<<endl;
                    cout<<" mantenerte a flote... ≡(▔﹏▔)≡"<<endl;
                    cout<<" Tu saldo actual es: $"<<datosPartida[index_SaldoPesos]<<endl;
                    cout<<"=====================================";
                    system("pause > nul");
                    contadorRojo=0;
                }
            }
            else
            {
                gameOver=1;
            }
            if (gameOver==1)
            {
                break;
            }
        }
        int tecla;
        do
        {
            system("cls");
            cout<<" ======================================"<<endl;
            cout<<"|  MES "<<i<<"/"<<rondas<<endl;
            rlutil::locate(40, 2);
            cout<<"|"<<endl;
            cout<<"|  JUGADOR: "<<nombre[contadorPartida]<<endl;
            rlutil::locate(40, 3);
            cout<<"|"<<endl;
            cout<<" ======================================"<<endl;
            cout<<"             ~EVENTOS FIJOS~            "<<endl;
            eventosFijos(i, datosPartida);
            cout<<" -------------------------------------"<<endl;
            cout<<"              ~IMPREVISTOS~             "<<endl;
            imprevistos(datosPartida);
            cout<<" -------------------------------------"<<endl;
            cout<<"           ~TENENCIAS ACTUALES~          "<<endl;
            cout<<"  Fondo de emergencias: $"<<datosPartida[index_FondoEmergencia]<<endl;
            cout<<"  Dolares: $"<<datosPartida[index_Dolares]<<" ($"<<datosPartida[index_Dolares]*datosPartida[index_PrecioDolar]<<")"<<endl;
            cout<<"  Bitcoin: $"<<datosPartida[index_BTC]<<" ($"<<datosPartida[index_BTC]*datosPartida[index_PrecioBTC]<<")"<<endl;
            cout<<"  SP500: "<<datosPartida[index_SP500]<<" ($"<<datosPartida[index_SP500]*datosPartida[index_PrecioSP500]<<")"<<endl;
            cout<<" -------------------------------------"<<endl;
            cout<<"            ~RESUMEN DEL MES~            "<<endl;
            if (i==1)
            {
                cout<<"  Regalo de tus viejos: $150000"<<endl;
            }
            cout<<"  Sueldo: $"<<datosPartida[index_Sueldo]<<endl;
            cout<<"  Gastos totales: -$"<<datosPartida[index_GastosFijos]+datosPartida[index_ImprevistosAcumulados]+(deposito=(i == 1)?deposito+180000:0)<<endl;
            cout<<"  Saldo final: $"<<datosPartida[index_SaldoPesos]<<endl;
            cout<<" ====================================="<<endl;
            cout<<" [G] Glosario"<<endl;
            cout<<" Presione cualquier tecla para continuar."<<endl;
            tipsEducativos(i);
            tecla = getch();

            if (tecla=='g' || tecla=='G')
            {
                rlutil::showcursor();
                glosarioFinanciero();
            }

        }
        while (tecla=='g' || tecla=='G');
        if(datosPartida[index_SaldoPesos]>0)
        {
            if(i!=rondas)
            {
                if (datosPartida[index_BTC]==0&&datosPartida[index_Dolares]==0&&datosPartida[index_SP500]==0)
                {
                    bool vender=false;
                    rlutil::showcursor();
                    inversiones(contadorPartida, datosPartida, nombre, rondas, i, vender);
                }
                else
                {
                    system("cls");
                    rlutil::showcursor();
                    comprarVender(contadorPartida, datosPartida, nombre, rondas, i);
                }
            }
        }
        aumentoPorInflacion(datosPartida, rondas);
        rlutil::showcursor();
    }
    mostrarResumen(contadorPartida, nombre, datosPartida, gameOver, patrimonioReal);
    rlutil::showcursor();
}

void comprarVender(int contadorPartida, double datos[], std::string nombre[], int rondas, int i)
{
    bool vender=false;
    string entrada;
    int opcion;

    system("cls");
    cartelJugador(contadorPartida, nombre, rondas, i);
    cout<<" ¿Como desea continuar?"<<endl;
    cout<<" Saldo: "<<datos[index_SaldoPesos]<<endl;
    cout<<""<<endl;
    cout<<" Dolares: $"<<datos[index_Dolares]<<endl;
    cout<<" Bitcoin: $"<<datos[index_BTC]<<endl;
    cout<<" SP500: "<<datos[index_SP500]<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<" 1. Comprar"<<endl;
    cout<<" 2. Vender"<<endl;
    cout<<" 0. Salir"<<endl;
    cout<<" 3. Glosario"<<endl;
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
        inversiones(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 2:
        vender=true;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 3:
        glosarioFinanciero();
        comprarVender(contadorPartida, datos, nombre, rondas, i);
        break;
    default:
        break;
    }

}

void inversiones(int contadorPartida, double datos[], string nombre[], int rondas, int i, bool vender)
{
    int opcion;
    string entrada;
    int aFondo;
    system("cls");
    cartelJugador(contadorPartida, nombre, rondas, i);
    cout<<" ¿Como prefiere distribuir su saldo restante?"<<endl;
    cout<<" Saldo actual: $"<<datos[index_SaldoPesos]<<endl;
    cout<<""<<endl;
    cout<<" 1. 0% inversion - 100% fondo emergencia"<<endl;
    cout<<" 2. 25% inversion - 75% fondo emergencia"<<endl;
    cout<<" 3. 50% inversion - 50% fondo emergencia"<<endl;
    cout<<" 4. 75% inversion - 25% fondo emergencia"<<endl;
    cout<<" 5. 100% inversion - 0% fondo emergencia"<<endl;
    cout<<" 0. No invertir"<<endl;
    cout<<" 6. Glosario"<<endl;
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
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 3:
        aFondo=(datos[index_SaldoPesos]*50)/100;
        datos[index_SaldoPesos]-=aFondo;
        datos[index_FondoEmergencia]+=aFondo;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 4:
        aFondo=(datos[index_SaldoPesos]*25)/100;
        datos[index_SaldoPesos]-=aFondo;
        datos[index_FondoEmergencia]+=aFondo;
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 5:
        opcionesDeInversion(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 6:
        glosarioFinanciero();
        inversiones(contadorPartida, datos, nombre, rondas, i, vender);
        break;
    case 0:

        break;

    case -1:
        inversiones(contadorPartida, datos, nombre, rondas, i, vender);
        break;

    default:
        break;
    }
}


void opcionesDeInversion(int contadorPartida, double datos[], string nombre[], int rondas, int i, bool vender)
{
    int opcion=67;
    string entrada;

    while (opcion!=0)
    {
        system("cls");
        if (vender==false)
        {
            if(datos[index_SaldoPesos]<=1e-9)
            {
                break;
            }
        }
        else if (vender==true)
        {
            if(datos[index_BTC]<=1e-9&&datos[index_Dolares]<=1e-9&&datos[index_SP500]<=1e-9)
            {
                break;
            }
        }
        cartelJugador(contadorPartida, nombre, rondas, i);

        cout<<" Saldo actual: $"<<datos[index_SaldoPesos]<<endl;
        cout<<" Elegir opción:"<<endl;
        cout<<" 1. Dolares"<<endl;
        cout<<" 2. BTC"<<endl;
        cout<<" 3. S&P 500"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<" 4. Glosario"<<endl;
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
        if (vender==true)
        {
            switch (opcion)
            {
            case 1:
                venderInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
                break;
            case 2:
                venderInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
                break;
            case 3:
                venderInstrumento(contadorPartida, datos, opcion, nombre, rondas, i);
                break;
            case 4:
                glosarioFinanciero();
                break;
            default:
                break;
            }
        }
        else if (vender==false)
        {
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
            case 4:
                glosarioFinanciero();
                break;
            default:
                break;
            }
        }
    }
}


void comprarInstrumento(int contadorPartida, double datos[], int opcion, string nombre[], int rondas, int i)
{
    bool flag=0;
    double plata=0;
    double instrumento=0;
    string entrada;
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
        rlutil::locate(0, 0);
        cartelJugador(contadorPartida, nombre, rondas, i);
        cout<<" ¿Cuánto quiere invertir en "<<nombre_instrumento[opcion-1]<<"?"<<endl;
        cout<<" (Saldo actual: "<<datos[index_SaldoPesos]<<")"<<endl;
        cout<<""<<endl;
        cout<<" "<<nombre_instrumento[opcion-1]<<": $"<<datos[opcion+5]<<endl;
        cout<<" >> "<<endl;
        cout<<" Presione [Enter] para escribir..."<<endl;
        cout<<" [Esc] volver"<<endl;
        cout<<" [G] Glosario"<<endl;
        cartelesInstrumentos(opcion);
        int tecla;
        do
        {
            tecla = rlutil::getkey();
        }
        while (tecla != rlutil::KEY_ESCAPE && tecla != rlutil::KEY_ENTER && tecla != 103);

        if (tecla == rlutil::KEY_ESCAPE)
        {
            rlutil::showcursor();
            break;
        }
        else if (tecla == rlutil::KEY_ENTER)
        {
            flag=false;
            rlutil::locate(1, 10);
            cout<<"                                     "<<endl;
            rlutil::locate(1, 11);
            cout<<"                                     "<<endl;
            rlutil::locate(1, 12);
            cout<<"                                     "<<endl;
            rlutil::locate(4, 9);
            rlutil::showcursor();
            cin >> entrada;
            try
            {
                plata = stoi(entrada);
            }
            catch (...)
            {
                plata = -1;
            }
        }
        else if (tecla == 103)
        {
            flag=true;
            glosarioFinanciero();
        }
        if (flag==false)
        {
            if (plata<=0||plata>datos[index_SaldoPesos] + 1e-9)
            {
                rlutil::hidecursor();
                cout<<" Valor no válido."<<endl;
                cout<<" (Toque alguna tecla para continuar...)"<<endl;
                system("pause > nul");
                rlutil::showcursor();
            }
            else if (plata>0)
            {
                datos[index_SaldoPesos]-=plata;
                instrumento=(plata/datos[opcion+5]);
                datos[opcion+2]+=instrumento;
                rlutil::hidecursor();
                cout<<" Se ha comprado: $"<<instrumento<<" "<<nombre_instrumento[opcion-1]<<endl;
                cout<<" (Toque alguna tecla para continuar...)"<<endl;
                system("pause > nul");
                rlutil::showcursor();
                break;
            }
        }



    }
}
void venderInstrumento(int contadorPartida, double datos[], int opcion, string nombre[], int rondas, int i)
{
    bool flag=0;
    double plata=0;
    string entrada;
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
        rlutil::locate(0, 0);
        cartelJugador(contadorPartida, nombre, rondas, i);
        cout<<" ¿Cuánto "<<nombre_instrumento[opcion-1]<<" desea vender?"<<endl;
        cout<<" ("<<nombre_instrumento[opcion-1]<<": "<<datos[opcion+2]<<")"<<endl;
        cout<<""<<endl;
        cout<<" 1 "<<nombre_instrumento[opcion-1]<<": $"<<datos[opcion+5]<<endl;
        cout<<" >> "<<endl;
        cout<<" Presione [Enter] para escribir..."<<endl;
        cout<<" [Esc] volver"<<endl;
        cout<<" [G] Glosario"<<endl;
        cartelesInstrumentos(opcion);
        int tecla;
        do
        {
            tecla = rlutil::getkey();
        }
        while (tecla != rlutil::KEY_ESCAPE && tecla != rlutil::KEY_ENTER && tecla != 103);

        if (tecla == rlutil::KEY_ESCAPE)
        {
            rlutil::showcursor();
            break;
        }
        else if (tecla == rlutil::KEY_ENTER)
        {
            flag=false;
            rlutil::locate(1, 10);
            cout<<"                                     "<<endl;
            rlutil::locate(1, 11);
            cout<<"                                     "<<endl;
            rlutil::locate(1, 12);
            cout<<"                                     "<<endl;
            rlutil::locate(4, 9);
            rlutil::showcursor();
            cin >> entrada;
            try
            {
                instrumento = stoi(entrada);
            }
            catch (...)
            {
                instrumento = -1;
            }
        }
        else if (tecla == 103)
        {
            flag=true;
            glosarioFinanciero();
        }
        if (flag==false)
        {
            if (instrumento<=0||instrumento>datos[opcion+2] + 1e-9 )
            {
                rlutil::hidecursor();
                cout<<" Valor no valido."<<endl;
                cout<<" (Toque alguna tecla para continuar...)"<<endl;
                system("pause > nul");
                rlutil::showcursor();
            }
            else if (instrumento>0)
            {
                datos[opcion+2]-=instrumento;
                plata=(instrumento*datos[opcion+5]);
                datos[index_SaldoPesos]+=plata;
                rlutil::hidecursor();
                cout<<" Ha vendido: $"<<instrumento<<" "<<nombre_instrumento[opcion-1]<<"(+$"<<plata<<")"<<endl;
                cout<<" (Toque alguna tecla para continuar...)"<<endl;
                system("pause > nul");
                rlutil::showcursor();
                break;
            }
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
    cout<<" Patrimonio nominal: $"<<patrimonio<<endl;
    cout<<" Patrimonio real: $"<<patrimonioReal[contadorPartida]<<endl;
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
        cout<<" ¡Felicidades, le ganaste a la inflacion! ╰(*°v°*)╯ "<<endl;
        break;
    case 1:
        cout<<" Le empataste a la inflacion. Podría"<<endl;
        cout<<" haber sido peor... (- ~ -)"<<endl;
        break;
    case 2:
        cout<<" Que desastre... Te comió la inflación (T - T) "<<endl;
        break;
    case 3:
        cout<<" Todavía no estás listo para el mundo..."<<endl;
        cout<<" Te volviste a lo de tus viejos. (u - u)"<<endl;
    default:
        break;
    }
    cout<<"====================================="<<endl;
    cout<< "Presione una tecla para continuar..."<<endl;
    system("pause > nul");
}
