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

void escribirLentoArcoiris(string texto, int velocidad)
{
    int colores[] = {
        rlutil::RED,
        rlutil::YELLOW,
        rlutil::GREEN,
        rlutil::CYAN,
        rlutil::BLUE,
        rlutil::MAGENTA
    };
    int cantColores = sizeof(colores) / sizeof(colores[0]);

    bool saltar = false;

    for(size_t i=0; i<texto.length(); i++)
    {
        rlutil::setColor(colores[i % cantColores]);
        cout<<texto[i];
        cout.flush();

        if (!saltar)
        {
            if (kbhit())
            {
                saltar = true;
                rlutil::getkey(); // consumimos la tecla presionada
            }
            else
            {
                Sleep(velocidad);
            }
        }
    }

    rlutil::resetColor();
}

void escribirLento(string texto, int velocidad)
{
    bool saltar = false; // se activa cuando el usuario presiona una tecla

    for (size_t i = 0; i < texto.length(); i++)
    {
        cout << texto[i];
        cout.flush();

        if (!saltar)
        {
            if (kbhit()) // ¿hay una tecla esperando?
            {
                saltar = true;
                rlutil::getkey(); // la "consumimos" para que no quede pendiente
            }
            else
            {
                Sleep(velocidad);
            }
        }
        // si saltar == true, ya no se llama a Sleep -> se imprime todo rápido
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

void cartelIntro(int contadorPartida, string nombre[], int rondas)
{
    int velocidad=40;
    rlutil::hidecursor();
    escribirLento("=====================================", velocidad);
    cout<<endl;
    escribirLento("  MES ", velocidad);
    Sleep(400);
    cout<< "1/"<< rondas;
    Sleep(600);
    escribirLento("       Jugador: ", velocidad);
    Sleep(400);
    cout<<nombre[contadorPartida]<<endl;
    Sleep(600);
    escribirLento("=====================================", velocidad);
    cout<<endl;
    Sleep(400);

    escribirLento("La fecha es 16 de Enero.", 40); cout<<endl;
    Sleep(300);
    escribirLento("Luego de una larga búsqueda,", 40);Sleep(200);
    escribirLento(" lograste",40);cout<<endl;
    escribirLento("conseguir tu primer empleo y por fin", 40);cout<<endl;
    escribirLento("podrás independizarte.", 40);cout<<endl;
    Sleep(300);
    cout<<""<<endl;
    escribirLento("Aparte de tu sueldo de $500000, ", 40);Sleep(200);
    escribirLento("tus",40);cout<<endl;
    escribirLento("viejos te dieron $150000 para ayudarte",40);cout<<endl;
    escribirLento("en tus primeros meses en el mundo real.",40);cout<<endl;
    Sleep(300);
    cout<<""<<endl;
    escribirLento("Al irte de casa, ",40);Sleep(200);
    escribirLento("te despiden deseandote",40);cout<<endl;
    escribirLento("mucha suerte. ",40);Sleep(300);
    escribirLento("La necesitarás.",40);cout<<endl;
    Sleep(300);
    cout<<""<<endl;
    escribirLento("SALDO INICIAL: ",40);Sleep(300);
    cout<<"$650000";Sleep(600);cout<<endl;
    cout<<""<<endl;
    escribirLento("Presiona [Enter] para comenzar.",80);
    system("pause > nul");
    rlutil::showcursor();
}
