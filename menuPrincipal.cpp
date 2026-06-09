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

void menuPrincipal(string nombre[], double patrimonioReal[])
{
    int opcion=1;
    int contadorPartida=0;
    string entrada;
    char salida;
    while(opcion!=0)
    {
        system("cls");
        cout<<"====================================="<<endl;
        cout<<"            MENÚ PRINCIPAL           "<<endl;
        cout<<"====================================="<<endl;
        cout<<" 1. Crear nueva partida"<<endl;
        cout<<" 2. Highscore de la sesion"<<endl;
        cout<<" 3. Glosario financiero"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"====================================="<<endl;
        cout<<" Ingrese una opción: ";
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
            crearPartidaNueva(contadorPartida, nombre, patrimonioReal);
            contadorPartida++;
            break;
        case 2:
            if(contadorPartida==0)
            {
                cout<<"Todavía no se jugaron partidas."<<endl;
            }
            else
            {
                highscoreDeLaSesion(patrimonioReal, nombre, contadorPartida);
            }
            system("pause");
            break;
        case 3:
            glosarioFinanciero();
            break;

        case 0:
            escribirLento(" ¿Está seguro/a que quiere salir?", 40);
            cout<<endl;
            escribirLento(" ¿s/n?", 40);
            cout<<endl;
            cin>>salida;
            switch(salida)
            {
            case 's':
                /*escribirLento(" Saliendo del juego", 40);
                Sleep(100);
                escribirLento("...", 500);*/
                return;
                break;
            case 'n':
                /*escribirLento(" Regresando al menú", 40);
                Sleep(100);
                escribirLento("...", 500);*/
                opcion=1;
                break;
            }
            break;
        default:
            escribirLento(" Opción inválida", 40);
            escribirLento("...", 500);
            break;
        }
    }
}

void highscoreDeLaSesion(double patrimonioReal[], string nombre[], int contadorPartida)
{
    system("cls");
    int maximo=0;
    cout<<"=================================================="<<endl;
    cout<<"                    HIGH SCORE                    "<<endl;
    cout<<"=================================================="<<endl;
    cout<<" Partidas jugadas: "<<contadorPartida<<endl;
    for(int i=0; i<contadorPartida; i++)
    {
        cout<<" Jugador:"<<nombre[i]<<endl;
        cout<<" Patrimonio real de: $"<<patrimonioReal[i]<<endl;
    }

    for(int i=0; i<contadorPartida; i++)
    {
        if(i!=0)
        {
            if(patrimonioReal[i]>patrimonioReal[maximo])
            {
                maximo=i;
            }
        }
    }
    cout<<"--------------------------------------------------"<<endl;
    cout<<" Jugador estrella:"<<nombre[maximo]<<endl;
    cout<<" Patrimonio real de: $"<<patrimonioReal[maximo]<<endl;
    cout<<"=================================================="<<endl;
}

