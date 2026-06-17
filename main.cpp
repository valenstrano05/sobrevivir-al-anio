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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    rlutil::hidecursor();
    int velocidad=0;
    srand(time(0));
    cout<<fixed<<setprecision(2);
    string nombre[5];
    double patrimonioReal[5];
    cargarDatosPat(patrimonioReal);
    string titulo= R"(
  ____        _                    _       _             _      _    ____
 / ___|  ___ | |__  _ __ _____   _(_)_   _(_)_ __    ___| |    / \   _ __   ___
 \___ \ / _ \| '_ \| '__/ _ \ \ / / \ \ / / | '__|  / _ \ |   / _ \ | '_ \ / _ \
  ___) | (_) | |_) | | |  __/\ V /| |\ V /| | |    |  __/ |  / ___ \| | | | (_) |
 |____/ \___/|_.__/|_|  \___| \_/ |_| \_/ |_|_|     \___|_| /_/   \_\_| |_|\___/)";

    escribirLentoArcoiris(titulo, velocidad);
    system("cls");
    cartelParpadeante(titulo);
    menuPrincipal(nombre, patrimonioReal);

    return 0;
}

