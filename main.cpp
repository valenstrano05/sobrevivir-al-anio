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

int main()
{
    int velocidad=50;
    srand(time(0));
    cout<<fixed<<setprecision(2);
    setlocale(LC_ALL,"");
    string nombre[5];
    double patrimonioReal[5];
    rlutil::locate(15, 0);
    escribirLentoArcoiris("=====================================", velocidad);
    cout<<endl;
    cout<<endl;
    escribirLentoArcoiris("          SOBREVIVIR AL AÑO          ", velocidad);
    cout<<endl;
    cout<<endl;
    escribirLentoArcoiris("=====================================", velocidad);
    cout<<endl;
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
    escribirLento("     Presione [Enter] para jugar", velocidad);
    system("pause > nul");
    menuPrincipal(nombre, patrimonioReal);

    return 0;
}
