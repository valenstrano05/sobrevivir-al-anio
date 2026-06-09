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

void escribirLento(string texto, int velocidad)
{
    for(size_t i=0; i<texto.length(); i++)
    {
        cout<<texto[i];
        cout.flush();
        Sleep(velocidad);
    }
}

void glosario()
{
    cout<<"========================================================================="<<endl;
    cout<<"                           GLOSARIO FINANCIERO                           "<<endl;
    cout<<"========================================================================="<<endl;
}

void cartelJugador(int contadorPartida, string nombre[], int rondas, int i)
{
    cout<<"====================================="<<endl;
    cout<<"  MES "<<i<<"/"<<rondas<<"       Jugador: "<<nombre[contadorPartida]<<endl;
    cout<<"====================================="<<endl;
}

