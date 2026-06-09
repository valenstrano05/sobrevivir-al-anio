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
    srand(time(0));
    cout<<fixed<<setprecision(2);
    setlocale(LC_ALL,"");
    string nombre[5];
    double patrimonioReal[5];
    cout<<"====================================="<<endl;
    cout<<endl;
    cout<<"         SOBREVIVIR AL AÑO           "<<endl;
    cout<<endl;
    cout<<"====================================="<<endl;
    cout<<endl;
    cout<<" Presione enter para continuar...";
    system("pause > nul");
    menuPrincipal(nombre, patrimonioReal);

    return 0;
}