void glosarioFinanciero()
{
    int opcion;
    string entrada;
    bool mostrarMenu=1;
    while(true)
    {
        if(mostrarMenu)
        {
            rlutil::showcursor();
            system("cls");
            glosario();
            cout<<" 1. Costo de oportunidad"<<endl;
            cout<<" 2. Diversificación"<<endl;
            cout<<" 3. ETF (Exchange-Traded Fund)"<<endl;
            cout<<" 4. Fondo de Emergencia"<<endl;
            cout<<" 5. Indexación"<<endl;
            cout<<" 6. Inflación"<<endl;
            cout<<" 7. Liquidez"<<endl;
            cout<<" 8. Poder Adquisitivo"<<endl;
            cout<<" 9. Salario Real"<<endl;
            cout<<" 10. Salario Nominal"<<endl;
            cout<<" 11. Volatilidad"<<endl;
            cout<<" 0. Volver al menu"<<endl;
            cout<<""<<endl;
            cout<<" Ingrese una página: "<<endl;
            cout<<"=========================================================================";
            rlutil::locate(22,17);
            cin >> entrada;
            try
            {
                opcion = stoi(entrada);
            }
            catch (...)
            {
                opcion = -1;
            }


        }
        mostrarMenu=1;
        if(opcion==0)
        {
            return;
        }
        if(opcion>=1&&opcion<=11)
        {
            system("cls");
        }
        switch (opcion)
        {
        case 1:
            system("cls");
            glosario();
            cout<<"1. Costo de Oportunidad:"<<endl;
            cout<<"El valor de la mejor alternativa que se resigna al tomar una decisión."<<endl;
            cout<<"Guardar plata en pesos tiene el costo de oportunidad de no invertirla."<<endl;
            break;
        case 2:
            system("cls");
            glosario();
            cout<<"2. Diversificación"<<endl;
            cout<<"Estrategia de distribuir el dinero entre distintos instrumentos para"<<endl;
            cout<<"reducir el riesgo total. 'No poner todos los huevos en la misma canasta.'"<<endl;
            break;
        case 3:
            system("cls");
            glosario();
            cout<<"3. ETF (Exchange-Traded Fund)"<<endl;
            cout<<"Fondo de inversión que cotiza en bolsa"<<endl;
            cout<<"y replica el comportamiento de un índice, como el S&P 500."<<endl;
            cout<<"Permite invertir en muchas empresas a la vez con bajo costo."<<endl;
            break;
        case 4:
            system("cls");
            glosario();
            cout<<"4. Fondo de Emergencia"<<endl;
            cout<<"Reserva de dinero en efectivo o cuenta disponible para cubrir "<<endl;
            cout<<"gastos imprevistos sin necesidad de endeudarse ni vender inversiones."<<endl;
            break;
        case 5:
            system("cls");
            glosario();
            cout<<"5. Indexación"<<endl;
            cout<<"Mecanismo por el cual el valor de un contrato (como un alquiler)"<<endl;
            cout<<"se ajusta periódicamente según un índice de precios, "<<endl;
            cout<<"para mantener el valor real."<<endl;
            break;
        case 6:
            system("cls");
            glosario();
            cout<<"6. Inflación"<<endl;
            cout<<"Aumento generalizado y sostenido de los precios de bienes y servicios."<<endl;
            cout<<"Hace que el dinero valga menos con el tiempo."<<endl;
            break;
        case 7:
            system("cls");
            glosario();
            cout<<"7. Liquidez"<<endl;
            cout<<"Facilidad con la que un activo se puede convertir en dinero disponible."<<endl;
            cout<<"El efectivo es el activo más líquido; los inmuebles, el menos."<<endl;
            break;
        case 8:
            system("cls");
            glosario();
            cout<<"8. Poder Adquisitivo"<<endl;
            cout<<"Cantidad de bienes y servicios que se pueden comprar con"<<endl;
            cout<<"una suma de dinero. Disminuye cuando hay inflación."<<endl;
            break;
        case 9:
            system("cls");
            glosario();
            cout<<"9. Salario Real"<<endl;
            cout<<"El salario real mide cuánto se puede comprar con ese dinero."<<endl;
            cout<<"Si la inflación supera al aumento del sueldo, el salario real cae."<<endl;
            break;
        case 10:
            system("cls");
            glosario();
            cout<<"10. Salario Nominal"<<endl;
            cout<<"El salario nominal es el número en el recibo de sueldo.";
            break;
        case 11:
            system("cls");
            glosario();
            cout<<"11. Volatilidad"<<endl;
            cout<<"Medida de cuánto varía el precio de un activo. Un instrumento muy"<<endl;
            cout<<"volátil (como el Bitcoin) puede subir o bajar mucho en poco tiempo."<<endl;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
        if(opcion>0&&opcion<12)
        {
            cout<<endl<<"    [<] Pág. Anterior   [>] Pág. Siguiente   [Esc] Volver al menu"<<endl;
            cout<<"========================================================================="<<endl;
            rlutil::hidecursor(); // esconde el cursor.
            int tecla=rlutil::getkey();
            if(tecla==rlutil::KEY_LEFT)
            {
                opcion = (opcion > 1)?opcion-1:11;
                mostrarMenu=0;
            }
            else if(tecla==rlutil::KEY_RIGHT)
            {
                opcion=(opcion<11)?opcion+1:1;
                mostrarMenu=0;
            }
            else if(tecla==rlutil::KEY_ESCAPE)
            {
                mostrarMenu=1;
            }
            if(tecla != rlutil::KEY_ESCAPE && tecla != rlutil::KEY_LEFT && tecla != rlutil::KEY_RIGHT)
            {
                mostrarMenu = 0;
            }
        }
    }
}
